import sys

def main():
    t = 1
    for _ in range(t):
        n, m = map(int, sys.stdin.readline().split())
        if n == 0:
            print(0)
            continue
        if n == m:
            print(0)
            continue
        if n > m:
            rem = n % m
            ans = min(rem, m - rem)
            print(ans)
        else:
            ans = min(m - n, n)
            print(ans)

if __name__ == "__main__":
    main()
# End of Code
