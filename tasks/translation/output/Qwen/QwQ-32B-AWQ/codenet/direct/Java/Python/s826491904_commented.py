n = int(input())
max_v = min_v = int(input())
for _ in range(n-1):
    num = int(input())
    max_v = max(max_v, num)
    min_v = min(min_v, num)
print(max_v - min_v)  # End of Code
