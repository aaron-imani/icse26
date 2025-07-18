import sys

line = sys.stdin.readline().split()
N = int(line[0])
M = int(line[1])

shortage = []
for _ in range(M):
    A = int(sys.stdin.readline())
    shortage.append(max(0, N - A))

shortage.sort()

ans = sum(shortage[:-1])

print(ans)
# End of Code
