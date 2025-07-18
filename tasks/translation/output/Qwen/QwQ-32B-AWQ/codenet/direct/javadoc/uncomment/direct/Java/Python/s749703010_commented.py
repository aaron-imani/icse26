import sys
sys.setrecursionlimit(1 << 25)

def main():
    n = int(input())
    a0 = list(map(int, input().split()))
    a1 = list(map(int, input().split()))
    a = [a0, a1]
    memo = [[[ -1 for _ in range(1<<n)] for _ in range(n+1)] for _ in range(2)]
    
    def dp(flip, idx, mask):
        if mask == (1 << n) -1:
            return 0
        if memo[flip][idx][mask] != -1:
            return memo[flip][idx][mask]
        x = bin(mask).count('1')
        ans = float('inf')
        ff = 0
        for i in range(n):
            if (mask & (1 << i)) == 0:
                nf = x % 2
                if (idx == n or a[flip][idx] <= a[ (nf + (ff %2 )) %2 ][i]):
                    new_flip = (nf + (ff %2 )) %2
                    new_mask = mask | (1 << i)
                    res = ff + dp(new_flip, i, new_mask)
                    if res < ans:
                        ans = res
                ff +=1
            else:
                x -=1
        memo[flip][idx][mask] = ans
        return ans
    
    ans = dp(0, n, 0)
    print(ans if ans != float('inf') else -1)
    
if __name__ == "__main__":
    main()
# End of Code
