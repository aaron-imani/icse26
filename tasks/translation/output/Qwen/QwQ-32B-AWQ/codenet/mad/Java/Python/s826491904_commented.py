n = int(input())
first = int(input())
max_val, min_val = first, first
for _ in range(n-1):
    num = int(input())
    max_val = num if num > max_val else max_val
    min_val = num if num < min_val else min_val
print(max_val - min_val)  # End of Code
