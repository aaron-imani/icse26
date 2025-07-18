import sys

def read():
    global d
    try:
        d = int(input().strip())
        return True
    except ValueError:
        return False

def solve():
    ans = 0
    i = 1
    while i * d < 600:
        x = i * d
        y = x * x
        ans += y * d
        i += 1
    return ans

def main():
    while read():
        print(solve())

if __name__ == "__main__":
    main()
# End of Code
