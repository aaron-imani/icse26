import sys

line = input()

N, M = map(int, line.split())

shortage = []

for _ in range(M):
    A = int(input().split()[0])
    if N > A:
        shortage.append(N - A)

shortage.sort()

ans = sum(shortage[:-1]) if len(shortage) > 1 else 0

print(ans)  # End of Code
