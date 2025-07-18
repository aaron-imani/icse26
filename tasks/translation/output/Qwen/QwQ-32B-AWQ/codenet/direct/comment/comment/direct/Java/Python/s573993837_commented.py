import sys

def main():
    data = sys.stdin.read().split()
    idx = 0
    t = int(data[idx])
    idx += 1
    for _ in range(t):
        n = int(data[idx])
        m = int(data[idx+1])
        idx += 2
        if n == 0:
            print(0)
            continue
        if n == m:
            print(0)
            continue
        if n > m:
            rem = n % m
            ans = min(rem, m - rem)
        else:
            ans = min(m - n, n)
        print(ans)

if __name__ == "__main__":
    main()
# End of Code
