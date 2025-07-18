import sys

def read():
    global d
    try:
        d = int(next(sys.stdin).strip())
        return True
    except ValueError:
        return False

def solve():
    ans = 0
    for i in range(1, 600 // d):
        x = i * d
        y = x * x
        ans += y * d
    return ans

def main():
    while read():
        print(solve())

if __name__ == "__main__":
    main()
# End of Code
