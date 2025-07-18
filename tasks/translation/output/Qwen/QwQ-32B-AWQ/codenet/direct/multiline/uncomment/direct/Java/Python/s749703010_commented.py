import sys

def main():
    global n, a, memo
    n = int(sys.stdin.readline())
    a0 = list(map(int, sys.stdin.readline().split()))
    a1 = list(map(int, sys.stdin.readline().split()))
    a = [a0, a1]
    memo = [[[ -1 for _ in range(1<<n)] for _ in range(n+1)] for _ in range(2)]
    ans = dp(0, n, 0)
    print(-1 if ans >= 10**9 else ans)

def dp(fliped, idx, msk):
    global n, a, memo
    if msk == (1 << n) -1:
        return 0
    if memo[fliped][idx][msk] != -1:
        return memo[fliped][idx][msk]
    x = bin(msk).count('1')
    ans = float('inf')
    ff = 0
    for i in range(n):
        if not (msk & (1 << i)):
            nf = x % 2
            if idx == n or (a[fliped][idx] <= a[ (nf + (ff%2)) %2 ][i]):
                new_fliped = (nf + (ff%2)) %2
                res = ff + dp(new_fliped, i, msk | (1<<i))
                if res < ans:
                    ans = res
            ff +=1
    memo[fliped][idx][msk] = ans
    return ans

if __name__ == "__main__":
    main()
# End of Code
