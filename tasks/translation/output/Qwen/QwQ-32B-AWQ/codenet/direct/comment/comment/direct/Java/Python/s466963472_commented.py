import sys

def solve(d):
    ans = 0
    i = 1
    while i * d < 600:
        ans += (i * d) ** 3
        i += 1
    return ans

def main():
    for line in sys.stdin:
        d = int(line.strip())
        print(solve(d))

if __name__ == "__main__":
    main()
# End of Code
