import sys
def next():
    return next.input_list[next.index]
def nextInt():
    return int(next())
def nextLong():
    return int(next())
def nextDouble():
    return float(next())
next.input_list = sys.stdin.read().split()
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
