import sys

def main():
    H = int(sys.stdin.readline())
    W = int(sys.stdin.readline())
    C = [['.'] * (W + 2) for _ in range(H + 2)]
    for i in range(1, H + 1):
        line = sys.stdin.readline().strip()
        for j in range(1, W + 1):
            C[i][j] = line[j-1]
    
    if H == 1 and W == 1:
        print("No")
        return
    
    for i in range(1, H + 1):
        for j in range(1, W + 1):
            if C[i][j] == '#':
                up = C[i-1][j]
                down = C[i+1][j]
                left = C[i][j-1]
                right = C[i][j+1]
                if up != '#' and down != '#' and left != '#' and right != '#':
                    print("No")
                    return
    print("Yes")

if __name__ == "__main__":
    main()
# End of Code
