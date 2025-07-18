import sys

def main():
    tokens = sys.stdin.readline().split()
    n = len(tokens)
    nums = [0] * n
    top = 0
    for token in tokens:
        c = token[0]
        if c in {'+', '-', '*'}:
            top -= 1
            a = nums[top - 1]
            b = nums[top]
            if c == '+':
                nums[top - 1] = a + b
            elif c == '-':
                nums[top - 1]: nums[top - 1] = a - b
            elif c == '*':
                nums[top - 1] = a * b
        else:
            nums[top] = int(token)
            top += 1
    print(nums[top-1])

if __name__ == "__main__":
    main()
# End of Code
