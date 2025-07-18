import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    n = data[0]
    m = data[1]
    if n == 0:
        print(0)
    elif n == m:
        print(0)
    elif n > m:
        remainder = n % m
        res = min(m - remainder, remainder)
        print(res)
    else:
        res = min(m - n, n)
        print(res)

if __name__ == "__main__":
    main()
# End of Code
