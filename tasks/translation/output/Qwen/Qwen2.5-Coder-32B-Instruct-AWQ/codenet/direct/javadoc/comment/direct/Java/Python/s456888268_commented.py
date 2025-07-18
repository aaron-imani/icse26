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

#constant
mod = int(1e9) + 7
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
dx8 = [-1, -1, -1, 0, 0, 1, 1, 1]
dy8 = [-1, 0, 1, -1, 1, -1, 0, 1]
inf = float('inf') // 2
linf = float('inf') // 3
dinf = float('inf') // 3
eps = 1e-10
pi = 3.141592653589793
sb = []
is_ = None
out = None
INPUT = ""

#libraries
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

def max(*args):
    return max(args)

def min(*args):
    return min(args)

def sort(ar):
    ar.sort()

def rsort(ar):
    ar.sort(reverse=True)

def fill(arr, x):
    for i in range(len(arr)):
        arr[i] = x

def fill2d(arr, x):
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            arr[i][j] = x

#MOD culc
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

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    solve()
# End of Code
