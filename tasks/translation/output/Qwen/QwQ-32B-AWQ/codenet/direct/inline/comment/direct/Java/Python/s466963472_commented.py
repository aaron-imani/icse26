import sys

def solve(d):
    ans = 0
    for i in range(1, (600 // d)):
        x = i * d
        ans += x * x * d
    return ans

def main():
    data = map(int, sys.stdin.read().split())
    for d in data:
        print(solve(d))

if __name__ == "__main__":
    main()
# End of Code
