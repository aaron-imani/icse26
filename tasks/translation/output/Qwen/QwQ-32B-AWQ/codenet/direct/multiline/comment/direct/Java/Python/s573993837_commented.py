t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    if n == 0:
        print(0)
        continue
    if n == m:
        print(0)
        continue
    if n > m:
        n %= m
    ans = min(m - n, n)
    print(ans)
# End of Code
