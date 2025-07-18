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

    # Calculate surp1
    mod_surp1 = pop1st + 1
    surp1 = 0
    for i in range(n):
        temp = surp1 * 2
        if flaged[i]:
            temp += 1
        surp1 = temp % mod_surp1

    # Calculate surp9
    surp9 = 0
    if pop1st > 1:
        mod_surp9 = pop1st - 1
        surp9 = 0
        for i in range(n):
            temp = surp9 * 2
            if flaged[i]:
                temp += 1
            surp9 = temp % mod_surp9
    else:
        surp9 = 0  # Not used when pop1st <= 1

    for p in range(n):
        if flaged[p]:
            if pop1st == 1:
                print(0)
                continue
            mod_val = pop1st - 1
            exponent = n - p - 1
            dif = pow(2, exponent, mod_val)
            dw = (surp9 - dif) % mod_val
            ans = 1
            while dw != 0:
                count = bin(dw).count('1')
                dw %= count
                ans += 1
            print(ans)
        else:
            mod_val = pop1st + 1
            exponent = n - p - 1
            dif = pow(2, exponent, mod_val)
            dw = (surp1 + dif) % mod_val
            ans = 1
            while dw != 0:
                count = bin(dw).count('1')
                dw %= count
                ans += 1
            print(ans)

if __name__ == "__main__":
    main()
# End of Code
