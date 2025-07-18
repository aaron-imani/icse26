import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    idx = 0
    N = data[idx]; idx += 1
    W = data[idx]; idx += 1
    v = [0] * (N + 1)
    w = [0] * (N + 1)
    for i in range(1, N+1):
        v[i] = data[idx]; idx += 1
        w[i] = data[idx]; idx += 1

    sumV = [[0]*(W+1) for _ in range(N+1)]

    for i in range(1, N+1):
        wi = w[i]
        for i_sum in range(0, wi):
            sumV[i][i_sum] = sumV[i-1][i_sum]
        for i_sum in range(wi, W+1):
            option1 = sumV[i-1][i_sum]
            option2 = sumV[i-1][i_sum - wi] + v[i]
            sumV[i][i_sum] = max(option1, option2)
    
    print(sumV[N][W])

if __name__ == "__main__":
    main()
# End of Code
