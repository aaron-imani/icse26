import sys
def solve(d):
    ans = 0
    max_i = 599 // d
    for i in range(1, max_i + 1):
        x = i * d
        ans += x * x * d
    return ans
def main():
    for d in map(int, sys.stdin):
        print(solve(d))
if __name__ == "__main__":
    main()
# End of Code
