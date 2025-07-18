Both translations are correct. Here is one of the correct translations:


# Using input() for simplicity, as it's more common in Python scripts
count = int(input())
giving_numbers = [int(input()) for _ in range(count)]

# Reversing Numbers
for i in range(count - 1, -1, -1):
    print(giving_numbers[i], end="")
    if i > 0:
        print(" ", end="")

print()
# End of Code
