import sys

def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n, m = map(int, sys.stdin.readline().split())
        if n == 0:
            print(0)
        elif n == m:
            print(0)
        else:
            rem = n % m
            ans = min(rem, m - rem)
            print(ans)

if __name__ == "__main__":
    main()
# End of Code
