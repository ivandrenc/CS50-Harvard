from cs50 import get_float
import math

change = round(get_float("Change owed: ") * 100)

while change <= 0:
    change = round(get_float("Change owed: ") * 100)

rest = change
coins = 0

if change >= 25:
    rest = rest - 25
    coins = coins + 1
    while rest >= 25:
        rest = rest - 25
        coins = coins + 1
if rest >= 10:
    rest = rest - 10
    coins = coins + 1
    while rest >= 10:
        rest = rest - 10
        coins = coins + 1
if rest >= 5:
    rest = rest - 5
    coins = coins + 1
    while rest >= 5:
        rest = rest - 5
        coins = coins + 1
if rest >= 1:
    rest = rest - 1
    coins = coins + 1
    while rest >= 1:
        rest = rest - 1
        coins = coins + 1
print(coins)