N, M = map(int, input().split())
shortage = []
for _ in range(M):
    A = int(input())
    shortage.append(max(N - A, 0))
shortage.sort()
ans = sum(shortage[:-1])
print(ans)  # End of Code
