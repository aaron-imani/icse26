import sys

input_str = input().split()
nums = [0] * len(input_str)
top = 0

for token in input_str:
    if token[0] == '+':
        top -= 1
        nums[top] = nums[top] + nums[top + 1]
    elif token[0] == '-':
        top -= 1
        nums[top] = nums[top] - nums[top + 1]
    elif token[0] == '*':
        top -= 1
        nums[top] = nums[top] * nums[top + 1]
    else:
        nums[top] = int(token)
        top += 1

print(nums[0])  # End of Code
