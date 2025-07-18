def main():
    MOD = 10**9 + 7
    N = int(input())
    A = list(map(int, input().split()))
    ans = 0
    sum_val = A[-1]
    for i in range(N-2, -1, -1):
        term = (sum_val * A[i]) % MOD
        ans += term
        ans %= MOD
        sum_val = (sum_val + A[i]) % MOD
    print(ans % MOD)

if __name__ == "__main__":
    main()
# End of Code
