import sys
def main():
    MOD = 10**9 + 7
    input = sys.stdin.read().split()
    idx = 0
    N = int(input[idx])
    idx += 1
    A = list(map(int, input[idx:idx+N]))
    idx += N
    ans = 0
    sum_val = A[-1]
    for i in range(N-2, -1, -1):
        ans += (sum_val * A[i]) % MOD
        ans %= MOD
        sum_val += A[i]
        sum_val %= MOD
    print(ans % MOD)
if __name__ == "__main__":
    main()
# End of Code
