count = int(input())
giving_numbers = [int(input()) for _ in range(count)]

# Reversing Numbers
for i in range(count - 1, -1, -1):
    print(giving_numbers[i], end=' ' if i > 0 else '')

print()
# End of Code
