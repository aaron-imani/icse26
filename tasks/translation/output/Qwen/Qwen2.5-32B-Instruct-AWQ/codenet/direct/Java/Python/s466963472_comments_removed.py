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
    i = 1
    while i * d < 600:
        x = i * d
        y = x * x
        ans += y * d
        i += 1
    return ans

if __name__ == "__main__":
    while read():
        print(solve())

# End of Code
