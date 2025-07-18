n, q = map(int, input().split())
s = input().strip()
pre = [0]*(n+1)
for i in range(1, n):
    if s[i-1] == 'A' and s[i] == 'C':
        pre[i] = 1
for i in range(1, n):
    pre[i] += pre[i-1]
for _ in range(q):
    l, r = map(int, input().split())
    r -= 1
    print(pre[r] - pre[l-1])
# End of Code
