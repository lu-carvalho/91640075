import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

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
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        if not request.get.form("symbol"):
            return apology("you must input a symbol", 403)

        if request.get.form("symbol")

        return apology("TODO")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


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

        if lookup(request.form.get("symbol")) == "None":
            return apology("That stock doesn't exist", 403)

        else:
            return redirect("/quote/quoted")

    else:
        return render_template("quote.html")

@app.route("/quote/quoted")
def quoted():
    #gotta find out how to display the quoted. embedding within it one or more values from lookup
    return render_template("quoted.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        #Once that form is submited, check for errors.

        # do not allow blank username
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # do nor allow blank password
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # password and confirmation match
        elif not request.form.get("password") == request.form.get("confirm_password"):
            return apology("password and confirmation don't match", 403)

        # make sure the username is not already taken

        elif len(db.execute("SELECT ? FROM users", username)) != 0:
            return apology("that username is already taken")

        # If there are no errors, insert the new user into the users table and log him in
        username = request.form.get("username")
        password = request.form.get("password")
        # i don't think this is necessary confirm_password = request.form.get("confirm_password")

        hash = generate_password_hash(password)

        #add all that information into my data base
        db.execute("INSERT INTO users (username, hash) VALUES (?,?)", username, hash)

        # TODO: Remember which user has logged in

        return redirect("/")

    else:
        #Display a form so that they can register for a new account
        return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
