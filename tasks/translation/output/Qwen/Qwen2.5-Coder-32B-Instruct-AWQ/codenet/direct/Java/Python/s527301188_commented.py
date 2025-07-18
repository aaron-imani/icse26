import sys

def main():
    import sys
    import io
    sys.stdin = io.StringIO(sys.stdin.read())
    
    nums = []
    for token in sys.stdin.readline().split():
        if token == '+':
            nums[-2] = nums[-2] + nums[-1]
            nums.pop()
        elif token == '-':
            nums[-2] = nums[-2] - nums[-1]
            nums.pop()
        elif token == '*':
            nums[-2] = nums[-2] * nums[-1]
            nums.pop()
        else:
            nums.append(int(token))
    
    print(nums[0])

if __name__ == "__main__":
    main()
# End of Code
