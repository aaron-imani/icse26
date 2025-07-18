n = int(input())
nums = list(map(int, input().split()))
max_val = nums[0]
min_val = nums[0]
for num in nums[1:]:
    if num > max_val:
        max_val = num
    if num < min_val:
        min_val = num
print(max_val - min_val)
# End of Code
