N = int(input())
nums = list(map(int, input().split()))
max_val = 0
output = 0
for num in nums:
    if num >= max_val:
        output += 1
        max_val = num
print(output)
# End of Code
