import sys

def main():
    strs = sys.stdin.read().split()
    nums = [0] * len(strs)
    top = 0
    for s in strs:
        if len(s) == 1 and s[0] in {'+', '-', '*'}:
            top -= 1
            a = nums[top-1]
            b = nums[top]
            if s == '+':
                nums[top-1] = a + b
            elif s == '-':
                nums[top-1] = a - b
            elif s == '*':
                nums[top-1] = a * b
        else:
            nums[top] = int(s)
            top += 1
    print(nums[0])

if __name__ == "__main__":
    main() # End of Code
