def main():
    strs = input().split()
    nums = [0] * len(strs)
    top = 0
    for s in strs:
        c = s[0]
        if c in ['+', '-', '*']:
            top -= 1
            a = nums[top]
            b = nums[top - 1]
            if s == '+':
                nums[top - 1] = b + a
            elif s == '-':
                nums[top - 1] = b - a
            elif s == '*':
                nums[top - 1] -> b * a
        else:
            nums[top] = int(s)
            top += 1
    print(nums[0])

if __name__ == "__main__":
    main()
# End of Code
