import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) =! 3:
        print("Usage: python dna.py file.csv file.txt")
        sys.exit(1)

    # TODO: Read DNA sequence file into a variable
    dna = open(sys.argv[2], "r").read()

    # TODO: Read database file into a variable & Find longest match of each STR in DNA sequence
    database = []
    with open(sys.argv[1]),"r") as csvfile:
        reader = csv.DictReader(csvfile)
        strs_tested = reader.fieldnames[1:]
        strs_count = {}

        for STR in strs_tested:
            index = 0
            longest_sequence = 0
            current_sequence = 0

            while index < len(dna):
                current_str = dna[index: index + len(STR)]
                if current_str == STR:
                    current_sequence += 1
                    index += len(STR)
                else:
                    if current_sequence > longest_sequence:
                        longest_sequence = current_sequence
                    current_sequence = 0
                    index += 1

            strs_count[STR] = longest_sequence

    # TODO: Check database for matching profiles
        for person in reader:
            name = person['name']
            is_found = True

            for STR in strs_tested:
                if int(person[STR]) != strs_count[STR]:
                    is_found = False
                    break
            if is_found:
                print(name)
                sys.exit(0)
        print("No Match")
        
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
