# Reading input
import sys
input = sys.stdin.read
data = input().split()

N = int(data[0])
Q = int(data[1])
s = data[2]

# Initialize prefix sum array
pre = [0] * (N + 1)

# Building the prefix sum array
for i in range(1, N):
    if s[i-1] == 'A' and s[i] == 'C':
        pre[i] = 1
    pre[i] += pre[i-1]

# Querying
for _ in range(Q):
    l, r = int(data[3 + 2 * _]), int(data[4 + 2 * _])
    r -= 1
    print(pre[r] - pre[l-1])

# End of Code
