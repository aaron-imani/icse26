import sys

def solve(d):
    ans = 0
    i = 1
    while i * d < 600:
        x = i * d
        ans += x * x * d
        i += 1
    return ans

def main():
    data = list(map(int, sys.stdin.read().split()))
    for d in data:
        print(solve(d))

if __name__ == "__main__":
    main()
# End of Code
