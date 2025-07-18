H, W = map(int, input().split())

c = []
for _ in range(10):
    row = list(map(int, input().split()))
    c.append(row)

dist = [0] * 10
for i in range(10):
    dist[i] = c[i][1]

for _ in range(10):
    for i in range(10):
        for j in range(10):
            dist[i] = min(dist[i], c[i][j] + dist[j])

ans = 0
for _ in range(H):
    row = list(map(int, input().split()))
    for A in row:
        if A >= 0:
            ans += dist[A]

print(ans)
# End of Code
