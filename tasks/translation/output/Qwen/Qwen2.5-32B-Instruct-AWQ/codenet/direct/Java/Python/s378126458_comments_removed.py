import sys

input = sys.stdin.read
data = input().split()
idx = 0

N = int(data[idx])
Q = int(data[idx + 1])
s = data[idx + 2]
idx += 3

pre = [0] * (N + 1)
for i in range(1, N):
    if s[i-1] == 'A' and s[i] == 'C':
        pre[i] = 1

for i in range(1, N):
    pre[i] += pre[i-1]

for _ in range(Q):
    l = int(data[idx])
    r = int(data[idx + 1])
    idx += 2
    r -= 1
    print(pre[r] - pre[l-1])

# End of Code
