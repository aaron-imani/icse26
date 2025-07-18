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
    out.write(str(n - 2 * ans) + '\n')

# constant
mod = 10**9 + 7
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
dx8 = [-1, -1, -1, 0, 0, 1, 1, 1]
dy8 = [-1, 0, 1, -1, 1, -1, 0, 1]
inf = sys.maxsize // 2
linf = sys.maxsize // 3
dinf = float('inf') / 3
eps = 1e-10
pi = 3.141592653589793
sb = []
is_input = False
out = sys.stdout

# libraries
def reverse(ar):
    ar.reverse()

def getReverse(s):
    return s[::-1]

def lowerBound(a, x):
    l, r = -1, len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] < x:
            l = c
        else:
            r = c
    return r

def upperBound(a, x):
    l, r = -1, len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] <= x:
            l = c
        else:
            r = c
    return r

def rlowerBound(a, x):
    l, r = -1, len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] > x:
            l = c
        else:
            r = c
    return r

def rupperBound(a, x):
    l, r = -1, len(a)
    while r - l > 1:
        c = (l + r) // 2
        if a[c] >= x:
            l = c
        else:
            r = c
    return r

def max(x, y):
    return x if x > y else y

def min(x, y):
    return x if x < y else y

def sort(ar):
    ar.sort()

def rsort(ar):
    ar.sort(reverse=True)

def fill(ar, x):
    for i in range(len(ar)):
        ar[i] = x

def fill2d(ar, x):
    for i in range(len(ar)):
        for j in range(len(ar[i])):
            ar[i][j] = x

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

def main():
    global is_input
    is_input = True
    solve()

def ns():
    if is_input:
        return sys.stdin.readline().strip()
    else:
        return INPUT.pop(0)

def ni():
    return int(ns())

def nl():
    return int(ns())

def na(n):
    return [ni() for _ in range(n)]

def nla(n):
    return [nl() for _ in range(n)]

def nm(n, m):
    return [ns(m) for _ in range(n)]

# End of Code
