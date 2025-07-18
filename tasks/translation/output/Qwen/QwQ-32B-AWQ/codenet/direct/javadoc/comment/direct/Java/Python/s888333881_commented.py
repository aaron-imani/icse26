n = int(input())
s = input().strip()

flaged = [c == '1' for c in s]
pop1st = sum(flaged)

surp1 = 0
mod_s1 = pop1st + 1
for i in range(n):
    surp1 = (surp1 * 2 + (1 if flaged[i] else 0)) % mod_s1

surp9 = 0
if pop1st > 1:
    mod_s9 = pop1st - 1
    surp9 = 0
    for i in range(n):
        surp9 = (surp9 * 2 + (1 if flaged[i] else 0)) % mod_s9

for p in range(n):
    if flaged[p]:
        if pop1st == 1:
            print(0)
            continue
        mod_val = pop1st - 1
        exponent = n - p - 1
        term = pow(2, exponent, mod_val)
        dw = (surp9 - term) % mod_val
        ans = 1
        while dw != 0:
            cnt = bin(dw).count('1')
            dw %= cnt
            ans += 1
        print(ans)
    else:
        mod_val = pop1st + 1
        exponent = n - p - 1
        term = pow(2, exponent, mod_val)
        dw = (surp1 + term) % mod_val
        ans = 1
        while dw != 0:
            cnt = bin(dw).count('1')
            dw %= cnt
            ans += 1
        print(ans)
# End of Code
