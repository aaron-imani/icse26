import sys

def solve(d):
    total = 0
    for x in range(d, 600, d):
        total += x * x * d
    return total

def main():
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        parts = line.split()
        for p in parts:
            d = int(p)
            print(solve(d))

if __name__ == "__main__":
    main()
# End of Code
