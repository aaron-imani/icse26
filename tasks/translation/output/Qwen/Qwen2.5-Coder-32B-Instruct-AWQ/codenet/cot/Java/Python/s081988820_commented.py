def main():
    H = int(input())
    W = int(input())
    c = [[0] * 10 for _ in range(10)]
    for i in range(10):
        for j in range(10):
            c[i][j] = int(input())
    min_cost = [c[i][1] for i in range(10)]
    for _ in range(10):
        for i in range(10):
            for j in range(10):
                min_cost[i] = min(min_cost[i], c[i][j] + min_cost[j])
    ans = 0
    for _ in range(H):
        for _ in range(W):
            A = int(input())
            if A >= 0:
                ans += min_cost[A]
    print(ans)

# End of Code
