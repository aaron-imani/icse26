n = int(input())
s = input().strip()

flaged = [False] * n
pop1st = 0
for i in range(n):
    if s[i] == '1':
        flaged[i] = True
        pop1st += 1

mod1 = pop1st + 1
surp1 = 0
for i in range(n):
    surp1 = (surp1 * 2) % mod1
    if flaged[i]:
        surp1 = (surp1 + 1) % mod1

surp9 = 0
if pop1st > 1:
    mod9 = pop1st - 1
    surp9 = 0
    for i in range(n):
        surp9 = (surp9 * 2) % mod9
        if flaged[i]:
            surp9 = (surp9 + 1) % mod9

for p in range(n):
    if s[p] == '1':
        if pop1st == 1:
            print(0)
            continue
        mod_val = pop1st - 1
        exponent = n - p - 1
        dif = pow(2, exponent, mod_val)
        dw = (surp9 - dif) % mod_val
        ans = 1
        while dw != 0:
            cnt = bin(dw).count('1')
            dw %= cnt
            ans += 1
        print(ans)
    else:
        mod_val = pop1st + 1
        exponent = n - p - 1
        dif = pow(2, exponent, mod_val)
        dw = (surp1 + dif) % mod_val
        ans = 1
        while dw != 0:
            cnt = bin(dw).count('1')
            dw %= cnt
            ans += 1
        print(ans)
#End of Code
