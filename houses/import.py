from sys import argv, exit
import csv
import cs50

if len(argv) != 2:
        print("Usage: python import.py data.csv")
        exit(1)
#connection with the database
db = cs50.SQL("sqlite:///students.db")

#reads the csv file
with open(argv[1], "r") as file:
    reader = csv.DictReader(file)

# iteration through each student
    for row in reader:
        #depending the lenght of the list assign the names of the students
        listNames = row['name'].split()
        if len(listNames) == 1:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?)", listNames[0], row['house'], row['birth'])
        elif len(listNames) == 2:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", listNames[0], None, listNames[1], row['house'], row['birth'])
        else:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", listNames[0], listNames[1], listNames[2], row['house'], row['birth'])



