import sys

def main():
    tokens = sys.stdin.readline().split()
    n = len(tokens)
    nums = [0] * n
    top = 0
    for token in tokens:
        if token in ['+', '-', '*']:
            top -= 1
            a = nums[top]
            b = nums[top + 1]
            # Wait, correction: a is at top-1, b at top after decrement
            # The mistake was here earlier, correcting now:
            a = nums[top - 1]
            b = nums[top]
            if token == '+':
                nums[top - 1] = a + b
            elif token == '-':
                nums[top - 1] = a - b
            elif token == '*':
                nums[top - 1] = a * b
        else:
            nums[top] = int(token)
            top += 1
    print(nums[0])

if __name__ == "__main__":
    main()

# Wait, the previous code has a mistake in variable names. Let me correct it again:

import sys

def main():
    tokens = sys.stdin.readline().split()
    n = len(tokens)
    nums = [0] * n
    top = 0
    for token in tokens:
        if token in ['+', '-', '*']:
            top -= 1
            a = nums[top - 1]
            b = nums[top]
            if token == '+':
                nums[top - 1] = a + b
            elif token == '-':
                nums[top - 1] = a - b
            elif token == '*':
                nums[top - 1] = a * b
        else:
            nums[top] = int(token)
            top += 1
    print(nums[0])

if __name__ == "__main__":
    main()
# End of Code
