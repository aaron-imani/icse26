N, M = map(int, input().split())
shortage = []
for _ in range(M):
    A = int(input())
    shortage.append(max(0, N - A))
shortage.sort()
ans = sum(shortage[:-1])
print(ans)
# End of Code
