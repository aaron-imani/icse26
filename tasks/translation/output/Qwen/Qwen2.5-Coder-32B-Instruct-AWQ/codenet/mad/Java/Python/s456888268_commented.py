import sys

def solve():
    tmp = ns()
    s = list(tmp)
    n = len(s)
    ans = 0
    cnt = 0
    for i in range(n):
        if s[i] == 'S':
            cnt += 1
        else:
            if cnt == 0:
                continue
            ans += 1
            cnt -= 1
    print(n - 2 * ans)

# constants
mod = int(1e9 + 7)
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
dx8 = [-1, -1, -1, 0, 0, 1, 1, 1]
dy8 = [-1, 0, 1, -1, 1, -1, 0, 1]
inf = float('inf')
linf = float('inf')
dinf = float('inf')
eps = 1e-10
pi = 3.141592653589793
sb = []
is_input = sys.stdin
out = sys.stdout

def reverse(arr):
    if isinstance(arr, list):
        return arr[::-1]
    elif isinstance(arr, str):
        return arr[::-1]
    else:
        raise TypeError("Unsupported type for reverse")

def get_reverse(s):
    return reverse(s)

def lower_bound(a, x):
    l, r = -1, len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] < x:
            l = c
        else:
            r = c
    return r

def upper_bound(a, x):
    l, r = -1, len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] <= x:
            l = c
        else:
            r = c
    return r

def rlower_bound(a, x):
    l, r = -1, len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] > x:
            l = c
        else:
            r = c
    return r

def rupper_bound(a, x):
    l, r = -1, len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] >= x:
            l = c
        else:
            r = c
    return r

def concat(x, arr):
    if isinstance(arr, list):
        return [x] + arr
    elif isinstance(arr, str):
        return x + arr
    else:
        raise TypeError("Unsupported type for concat")

def max3(x, y, z):
    return max(x, y, z)

def min3(x, y, z):
    return min(x, y, z)

def sort(arr):
    return sorted(arr)

def rsort(arr):
    return sorted(arr, reverse=True)

def fill(arr, x):
    return [x] * len(arr)

def plus(x, y):
    res = (x + y) % mod
    return res if res >= 0 else res + mod

def sub(x, y):
    res = (x - y) % mod
    return res if res >= 0 else res + mod

def mul(x, y):
    res = (x * y) % mod
    return res if res >= 0 else res + mod

def div(x, y):
    res = x * pow(y, mod - 2, mod) % mod
    return res if res >= 0 else res + mod

def pow(x, y):
    if y < 0:
        return 0
    if y == 0:
        return 1
    if y % 2 == 1:
        return (x * pow(x, y - 1, mod)) % mod
    root = pow(x, y // 2, mod)
    return root * root % mod

def ns():
    while True:
        c = sys.stdin.read(1)
        if c == '':
            return ''
        if c in '\n \r\t':
            continue
        s = c
        while True:
            c = sys.stdin.read(1)
            if c in '\n \r\t' or c == '':
                break
            s += c
        return s

def ni():
    return int(ns())

def nl():
    return int(ns())

def nd():
    return float(ns())

def main():
    solve()

if __name__ == "__main__":
    main()
# End of Code
