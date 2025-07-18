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

# constants
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

# helper functions
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

def max(*args):
    return max(args)

def min(*args):
    return min(args)

def sort(ar):
    ar.sort()

def rsort(ar):
    ar.sort()
    ar.reverse()

def fill(ar, x):
    for i in range(len(ar)):
        ar[i] = x

def main():
    solve()

if __name__ == "__main__":
    main()
# End of Code
