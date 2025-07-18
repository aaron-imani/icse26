import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    N = data[0]
    max_val = data[1]
    min_val = max_val
    for i in range(2, N+1):
        num = data[i]
        max_val = max(max_val, num)
        min_val = min(min_val, num)
    print(max_val - min_val)

if __name__ == "__main__":
    main()
# End of Code
