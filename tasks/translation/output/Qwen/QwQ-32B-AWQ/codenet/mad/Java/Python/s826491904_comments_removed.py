n = int(input())
max_val = int(input())
min_val = max_val
for _ in range(n-1):
    current = int(input())
    if current > max_val:
        max_val = current
    if current < min_val:
        min_val = current
print(max_val - min_val)
# End of Code
