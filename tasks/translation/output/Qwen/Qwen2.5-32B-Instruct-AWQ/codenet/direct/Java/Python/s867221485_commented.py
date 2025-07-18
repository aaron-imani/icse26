N = int(input())

s = input()

flag = False
ans = 0
sha = 0
dot = 0
temp = 0
first = True

for i in range(N):
    if s[i] == '#':
        first = False
        if sha <= dot:
            ans += sha
            sha = 0
            dot = 0
            first = True
        else:
            temp += dot
        sha += 1
    else:
        if not first:
            dot += 1

if sha <= dot:
    ans += sha
    dot = 0
else:
    temp += dot

print(ans + dot)  # End of Code
