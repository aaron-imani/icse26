n = int(input())
s = input().strip()

pop1st = s.count('1')

mod_s1 = pop1st + 1
surp1 = 0
for c in s:
    surp1 *= 2
    if c == '1':
        surp1 += 1
    surp1 %= mod_s1

surp9 = 0
if pop1st > 1:
    mod_s9_val = pop1st - 1
    surp9 = 0
    for c in s:
        surp9 *= 2
        if c == '1':
            surp9 += 1
        surp9 %= mod_s9_val
else:
    surp9 = 不出

for p in range(n):
    c = s[p]
    if c == '1':
        if pop1st == 1:
            print(0)
            continue
        else:
            exponent = n - p - 1
            mod_val = pop1st - 1
            dif = pow(2, exponent, mod_val)
            dw = (surp9 - dif) % mod_val
            current = dw
            ans = 1
            while current != 0:
                cnt = bin(current).count('1')
                current %= cnt
                ans += 1
            print(ans)
    else:
        exponent = n - p - 1
        mod_val = pop1st + 1
        dif = pow(2, exponent, mod_val)
        dw = (surp1 + dif) % mod_val
        current = dw
        ans = 1
        while current != 0:
            cnt = bin(current).count('1')
            current %= cnt
            ans += 1
        print(ans)
# End of Code
