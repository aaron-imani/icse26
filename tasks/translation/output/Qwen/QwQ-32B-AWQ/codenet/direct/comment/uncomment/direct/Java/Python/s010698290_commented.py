n, m = map(int, input().split())

solved = [False] * (n + 1)
penal = [0] * (n + 1)

for _ in range(m):
    parts = input().split()
    num = int(parts[0])
    cmd = parts[1]
    if cmd == 'A':
        solved[num] = True
    else:
        if not solved[num]:
            penal[num] += 1

correct_ans = 0
total_penal = 0
for i in range(1, n + 1):
    if solved[i]:
        correct_ans += 1
        total_penal += penal[i]

print(correct_ans, total_penal)
# End of Code
