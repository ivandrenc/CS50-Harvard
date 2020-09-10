from cs50 import get_int
numero = get_int("Height: ")
while numero <= 0 or numero >8:
    numero = get_int("Height: ")
contador = 0
for i in range(numero):
    contador = contador + 1
    for j in range(numero - contador):
        print(" ", end="")
    for a in range(contador):
        print("#", end="")
    for b in range(2):
        print(" ", end="")
    for k in range(contador):
        print("#", end="")
    print()
        
        