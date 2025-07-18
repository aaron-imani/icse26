import sys

def main():
    n = int(sys.stdin.readline())
    a = []
    for _ in range(n):
        line = sys.stdin.readline().strip()
        a.append(list(line))
    
    P = 37
    powP = [1] * (n + 1)
    for i in range(1, n + 1):
        powP[i] = powP[i - 1] * P
    
    hashRow = [[0] * n for _ in range(n)]
    hashCol = [[0] * n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            c_val = ord(a[i][j])
            for k in range(n):
                term = c_val * powP[(j - k + n) % n]
                hashRow[i][k] += term
                term_col = c_val * powP[(i - k + n) % n]
                hashCol[j][k] += term_col
    
    ans = 0
    for A in range(n):
        for B in range(n):
            ok = True
            for i in range(n):
                row_idx = (i + A) % n
                col_idx = (i + B) % n
                val_row = hashRow[row_idx][B]
                val_col = hashCol[col_idx][A]
                if val_row != val_col:
                    ok = False
                    break
            if ok:
                ans += 1
    print(ans)

if __name__ == '__main__':
    main()
# End of Code
