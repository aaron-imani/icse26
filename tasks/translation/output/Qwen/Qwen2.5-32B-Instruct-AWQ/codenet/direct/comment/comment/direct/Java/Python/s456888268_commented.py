mod = 10**9 + 7
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
dx8 = [-1, -1, -1, 0, 0, 1, 1, 1]
dy8 = [-1, 0, 1, -1, 1, -1, 0, 1]
inf = float('inf')
linf = float('inf')
dinf = float('inf')
eps = 1e-10
pi = 3.141592653589793

def reverse(ar):
    return ar[::-1]

def get_reverse(s):
    return s[::-1]

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

def r_lower_bound(a, x):
    l, r = -1, len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] > x:
            l = c
        else:
            r = c
    return r

def r_upper_bound(a, x):
    l, r = -1, len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] >= x:
            l = c
        else:
            r = c
    return r

def concat(x, arr):
    return [x] + arr

def concat(arr, x):
    return arr + [x]

def max_(x, y):
    return max(x, y)

def min_(x, y):
    return min(x, y)

def max_(x, y, z):
    return max(x, y, z)

def min_(x, y, z):
    return min(x, y, z)

def sort_(ar):
    return sorted(ar)

def r_sort(ar):
    return sorted(ar, reverse=True)

def fill(arr, x):
    return [x] * len(arr)

def fill_2d(arr, x):
    return [[x for _ in range(len(arr[0]))] for _ in range(len(arr))]

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

def pow_(x, y):
    if y < 0:
        return 0
    if y == 0:
        return 1
    if y % 2 == 1:
        return (x * pow_(x, y - 1, mod)) % mod
    root = pow_(x, y // 2, mod)
    return (root * root) % mod

def solve():
    s = input()
    cnt = 0
    ans = 0
    for c in s:
        if c == 'S':
            cnt += 1
        else:
            if cnt == 0:
                continue
            ans += 1
            cnt -= 1
    print(len(s) - 2 * ans)

if __name__ == "__main__":
    solve()  # End of Code
