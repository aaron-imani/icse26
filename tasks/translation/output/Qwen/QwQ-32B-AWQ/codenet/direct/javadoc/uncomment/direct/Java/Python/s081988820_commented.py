import sys

def main():
    H, W = map(int, sys.stdin.readline().split())
    c = []
    for _ in range(10):
        row = list(map(int, sys.stdin.readline().split()))
        c.append(row)
    min_cost = [0] * 10
    for i in range(10):
        min_cost[i] = c[i][1]
    for _ in range(10):
        for i in range(10):
            for j in range(10):
                min_cost[i] = min(min_cost[i], c[i][j] + min_cost[j])
    ans = 0
    for _ in range(H):
        row = list(map(int, sys.stdin.readline().split()))
        for A in row:
            if A >= 0:
                ans += min_cost[A]
    print(ans)

if __name__ == "__main__":
    main()
# End of Code
