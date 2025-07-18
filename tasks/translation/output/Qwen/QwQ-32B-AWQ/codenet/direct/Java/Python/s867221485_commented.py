import sys

def main():
    N = int(sys.stdin.readline())
    s = sys.stdin.readline().strip()
    ans = 0
    sha = 0
    dot = 0
    first = True
    for c in s:
        if c == '#':
            first = False
            if sha <= dot:
                ans += sha
                sha = 0
                dot = 0
                first = True
            sha += 1
        else:
            if not first:
                dot += 1
    if sha <= dot:
        ans += sha
        dot = 0
    print(ans + dot)

if __name__ == "__main__":
    main()
# End of Code
