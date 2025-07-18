import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    N = data[0]
    A = data[1:N+1]
    MOD = 10**9 + 7
    ans = 0
    sum_val = A[-1]
    for i in range(N-2, -1, -1):
        term = (sum_val * A[i]) % MOD
        ans += term
        ans %= MOD
        sum_val += A[i]
        sum_val %= MOD
    print(ans % MOD)

if __name__ == "__main__":
    main()
# End of Code
