import sys

def main():
    H, W = map(int, sys.stdin.readline().split())
    c = [[0]*10 for _ in range(10)]
    for i in range(10):
        line = list(map(int, sys.stdin.readline().split()))
        for j in range(10):
            c[i][j] = line[j]
    min_dist = [0]*10
    for i in range(10):
        min_dist[i] = c[i][1]
    for _ in range(10):
        for i in range(10):
            for j in range(10):
                if min_dist[i] > c[i][j] + min_dist[j]:
                    min_dist[i] = c[i][j] + min_dist[j]
    total = 0
    for _ in range(H):
        line = list(map(int, sys.stdin.readline().split()))
        for a in line:
            if a >= 0:
                total += min_dist[a]
    print(total)

if __name__ == "__main__":
    main()
# End of Code
