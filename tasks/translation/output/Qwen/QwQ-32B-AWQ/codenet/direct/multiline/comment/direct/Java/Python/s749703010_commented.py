import sys

def main():
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
        ans = 10**18
        ff = 0
        for i in range(n):
            if (msk & (1 << i)) == 0:
                nf = x % 2
                if idx == n or a[flip][idx] <= a[(nf + (ff % 2)) % 2][i]:
                    new_flip = (nf + (ff % 2)) % 2
                    new_msk = msk | (1 << i)
                    res = ff + dp(new_flip, i, new_msk)
                    if res < ans:
                        ans = res
                ff += 1
            else:
                x -= 1
        memo[flip][idx][msk] = ans
        return ans
    
    ans_val = dp(0, n, 0)
    print(-1 if ans_val >= 10**18 else ans_val)

if __name__ == "__main__":
    main()
# End of Code
