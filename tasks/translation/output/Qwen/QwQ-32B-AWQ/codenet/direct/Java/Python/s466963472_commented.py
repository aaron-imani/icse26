import sys

def solve(d):
    ans = 0
    for i in range(1, (599 // d) + 1):
        x = i * d
        ans += x * x * d
    return ans

def main():
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        d = int(line)
        print(solve(d))

if __name__ == "__main__":
    main()
# End of Code
