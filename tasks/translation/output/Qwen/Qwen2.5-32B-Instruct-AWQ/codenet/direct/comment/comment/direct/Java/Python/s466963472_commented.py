import sys

def read():
    try:
        d = int(input())
        return d, True
    except EOFError:
        return None, False

def solve(d):
    ans = 0
    for i in range(1, 600 // d + 1):
        x = i * d
        y = x * x
        ans += y * d
    return ans

if __name__ == "__main__":
    while True:
        d, flag = read()
        if not flag:
            break
        print(solve(d))

# End of Code
