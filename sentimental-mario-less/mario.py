from cs50 import get_int
numero = get_int("height: ")
esp = 0
for i in range(numero):
    esp = esp + 1
    for j in range(numero - esp):
        print(" ", end="")
    for a in range(esp):
        print("#", end="")
    print()