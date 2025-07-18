Here's the Python code translated from the provided Java code:


import sys

def main():
    n = int(sys.stdin.readline())
    s = sys.stdin.readline().strip()

    flaged = [False] * n
    pop1st = 0
    for i in range(n):
        if s[i] == '1':
            flaged[i] = True
            pop1st += 1

    mod_s1 = pop1st + 1
    surp1 = 0
    for c in s:
        surp1 = (surp1 * 2 + (1 if c == '1' else 0)) % mod_s1

    surp9 = 0
    if pop1st > 1:
        mod_s9 = pop1st - 1
        surp9 = 0
        for c in s:
            surp9 = (surp9 * 2 + (1 if c == '1' else 0)) % mod_s9
    else:
        surp9 = 0

    for p in range(n):
        if flaged[p]:
            if pop1st == 1:
                print(0)
                continue
            else:
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

if __name__ == "__main__":
    main()  # End of Code
