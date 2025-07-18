import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    nums = []
    for token in data:
        if token == '+':
            b = nums.pop()
            a = nums.pop()
            nums.append(a + b)
        elif token == '-':
            b = nums.pop()
            a = nums.pop()
            nums.append(a - b)
        elif token == '*':
            b = nums.pop()
            a = nums.pop()
            nums.append(a * b)
        else:
            nums.append(int(token))
    
    print(nums[0])

if __name__ == "__main__":
    main()  # End of Code
