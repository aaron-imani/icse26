import sys

def main():
    N, Q = map(int, sys.stdin.readline().split())
    s = sys.stdin.readline().strip()
    pre = [0] * (N + 1)
    for i in range(1, N):
        if s[i-1] == 'A' and s[i] == 'C':
            pre[i] = 1
    for i in range(1, N):
        pre[i] += pre[i-1]
    for _ in range(Q):
        l, r = map(int, sys.stdin.readline().split())
        r -= 1
        print(pre[r] - pre[l-1])

if __name__ == "__main__":
    main()
# End of Code
