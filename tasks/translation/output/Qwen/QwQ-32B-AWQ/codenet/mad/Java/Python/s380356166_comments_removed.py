K, S = map(int, input().split())
ans = 0
for x in range(K + 1):
    for y in range(K + 1):
        wk = S - x - y
        if 0 <= wk <= K:
            ans += 1
print(ans)
# End of Code
