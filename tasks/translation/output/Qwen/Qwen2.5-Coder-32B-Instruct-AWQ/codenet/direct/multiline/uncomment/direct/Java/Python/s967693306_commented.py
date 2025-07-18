import sys
from collections import defaultdict

INF = sys.maxsize // 2
MOD = 1_000_000_007
SIZE = 1_000_000

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def inv(a):
    return pow(a, MOD - 2, MOD)

def pow_mod(a, r):
    sum_val = 1
    while r > 0:
        if r & 1:
            sum_val = sum_val * a % MOD
        a = a * a % MOD
        r >>= 1
    return sum_val

def mod_fact(n):
    if n == 0:
        return 1
    return n * mod_fact(n - 1) % MOD

def fact(n):
    if n == 0:
        return 1
    return n * fact(n - 1)

def init_comb():
    fac = [0] * SIZE
    inv = [0] * SIZE
    finv = [0] * SIZE
    fac[0] = fac[1] = 1
    inv[1] = 1
    finv[0] = finv[1] = 1
    for i in range(2, SIZE):
        fac[i] = fac[i - 1] * i % MOD
        inv[i] = MOD - inv[MOD % i] * (MOD // i) % MOD
        finv[i] = finv[i - 1] * inv[i] % MOD
    return fac, inv, finv

def mod_comb(n, r, fac, finv):
    if n < r or n < 0 or r < 0:
        return 0
    return fac[n] * finv[r] % MOD * finv[n - r] % MOD

def is_prime(a):
    if a <= 1:
        return False
    for i in range(2, int(a**0.5) + 1):
        if a % i == 0:
            return False
    return True

def next_permutation(s):
    s = list(s)
    pivot_pos = -1
    pivot = 0
    for i in range(len(s) - 2, -1, -1):
        if s[i] < s[i + 1]:
            pivot_pos = i
            pivot = s[i]
            break

    if pivot_pos == -1 and pivot == 0:
        return None

    L = pivot_pos + 1
    R = len(s) - 1
    min_pos = -1
    min_val = chr(ord('z') + 1)
    for i in range(R, L - 1, -1):
        if pivot < s[i]:
            if s[i] < min_val:
                min_val = s[i]
                min_pos = i

    s[pivot_pos], s[min_pos] = s[min_pos], s[pivot_pos]
    s[L:] = sorted(s[L:])

    return ''.join(s)

def next_permutation_arr(a):
    for i in range(len(a) - 1, 0, -1):
        if a[i - 1] < a[i]:
            swap_index = find(a[i - 1], a, i, len(a) - 1)
            a[swap_index], a[i - 1] = a[i - 1], a[swap_index]
            a[i:] = sorted(a[i:])
            return True
    return False

def find(dest, a, s, e):
    if s == e:
        return s
    m = (s + e + 1) // 2
    return find(dest, a, s, m - 1) if a[m] <= dest else find(dest, a, m, e)

def elimination(a, b):
    n = len(a)
    for k in range(n - 1):
        for i in range(k + 1, n):
            f = -a[i][k] / a[k][k]
            for j in range(k + 1, n):
                a[i][j] += f * a[k][j]
            b[i] += f * b[k]
    for i in range(n - 1, -1, -1):
        for j in range(i + 1, n):
            b[i] -= a[i][j] * b[j]
        b[i] /= a[i][i]

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0

    def next_int():
        nonlocal index
        result = int(data[index])
        index += 1
        return result

    n = next_int()
    m = next_int()
    map_dict = defaultdict(int)

    for _ in range(m):
        s = next_int()
        c = next_int()
        if map_dict[s] != 0 and map_dict[s] != c:
            print(-1)
            return
        map_dict[s] = c

    for i in range(1000):
        s = str(i)
        flag = True
        if len(s) < n:
            continue
        for j in range(n):
            if (map_dict[j + 1] != 0 and map_dict[j + 1] != int(s[j])) or (map_dict[j + 1] == 0 and int(s[j]) != 0):
                if map_dict[j + 1] == 0 and j == 0 and int(s[j]) == 1:
                    continue
                flag = False
                break
        if flag and len(s) == n:
            print(s)
            return

    print(-1)

if __name__ == "__main__":
    main()
# End of Code
