import sys

count = int(input())
giving_numbers = []

for _ in range(count):
    giving_numbers.append(int(input()))

for i in range(count - 1, -1, -1):
    print(giving_numbers[i], end=" " if i > 0 else "\n")

# End of Code
