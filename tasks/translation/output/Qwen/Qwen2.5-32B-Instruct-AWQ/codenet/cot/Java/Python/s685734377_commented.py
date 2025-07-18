from sys import stdin, stdout

def solve(testNumber):
    n = int(stdin.readline())
    a = [list(stdin.readline().strip()) for _ in range(n)]
    P, Q = 37, 47
    powP = [1] * (n + 1)
    powQ = [1] * (n + 1)
    for i in range(1, n + 1):
        powP[i] = powP[i - 1] * P
        powQ[i] = powQ[i - 1] * Q

    hashRow = [[0] * n for _ in range(n)]
    hashCol = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                hashRow[i][k] += ord(a[i][j]) * powP[(j - k + n) % n]
                hashCol[j][k] += ord(a[i][j]) * powP[(i - k + n) % n]

    ans = 0
    for A in range(n):
        for B in range(n):
            ok = True
            for i in range(n):
                if hashRow[(i + A) % n][B] != hashCol[(i + B) % n][A]:
                    ok = False
                    break
            ans += 1 if ok else 0
    stdout.write(str(ans) + '\n')

solve(1)  # End of Code
