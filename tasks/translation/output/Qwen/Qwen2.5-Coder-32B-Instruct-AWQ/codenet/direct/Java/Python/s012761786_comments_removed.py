import sys

def next():
    return sys.stdin.read().split()[next.index]

def nextInt():
    return int(next())

def nextLong():
    return int(next())

def nextDouble():
    return float(next())

def splitString(s):
    return list(s)

def splitChar(s):
    return list(s)

def charToInt(aaa):
    return ord(aaa) - 48

def maxInt(a, lng):
    max_val = a[0]
    for i in range(1, lng):
        max_val = max(max_val, a[i])
    return max_val

def minInt(a, lng):
    min_val = a[0]
    for i in range(1, lng):
        min_val = min(min_val, a[i])
    return min_val

def maxLong(a, lng):
    max_val = a[0]
    for i in range(1, lng):
        max_val = max(max_val, a[i])
    return max_val

def minLong(a, lng):
    min_val = a[0]
    for i in range(1, lng):
        min_val = min(min_val, a[i])
    return min_val

next.index = 0
input_data = sys.stdin.read().split()
next.index = 0

n = nextLong()
a = nextLong()
b = nextLong()

sa = abs(a - b)

ans = 0

if sa % 2 == 0:
    ans = sa // 2
else:
    AAA = min((n - a), (a - 1))
    BBB = min((n - b), (b - 1))

    ans = min(AAA, BBB)

    sa -= 1
    ans += 1

    ans += sa // 2

print(ans)

# End of Code
