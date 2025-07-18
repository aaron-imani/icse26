import sys

N = 0
K = 0
Q = 0
A = 0
B = 0
C = 0
min_val = 9999999
ans = 0

def main():
    N = int(input().strip())
    s = input().strip()

    flag = False
    ans = 0
    hen = 0
    sha = 0
    dot = 0
    temp = 0
    first = True
    for i in range(N):
        if s[i] == '#':
            first = False
            if sha <= dot:
                ans += sha
                sha = 0
                dot = 0
                first = True
            else:
                temp += dot
            sha += 1
        else:
            dot += 1

    if sha <= dot:
        ans += sha
        dot = 0
    else:
        temp += dot

    print(ans + dot)

if __name__ == "__main__":
    main()
# End of Code
