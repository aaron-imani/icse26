MOD = int(1e9+7)

def solve():
    N = int(input())
    A = list(map(int, input().split()))
    
    ans = 0
    sum_val = A[N-1]
    for i in range(N - 2, -1, -1):
        ans += (sum_val * A[i]) % MOD
        ans %= MOD
        sum_val += A[i]
        sum_val %= MOD
    print(ans)

if __name__ == "__main__":
    solve()
# End of Code
