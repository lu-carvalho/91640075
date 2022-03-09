import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

from datetime import datetime, timezone

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")

# create table and index in order to keep track of each user stock orders
db.execute("CREATE TABLE IF NOT EXISTS orders (id INTEGER, user_id NUMERIC NOT NULL, symbol TEXT NOT NULL, shares NUMERIC NOT NULL, price NUMERIC NOT NULL, timestamp TEXT, PRIMARY KEY(id), FOREIGN KEY(user_id) REFERENCES users(id))")

db.execute("CREATE INDEX IF NOT EXISTS orders_by_user_id_index ON orders (user_id)")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    owns = own_shares()
    total = 0
    for symbol, shares in owns.items():
        result = lookup(symbol)
        name, price = result["name"], result["price"]
        stock_value = shares * price
        total += stock_value
        owns[symbol] = (name, shares, usd(price), usd(stock_value))
    cash = db.execute("SELECT cash FROM users WHERE id = ? ", session["user_id"])[0]['cash']
    total += cash
    return render_template("index.html", owns=owns, cash= usd(cash), total = usd(total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("you must input a symbol")

        elif lookup(request.form.get("symbol")) == None:
            return apology("That stock doesn't exist")

        
        elif (request.form.get("shares")) < 0:
            return apology("please enter a valid amount of shares")

        result = lookup(request.form.get("symbol"))

        price = result[price]
        name = result[name]
        symbol = result[symbol]
        shares = request.form.get("shares")
        user_id = session["user_id"]
        cash = int(db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"])
        new_cash = cash - price * shares

        if new_cash < 0:
            return apology("You gonna need more cash for that")

        else:
            #add the stock purchase to the user's porfolio and update cash amount
            db.execute("INSERT INTO orders (user_id, symbol, shares, price, timestamp) VALUES (?, ?, ?, ?, ?", user_id, symbol, shares, price, when())

            db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

            return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    rows = db.execute("SELECT symbol, shares, price, timestamp FROM orders WHERE user_id = ?", session["user_id"])
    return render_template("history.html", rows = rows)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":

        if lookup(request.form.get("symbol")) == None:
            return apology("That stock doesn't exist")

        else:
            symbol = request.form.get("symbol")
            result = lookup(symbol)
        return render_template("quoted.html", name = result["name"], price = usd(result["price"]), symbol = result["symbol"])

    else:
        return render_template("quote.html")


@app.route("/quote/quoted")
def quoted():
    return render_template("quoted.html")

@app.route("/register", methods=["GET", "POST"])
def register():

    username = request.form.get("username")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")

    if request.method == "POST":

        # once that form is submited, check for errors.
        # do not allow blank username
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # make sure the username is not already taken
        elif len(db.execute("SELECT username FROM users WHERE username = ?", username)) > 0:
            return apology("that username is already taken")

        # do nor allow blank password
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # password and confirmation match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("password and confirmation don't match", 400)

        # If there are no errors, insert the new user into the users table and log him in

        else:
            hash = generate_password_hash(password)

            #add all that information into my data base
            db.execute("INSERT INTO users (username, hash) VALUES (?,?)", username, hash)

            # Remember which user has logged in

            rows = db.execute("SELECT * FROM users WHERE username = ?", username)
            session["user_id"] = rows[0]["id"]

            return redirect("/")

    else:
        #Display a form so that they can register for a new account
        return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    owns = own_shares()
    if request.method == "GET":
        return render_template("sell.html", owns = owns.keys())

    symbol = request.form.get("symbol")
    shares = int(request.form.get("shares"))

    #see if there are shares to sell
    if owns[symbol] < shares:
        return render_template("sell.html", invalid=True, symbol=symbol, owns = owns.keys())

    # sell, same procediment as buy, but like, in reverse
    result = lookup(symbol)
    user_id = session["user_id"]
    cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]['cash']
    price = result["price"]
    new_cash = cash + price * shares
    db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

    # Log the transaction into orders
    db.execute("INSERT INTO orders (user_id, symbol, shares, price, timestamp) VALUES (?, ?, ?, ?, ?)", user_id, symbol, -shares, price, when())

    return redirect("/")

def own_shares():
    """Helper function: Which stocks the user owns, and numbers of shares owned. Return: dictionary {symbol: qty}"""
    user_id = session["user_id"]
    owns = {}
    query = db.execute("SELECT symbol, shares FROM orders WHERE user_id = ?", user_id)
    for q in query:
        symbol, shares = q["symbol"], q["shares"]
        owns[symbol] = owns.setdefault(symbol, 0) + shares
    # filter zero-share stocks
    owns = {k: v for k, v in owns.items() if v != 0}
    return owns

def when():
    now_utc = datetime.now(timezone.utc)
    return str(now_utc.date()) + ' @time ' + now_utc.time().strftime("%H:%M:%S")