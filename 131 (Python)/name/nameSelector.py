import random

in_file = open('nameSelector-in.txt', 'r')

roster = []

for line in in_file:

    values = line.split()

    first = values[0]
    last  = values[1]

    roster.append(last + ", " + first)

in_file.close()

roster.sort()

for name in roster:

    print(name)