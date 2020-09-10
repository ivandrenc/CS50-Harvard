from sys import argv, exit
import csv
import cs50


def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)
    database = open(argv[1], "r")
    readerDatabase = csv.DictReader(database)
    genTypeList = readerDatabase.fieldnames
    textFile = open(argv[2], "r")
    sequence = textFile.read()
        #creation of a dictionary with gentypes and empty lists
    record = {name: [] for name in genTypeList}
    #eliminate first element containing name to make it easier work with
    #the genes types
    record.pop('name')
    counter = 0
        #i------8
        #iteration through each gentype
    for i in range(1, len(genTypeList)):
        for j in range(len(sequence)):
            counter = 0
            #string slicing
            gen = sequence[j:j + len(genTypeList[i])]
            if gen == genTypeList[i]:
                counter = counter + 1
                record[genTypeList[i]].append(counter)
                while (True):
                    j = j + len(genTypeList[i])
                    #previous slice
                    tmp = gen
                    #posterior slice
                    gen = sequence[j:j + len(genTypeList[i])]
                    if tmp != gen:
                        break
                    else:
                        counter = counter + 1
                        record[genTypeList[i]].append(counter)
            else:
                continue



    for names in record:
        if len(record[names]) != 0:
            maxx = max(record[names])
            record[names] = maxx
        else:
            print("No match")
            return
    #variable match will count how many times the genes matches with the records
    #of the sequence
    match = 0
    for linea in readerDatabase:
        #iteration over each type of gen AGATC, AATG ...
        match = 0
        for iteration in range(1, len(genTypeList)):
            a = int(linea[genTypeList[iteration]])
            b = int(record[genTypeList[iteration]])
            if a == b:
                match = match + 1
                if match == len(genTypeList) - 1:
                    print(linea["name"])
                    return
                else:
                    continue
    #assuming we dont have more than 2 matches between two
    #persons
    if match <= 2:
        print("No match")
        return

    textFile.close()
    database.close()


main()

