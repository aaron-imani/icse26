Here's the translated Python code:


N = int(input())
s = input().strip()

ans = 0
sha = 0
dot = 0
first = True

for c in s:
    if c == '#':
        first = False
        if sha <= dot:
            ans += sha
            sha = 0
            dot = 0
            first = True
        sha += 1
    else:
        dot += 1

if sha <= dot:
    ans += sha
    dot = 0

print(ans + dot)
# End of Code
