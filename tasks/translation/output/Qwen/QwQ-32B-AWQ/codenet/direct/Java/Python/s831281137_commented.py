import sys

def input_list():
    return list(map(int, sys.stdin.read().split()))

data = input_list()
ptr = 0

def nint():
    global ptr
    ret = data[ptr]
    ptr += 1
    return ret

def main():
    N = nint()
    W = nint()
    v = [0] * (N + 1)
    w = [0] * (N + 1)
    for i in range(1, N+1):
        v[i] = nint()
        w[i] = nint()
    sumV = [[0]*(W+1) for _ in range(N+1)]
    for i in range(1, N+1):
        for i_sum in range(w[i]):
            sumV[i][i_sum] = sumV[i-1][i_sum]
        for i_sum in range(w[i], W+1):
            sumV[i][i_sum] = max(sumV[i-1][i_sum], sumV[i-1][i_sum - w[i]] + v[i])
    print(sumV[N][W])

if __name__ == "__main__":
    main()  # End of Code
