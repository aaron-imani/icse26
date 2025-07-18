N = int(input())
arr = list(map(int, input().split()))
max_val = 0
output = 0
for num in arr:
    if num >= max_val:
        max_val = num
        output += 1
print(output)
# End of Code
