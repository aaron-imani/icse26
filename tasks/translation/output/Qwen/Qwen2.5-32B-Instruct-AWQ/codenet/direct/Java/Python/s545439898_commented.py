import sys

count = int(input())
giving_numbers = []

# Read Numbers
for _ in range(count):
    giving_numbers.append(int(input()))

# Reversing Numbers
for i in range(count - 1, -1, -1):
    print(giving_numbers[i], end=" " if i > 0 else "")

print()
# End of Code
