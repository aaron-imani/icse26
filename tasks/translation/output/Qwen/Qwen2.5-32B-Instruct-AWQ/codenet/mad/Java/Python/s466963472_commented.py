import sys

def read():
    try:
        d = int(input())
        return d
    except ValueError:
        return False

def solve(d):
    ans = 0
    for i in range(1, 600 // d + 1):
        x = i * d
        y = x * x
        ans += y * d
    return ans

while True:
    d = read()
    if not d:
        break
    print(solve(d))

# End of Code
