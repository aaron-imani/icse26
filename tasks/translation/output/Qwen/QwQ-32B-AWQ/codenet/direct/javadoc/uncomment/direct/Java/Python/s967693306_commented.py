Here's the translated Python code:


n, m = map(int, input().split())
pos_to_digit = {}

for _ in range(m):
    s, c = map(int, input().split())
    if s in pos_to_digit:
        if pos_to_digit[s] != c:
            print(-1)
            exit()
    pos_to_digit[s] = c

for i in range(1000):
    s = str(i)
    if len(s) != n:
        continue
    flag = True
    for j in range(n):
        digit = int(s[j])
        pos = j + 1
        required = pos_to_digit.get(pos)
        if required is not None:
            if digit != required:
                flag = False
                break
        else:
            if digit != 0:
                if j == 0 and digit == 1:
                    continue
                else:
                    flag = False
                    break
    if flag:
        print(s)
        exit()

print(-1)
# End of Code
