import sys

def main():
    n = int(sys.stdin.readline())
    a = []
    for _ in range(n):
        line = sys.stdin.readline().strip()
        assert len(line) == n
        a.append(list(line))
    
    P = 37
    Q = 47
    powP = [1] * (n + 1)
    powQ = [1] * (n + 1)
    for i in range(1, n + 1):
        powP[i] = powP[i-1] * P
        powQ[i] = powQ[i-1] * Q
    
    hashRow = [[0]*n for _ in range(n)]
    hashCol = [[0]*n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            c = ord(a[i][j])
            for k in range(n):
                exp = (j - k + n) % n
                hashRow[i][k] += c * powP[exp]
                exp_col = (i - k + n) % n
                hashCol[j][k] += c * powP[exp_col]
    
    ans = 0
    for A in range(n):
        for B in range(n):
            ok = True
            for i in range(n):
                row_idx = (i + A) % n
                col_idx = (i + B) % n
                if hashRow[row_idx][B] != hashCol[col_idx][A]:
                    ok = False
                    break
            if ok:
                ans += 1
    print(ans)

if __name__ == "__main__":
    main() # End of Code
