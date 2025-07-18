n = int(input())
s = input().strip()
flaged = [c == '1' for c in s]
pop1st = sum(1 for c in s if c == '1')

surp1 = 0
mod1 = pop1st + 1
for c in s:
    surp1 = (surp1 * 2 + (1 if c == '1' else 0)) % mod1

surp9 = 0
if pop1st > 1:
    mod9 = pop1st - 1
    for c in s:
        surp9 = (surp9 * 2 + (1 if c == '1' else 0)) % mod9
else:
    surp9 = 0

for p in range(n):
    if flaged[p]:
        if pop1st == 1:
            print(0)
            continue
        mod = pop1st - 1
        exponent = n - p - 1
        dif = pow(2, exponent, mod)
        dw = (surp9 - dif) % mod
        ans = 1
        while dw != 0:
            cnt = bin(dw).count('1')
            dw %= cnt
            ans += 1
        print(ans)
    else:
        mod = pop1st + 1
        exponent = n - p - 1
        dif = pow(2, exponent, mod)
        dw = (surp1 + dif) % mod
        ans = 1
        while dw != 0:
            cnt = bin(dw).count('1')
            dw %= cnt
            ans += 1
        print(ans)
# End of Code
