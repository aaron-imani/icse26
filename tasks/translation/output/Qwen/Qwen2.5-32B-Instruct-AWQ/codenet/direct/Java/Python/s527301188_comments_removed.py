import sys

def main():
    input_line = sys.stdin.readline().strip()
    strs = input_line.split(" ")
    nums = []
    for s in strs:
        if s[0] == '+':
            top = nums.pop()
            nums[-1] += top
        elif s[0] == '-':
            top = nums.pop()
            nums[-1] -= top
        elif s[0] == '*':
            top = nums.pop()
            nums[-1] *= top
        else:
            nums.append(int(s))
    print(nums[0])

if __name__ == "__main__":
    main()  # End of Code
