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
    for d in map(int, sys.stdin.read().split()):
        print(solve(d))

if __name__ == "__main__":
    main()
# End of Code
