import sys

def main():
    n, m = map(int, sys.stdin.readline().split())
    if n == 0:
        print(0)
    elif n == m:
        print(0)
    elif n > m:
        n %= m
        res = min(m - n, n)
        print(res)
    else:
        res = min(m - n, n)
        print(res)

if __name__ == "__main__":
    main()
# End of Code
