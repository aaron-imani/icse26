import sys

def main():
    input_line = sys.stdin.readline().strip()
    strs = input_line.split(" ")
    nums = []
    for s in strs:
        if s == '+':
            nums[-2] += nums[-1]
            nums.pop()
        elif s == '-':
            nums[-2] -= nums[-1]
            nums.pop()
        elif s == '*':
            nums[-2] *= nums[-1]
            nums.pop()
        else:
            nums.append(int(s))
    print(nums[0])

if __name__ == "__main__":
    main()  # End of Code
