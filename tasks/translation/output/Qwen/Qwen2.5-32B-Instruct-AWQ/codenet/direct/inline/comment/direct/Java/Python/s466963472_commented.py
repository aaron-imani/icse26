import sys

d = 0

def read():
    global d
    line = sys.stdin.readline()
    if not line:
        return False
    d = int(line)
    return True

def solve():
    ans = 0
    for i in range(1, 600 // d + 1):
        x = i * d
        y = x * x
        ans += y * d
    return ans

if __name__ == "__main__":
    while read():
        print(solve())

# End of Code
