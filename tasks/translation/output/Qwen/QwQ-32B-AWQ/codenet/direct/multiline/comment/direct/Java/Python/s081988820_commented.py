import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    idx = 0
    H = data[idx]; idx += 1
    W = data[idx]; idx += 1
    c = [[0]*10 for _ in range(10)]
    for i in range(10):
        for j in range(10):
            c[i][j] = data[idx]
            idx += 1
    min_dist = [0] * 10
    for i in range(10):
        min_dist[i] = c[i][1]
    for _ in range(10):
        for i in range(10):
            for j in range(10):
                if min_dist[i] > c[i][j] + min_dist[j]:
                    min_dist[i] = c[i][j] + min_dist[j]
    ans = 0
    for _ in range(H):
        for _ in range(W):
            A = data[idx]
            idx += 1
            if A >= 0:
                ans += min_dist[A]
    print(ans)

if __name__ == "__main__":
    main()
# End of Code
