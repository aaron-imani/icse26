import sys

def main():
    input = sys.stdin.read().split()
    N = int(input[0])
    max_val = min_val = int(input[1])
    for i in range(1, N):
        num = int(input[i + 1])
        max_val = max(max_val, num)
        min_val = min(min_val, num)
    print(max_val - min_val)

if __name__ == "__main__":
    main()
# End of Code
