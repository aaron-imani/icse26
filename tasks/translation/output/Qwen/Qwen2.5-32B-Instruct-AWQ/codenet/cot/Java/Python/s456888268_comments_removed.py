mod = 10**9 + 7
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
dx8 = [-1, -1, -1, 0, 0, 1, 1, 1]
dy8 = [-1, 0, 1, -1, 1, -1, 0, 1]
inf = float('inf') // Integer.MAX_VALUE / 2
linf = float('inf') // Long.MAX_VALUE / 3
dinf = float('inf') // Double.MAX_VALUE / 3
eps = 1e-10
pi = 3.141592653589793

def solve():
    tmp = input().strip()
    s = list(tmp)
    n = len(s)
    ans = 0
    cnt = 0
    for i in range(n):
        if s[i] == 'S':
            cnt += 1
        else:
            if cnt == 0:
                continue
            ans += 1
            cnt -= 1
    print(n - 2 * ans)

def main():
    solve()

if __name__ == "__main__":
    main()
# End of Code
