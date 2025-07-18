import sys

def main():
    n = int(sys.stdin.readline())
    a0 = list(map(int, sys.stdin.readline().split()))
    a1 = list(map(int, sys.stdin.readline().split()))
    a = [a0, a1]
    
    memo = [[[ -1 for _ in range(1 << n)] for _ in range(n + 1)] for _ in range(2)]
    
    def dp(flip, idx, msk):
        if msk == (1 << n) -1:
            return 0
        if memo[flip][idx][msk] != -1:
            return memo[flip][idx][msk]
        x = bin(msk).count('1')
        ans = float('inf')
        ff = 0
        for i in range(n):
            if (msk & (1 << i)) == 0:
                nf = x % 2
                next_flip = (nf + (ff % 2)) % 2
                if idx == n or a[flip][idx] <= a[next_flip][i]:
                    new_msk = msk | (1 << i)
                    res = ff + dp(next_flip, i, new_msk)
                    if res < ans:
                        ans = res
                ff += 1
            else:
                x -= 1
        memo[flip][idx][msk] = ans
        return ans
    
    ans = dp(0, n, 0)
    print(ans if ans != float('inf') else -1)

if __name__ == "__main__":
    main()
# End of Code
