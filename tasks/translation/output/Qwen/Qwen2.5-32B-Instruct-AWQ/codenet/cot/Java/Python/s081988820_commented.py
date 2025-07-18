H, W = map(int, input().split())
c = [list(map(int, input().split())) for _ in range(10)]
min_cost = [c[i][1] for i in range(10)]
for _ in range(10):
    for i in range(10):
        for j in range(10):
            min_cost[i] = min(min_cost[i], c[i][j] + min_cost[j])

ans = 0
for _ in range(H):
    row = list(map(int, input().split()))
    for A in row:
        if A >= 0:
            ans += min_cost[A]

print(ans)
# End of Code
