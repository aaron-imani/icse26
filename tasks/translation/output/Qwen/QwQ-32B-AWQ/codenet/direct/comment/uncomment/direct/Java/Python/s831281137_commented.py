def main():
    import sys
    n = int(sys.stdin.readline())
    W = int(sys.stdin.readline())
    v = [0] * (n + 1)
    w = [0] * (n + 1)
    for i in range(1, n+1):
        a, b = map(int, sys.stdin.readline().split())
        v[i] = a
        w[i] = b
    dp = [[0]*(W+1) for _ in range(n+1)]
    for i in range(1, n+1):
        wi = w[i]
        for j in range(0, wi):
            dp[i][j] = dp[i-1][j]
        for j in range(wi, W+1):
            dp[i][j] = max(dp[i-1][j], dp[i-1][j - wi] + v[i])
    print(dp[n][W])

if __name__ == "__main__":
    main()
# End of Code
