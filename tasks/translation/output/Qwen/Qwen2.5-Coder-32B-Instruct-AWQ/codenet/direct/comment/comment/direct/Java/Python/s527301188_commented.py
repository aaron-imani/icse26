import sys

def main():
    import sys
    input = sys.stdin.read().strip()
    strs = input.split()
    nums = []
    for s in strs:
        if s == '+':
            b = nums.pop()
            a = nums.pop()
            nums.append(a + b)
        elif s == '-':
            b = nums.pop()
            a = nums.pop()
            nums.append(a - b)
        elif s == '*':
            b = nums.pop()
            a = nums.pop()
            nums.append(a * b)
        else:
            nums.append(int(s))
    print(nums[0])

if __name__ == "__main__":
    main()
# End of Code
