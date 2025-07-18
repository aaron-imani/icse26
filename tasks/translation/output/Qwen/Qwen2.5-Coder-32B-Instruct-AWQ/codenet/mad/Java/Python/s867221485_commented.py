N = int(input().strip())
s = input().strip()

ans = 0
sha = 0
dot = 0

for i in range(N):
    if s[i] == '#':
        if sha <= dot:
            ans += sha
            sha = 0
            dot = 0
        sha += 1
    else:
        dot += 1

if sha <= dot:
    ans += sha
    dot = 0

print(ans + dot)
# End of Code
