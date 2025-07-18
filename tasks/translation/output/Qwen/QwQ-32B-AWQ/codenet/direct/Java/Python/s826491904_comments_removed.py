n = int(input())
max_val = min_val = int(input())
for _ in range(n-1):
    num = int(input())
    max_val = max(max_val, num)
    min_val = min(min_val, num)
print(max_val - min_val)
# End of Code
