import sys

def next():
    return sys.stdin.readline().strip()

def nextInt():
    return int(next())

def nextLong():
    return int(next())

def nextDouble():
    return float(next())

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

    ans = min(AAA, BBB)  # 片方が端っこに来るまで。

    # 差を1減らす⇒差が偶数になる
    sa -= 1
    ans += 1

    # 差は偶数
    ans += sa // 2

print(ans)

# End of Code
