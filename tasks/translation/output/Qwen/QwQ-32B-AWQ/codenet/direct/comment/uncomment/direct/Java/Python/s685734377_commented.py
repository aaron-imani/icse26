import sys

def main():
    n = int(sys.stdin.readline())
    a = []
    for _ in range(n):
        line = sys.stdin.readline().strip()
        a.append(list(line))
    
    P = 37
    Q = 47
    powP = [1] * (n + 1)
    for i in range(1, n+1):
        powP[i] = powP[i-1] * P
    
    hashRow = [[0]*n for _ in range(n)]
    hashCol = [[0]*n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            c = ord(a[i][j])
            for k in range(n):
                term = c * powP[(j - k) % n]
                hashRow[i][k] += term
                term_col = c * powP[(i - k) % n]
                hashCol[j][k] += term_col
    
    ans = 0
    for A in range(n):
        for B in range(n):
            ok = True
            for i in range(n):
                row_iA = (i + A) % n
                val_row = hashRow[row_iA][B]
                col_iB = (i + B) % n
                val_col = hashCol[col_iB][A]
                if val_row != val_col:
                    ok = False
                    break
            if ok:
                ans += 1
    print(ans)

if __name__ == "__main__":
    main()
# End of Code
