import sys

def main():
    N, W = map(int, sys.stdin.readline().split())
    v = [0] * (N + 1)
    w = [0] * (N + 1)
    for i in range(1, N+1):
        vi, wi = map(int, sys.stdin.readline().split())
        v[i] = vi
        w[i] = wi
    sumV = [[0]*(W+1) for _ in range(N+1)]
    for i in range(1, N+1):
        current_w = w[i]
        for s in range(current_w):
            sumV[i][s] = sumV[i-1][s]
        for s in range(current_w, W+1):
            opt1 = sumV[i-1][s]
            opt2 = sumV[i-1][s - current_w] + v[i]
            sumV[i][s] = max(opt1, opt2)
    print(sumV[N][W])

if __name__ == "__main__":
    main() # End of Code
