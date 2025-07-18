import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    idx = 0
    N = data[idx]; idx +=1
    W = data[idx]; idx +=1

    v = [0]*(N+1)
    w = [0]*(N+1)
    for i in range(1, N+1):
        v[i] = data[idx]; idx +=1
        w[i] = data[idx]; idx +=1

    dp = [[0]*(W+1) for _ in range(N+1)]

    for i in range(1, N+1):
        wi = w[i]
        vi = v[i]
        for j in range(W+1):
            if j < wi:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - wi] + vi)
    
    print(dp[N][W])

if __name__ == "__main__":
    main()  # End of Code
