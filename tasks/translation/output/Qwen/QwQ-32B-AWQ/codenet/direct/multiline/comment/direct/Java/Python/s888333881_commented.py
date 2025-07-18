import sys

def main():
    n = int(sys.stdin.readline().strip())
    s = sys.stdin.readline().strip()
    flaged = [False] * n
    pop1st = 0
    for i in range(n):
        if s[i] == '1':
            flaged[i] = True
            pop1st += 1

    mod1 = pop1st + 1
    surp1 = 0
    for i in range(n):
        surp1 = (surp1 * 2 + (1 if flaged[i] else 0)) % mod1

    surp9 = None
    if pop1st > 1:
        mod9 = pop1st - 1
        surp9 = 0
        for i in range(n):
            surp9 = (surp9 * 2 + (1 if flaged[i] else 0)) % mod9

    for p in range(n):
        if flaged[p]:
            if pop1st == 1:
                print(0)
            else:
                exponent = n - p - 1
                mod_val = pop1st - 1
                dif = pow(2, exponent, mod_val)
                dw = (surp9 - dif) % mod_val
                ans = 1
                while dw != 0:
                    cnt = bin(dw).count('1')
                    dw = dw % cnt
                    ans += 1
                print(ans)
        else:
            exponent = n - p - 1
            mod_val = pop1st + 1
            dif = pow(2, exponent, mod_val)
            dw = (surp1 + dif) % mod_val
            ans = 1
            while dw != 0:
                cnt = bin(dw).count('1')
                dw = dw % cnt
                ans += 1
            print(ans)

if __name__ == "__main__":
    main()
# End of Code
