def solve():
    tmp = input().strip()
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

# Constants
mod = 10**9 + 7
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
dx8 = [-1, -1, -1, 0, 0, 1, 1, 1]
dy8 = [-1, 0, 1, -1, 1, -1, 0, 1]
inf = float('inf') // 2
linf = float('inf') // 3
dinf = float('inf') // 3
eps = 1e-10
pi = 3.141592653589793

# Libraries
def reverse(ar):
    ar.reverse()

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
    ar.sort()

def rsort(ar):
    ar.sort()
    ar.reverse()

def fill(ar, x):
    for i in range(len(ar)):
        ar[i] = x

def plus(x, y):
    return (x + y) % mod

def sub(x, y):
    return (x - y) % mod

def mul(x, y):
    return (x * y) % mod

def div(x, y):
    return (x * pow(y, mod - 2, mod)) % mod

def pow_(x, y):
    if y < 0:
        return 0
    if y == 0:
        return 1
    if y % 2 == 1:
        return (x * pow_(x, y - 1, mod)) % mod
    root = pow_(x, y // 2, mod)
    return (root * root) % mod

solve()
# End of Code
