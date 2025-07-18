import sys

d = 0

def read():
    global d
    if not sys.stdin.readline().strip().isdigit():
        return False
    d = int(sys.stdin.readline().strip())
    return True

def solve():
    ans = 0
    for i in range(1, 600 // d + 1):
        x = i * d
        y = x * x
        ans += y * d
    return ans

while read():
    print(solve())  # End of Code
