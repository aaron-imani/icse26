import sys

def main():
    import sys
    import io
    sys.stdin = io.StringIO(sys.stdin.read())
    
    strs = input().split()
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

if __name__ == "__main__":
    main()
# End of Code
