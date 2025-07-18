import sys

def main():
    sys.setrecursionlimit(1 << 25)
    n = int(sys.stdin.readline())
    a0 = list(map(int, sys.stdin.readline().split()))
    a1 = list(map(int, sys.stdin.readline().split()))
    a = [a0, a1]
    
    memo = [[[ -1 for _ in range(1 << n)] for _ in range(n + 1)] for _ in range(2)]
    
    def dp(flip, idx, msk):
        if msk == (1 << n) - 1:
            return 0
        if memo[flip][idx][msk] != -1:
            return memo[flip][idx][msk]
        x = bin(msk).count('1')
        ans = float('inf')
        ff = 0
        for i in range(n):
            if not (msk & (1 << i)):
                nf = x % 2
                if idx == n or (a[flip][idx] <= a[ ( (nf + (ff%2)) %2 ) ][i]):
                    new_flip = (nf + (ff % 2)) % 2
                    res = dp(new_flip, i, msk | (1 << i))
                    temp = ff + res
                    if temp < ans:
                        ans = temp
                ff += 1
        memo[flip][idx][msk] = ans
        return ans
    
    ans = dp(0, n, 0)
    print(-1 if ans >= 1e9 else ans)

if __name__ == "__main__":
    main()
# End of Code
