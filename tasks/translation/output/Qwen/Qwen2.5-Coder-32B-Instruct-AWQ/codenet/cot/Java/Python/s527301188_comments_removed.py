import sys

input = sys.stdin.read().strip()
strs = input.split(" ")
nums = []
top = 0
for s in strs:
    if s == '+':
        top -= 1
        nums[top-1] = nums[top - 1] + nums[top]
    elif s == '-':
        top -= 1
        nums[top-1] = nums[top - 1] - nums[top]
    elif s == '*':
        top -= 1
        nums[top-1] = nums[top - 1] * nums[top]
    else:
        nums.append(int(s))
        top += 1

print(nums[0])
# End of Code
