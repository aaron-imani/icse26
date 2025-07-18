import sys

input = sys.stdin.read().strip()
strs = input.split()
nums = []

for s in strs:
    if s == '+':
        nums[-2] = nums[-2] + nums[-1]
        nums.pop()
    elif s == '-':
        nums[-2] = nums[-2] - nums[-1]
        nums.pop()
    elif s == '*':
        nums[-2] = nums[-2] * nums[-1]
        nums.pop()
    else:
        nums.append(int(s))

print(nums[0])
# End of Code
