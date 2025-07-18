mod = int(1e9 + 7)
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
is_input = ""
out = print

def reverse(ar):
    ar.reverse()

def get_reverse(s):
    return s[::-1]

def sbnl():
    sb.append("\n")

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
    ar.sort(reverse=True)

def fill(arr, x):
    for i in range(len(arr)):
        arr[i] = x

def solve():
    tmp = input()
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
    out(n - 2 * ans)

if __name__ == "__main__":
    solve()  # End of Code
