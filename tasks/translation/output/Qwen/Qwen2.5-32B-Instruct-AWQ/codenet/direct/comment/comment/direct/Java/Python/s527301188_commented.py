import sys

def main():
    input_line = sys.stdin.readline().strip()
    tokens = input_line.split(" ")
    nums = []
    
    for token in tokens:
        if token == "+":
            nums[-2] += nums[-1]
            nums.pop()
        elif token == "-":
            nums[-2] -= nums[-1]
            nums.pop()
        elif token == "*":
            nums[-2] *= nums[-1]
            nums.pop()
        else:
            nums.append(int(token))
    
    print(nums[0])

if __name__ == "__main__":
    main()  # End of Code
