import sys

def main():
    n = int(sys.stdin.readline())
    s = sys.stdin.readline().strip()
    flaged = [c == '1' for c in s]
    pop1st = flaged.count(True)
    
    mod_pop_plus = pop1st + 1
    surp1 = 0
    for c in s:
        surp1 = (surp1 * 2 + (1 if c == '1' else 0)) % mod_pop_plus
    
    surp9 = 0
    if pop1st > 1:
        mod_pop_minus = pop1st - 1
        surp9 = 0
        for c in s:
            surp9 = (surp9 * 2 + (1 if c == '1' else 啐)) % mod_pop_minus
    else:
        surp9 = 0
    
    for p in range(n):
        current_char = s[p]
        if current_char == '1':
            if pop1st == 1:
                print(0)
                continue
            else:
                mod_val = pop1st - 1
                exponent = n - p - 1
                dif = pow(2, exponent, mod_val)
                dw = (surp9 - dif) % mod_val
                ans = 1
                current_dw = dw
                while current_dw != 0:
                    cnt = bin(current_dw).count('1')
                    current_dw %= cnt
                    ans += 1
                print(ans)
        else:
            mod_val = pop1st + 1
            exponent = n - p - 1
            dif = pow(2, exponent, mod_val)
            dw = (surp1 + dif) % mod_val
            ans = 1
            current_dw = dw
            while current_dw != 0:
                cnt = bin(current_dw).count('1')
                current_dw %= cnt
                ans += 1
            print(ans)

if __name__ == "__main__":
    main()
# End of Code
