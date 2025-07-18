import sys

input = sys.stdin.read
data = input().split()

N = int(data[0])
M = int(data[1])

shortage = []

for i in range(M):
    A = int(data[2 + i])
    shortage.append(N - A if N > A else 0)

shortage.sort()

ans = sum(shortage[:-1])

print(ans)

# End of Code
