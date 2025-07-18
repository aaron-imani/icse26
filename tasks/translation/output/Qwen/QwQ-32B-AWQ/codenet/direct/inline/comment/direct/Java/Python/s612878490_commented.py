n, m = map(int, input().split())
shortage = []
for _ in range(m):
    a = int(input())
    shortage.append(max(0, n - a))
shortage.sort()
ans = sum(shortage[:-1])
print(ans)
# End of Code
