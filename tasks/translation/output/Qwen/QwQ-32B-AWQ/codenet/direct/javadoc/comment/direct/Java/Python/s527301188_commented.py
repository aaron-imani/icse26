import sys

def main():
    strs = sys.stdin.readline().split()
    n = len(strs)
    nums = [0] * n
    top = 0
    for s in strs:
        if s in ['+', '-', '*']:
            top -= 1
            a = nums[top-1]
            b = nums[top]
            if s == '+':
                nums[top-1] = a + b
            elif s == '-':
                nums[top-1] = a - b
            else:
                nums[top-1] = a * b
        else:
            nums[top] = int(s)
            top += 1
    print(nums[0])

if __name__ == "__main__":
    main()
# End of Code
