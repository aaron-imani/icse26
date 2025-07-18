n, m = map(int, input().split())

solved = [False] * (n + 1)
penal = [0] * (n + 1)

for _ in range(m):
    parts = input().split()
    num = int(parts[0])
    action = parts[1]
    if action[0] == 'A':
        solved[num] = True
    else:
        if not solved[num]:
            penal[num] += 1

correct_ans = 0
num_penal = 0
for i in range(1, n + 1):
    if solved[i]:
        correct_ans += 1
        num_penal += penal[i]

print(correct_ans, num_penal)
# End of Code
