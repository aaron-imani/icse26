import sys

def main():
    input = sys.stdin.read
    data = input().split()
    index = 0

    def nint():
        nonlocal index
        index += 1
        return int(data[index - 1])

    N = nint()
    W = nint()

    v = [0] * (N + 1)
    w = [0] * (N + 1)

    for i in range(1, N + 1):
        v[i] = nint()
        w[i] = nint()

    sumV = [[0] * (W + 1) for _ in range(N + 1)]

    for i in range(1, N + 1):
        for i_sum in range(w[i]):
            sumV[i][i_sum] = sumV[i - 1][i_sum]

        for i_sum in range(w[i], W + 1):
            sumV[i][i_sum] = max(sumV[i - 1][i_sum], sumV[i - 1][i_sum - w[i]] + v[i])

    print(sumV[N][W])

if __name__ == "__main__":
    main()  # End of Code
