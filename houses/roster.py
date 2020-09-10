from sys import argv, exit
import cs50


if len(argv) != 2:
    print("Usage: python roster.py house")
    exit(1)
db = cs50.SQL("sqlite:///students.db")
listStudents = db.execute("SELECT DISTINCT first, middle, last, birth, house FROM students WHERE house = ? ORDER BY last", argv[1])

for student in listStudents:
    if student['first'] != None:
        print(student['first'], end = ' ')
    if student['middle'] != None:
        print(student['middle'], end = ' ')
    if student['last'] != None:
        print(student['last'], end = ', ')
    print("born", student['birth'])


