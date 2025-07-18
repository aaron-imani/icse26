import sys

input = sys.stdin.read
data = input().split()

count = int(data[0])
giving_numbers = [int(data[i+1]) for i in range(count)]

# Reversing Numbers
for i in range(count-1, -1, -1):
    print(giving_numbers[i], end=" " if i != 0 else "")

print()
# End of Code
