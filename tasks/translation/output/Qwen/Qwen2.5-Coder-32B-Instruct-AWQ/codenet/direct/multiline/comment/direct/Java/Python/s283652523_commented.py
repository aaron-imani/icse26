MOD = int(1e9) + 7

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    N = int(data[index])
    index += 1
    A = list(map(int, data[index:index + N]))
    index += N
    
    ans = 0
    total_sum = A[-1]
    for i in range(N - 2, -1, -1):
        ans += (total_sum * A[i]) % MOD
        ans %= MOD
        total_sum += A[i]
        total_sum %= MOD
    
    print(ans)

if __name__ == "__main__":
    solve()
# End of Code
