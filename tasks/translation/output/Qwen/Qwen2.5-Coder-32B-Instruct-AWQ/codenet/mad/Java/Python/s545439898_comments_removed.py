count = int(input())
giving_numbers = [int(input()) for _ in range(count)]

print(" ".join(map(str, giving_numbers[::-1])))
# End of Code
