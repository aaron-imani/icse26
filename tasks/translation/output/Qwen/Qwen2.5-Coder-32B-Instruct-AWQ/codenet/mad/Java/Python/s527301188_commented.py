import sys

strs = sys.stdin.readline().strip().split()
nums = [0] * len(strs)
top = 0

for s in strs:
    if s == '+':
        top -= 1
        nums[top - 1] = nums[top - 1] + nums[top]
    elif s == '-':
        top -= 1
        nums[top - 1] = nums[top - 1] - nums[top]
    elif s == '*':
        top -= 1
        nums[top - 1] = nums[top - 1] * nums[top]
    else:
        nums[top] = int(s)
        top += 1

print(nums[0])
# End of Code
