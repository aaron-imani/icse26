strs = input().split(' ')
nums = [0] * len(strs)
top = 0
for i in range(len(strs)):
    if strs[i][0] == '+':
        top -= 1
        nums[top-1] = nums[top-1] + nums[top]
    elif strs[i][0] == '-':
        top -= 1
        nums[top-1] = nums[top-1] - nums[top]
    elif strs[i][0] == '*':
        top -= 1
        nums[top-1] = nums[top-1] * nums[top]
    else:
        nums[top] = int(strs[i])
        top += 1

print(nums[0])  # End of Code
