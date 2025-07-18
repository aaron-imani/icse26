import sys

line = input()
N, M = map(int, line.split())

shortage = []

for i in range(M):
    line = input()
    A = int(line.split()[0])
    shortage.append(max(N - A, 0))

shortage.sort()

ans = sum(shortage[:-1])

print(ans)
# End of Code
