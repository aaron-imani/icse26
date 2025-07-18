import sys

def main():
    N, W = map(int, sys.stdin.readline().split())
    v = [0] * (N + 1)
    w = [0] * (N + 1)
    for i in range(1, N + 1):
        a, b = map(int, sys.stdin.readline().split())
        v[i] = a
        w[i] = b
    sumV = [[0] * (W + 1) for _ in range(N + 1)]
    for i in range(1, N + 1):
        for i_sum in range(0, w[i]):
            sumV[i][i_sum] = sumV[i-1][i_sum]
        for i_sum in range(w[i], W + 1):
            option1 = sumV[i-1][i_sum]
            option2 = sumV[i-1][i_sum - w[i]] + v[i]
            sumV[i][i_sum] = max(option1, option2)
    print(sumV[N][W])

if __name__ == "__main__":
    main()
# End of Code
