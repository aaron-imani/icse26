import sys

def main():
    H, W = map(int, sys.stdin.readline().split())
    if H == 1 and W == 1:
        print("No")
        return
    grid = [['.' for _ in range(W + 2)] for _ in range(H + 2)]
    for i in range(1, H + 1):
        line = sys.stdin.readline().strip()
        for j in range(1, W + 1):
            grid[i][j] = line[j-1]
    for i in range(1, H + 1):
        for j in range(1, W + 1):
            if grid[i][j] == '#':
                up = grid[i-1][j]
                down = grid[i+1][j]
                left = grid[i][j-1]
                right = grid[i][j+1]
                if up != '#' and down != '#' and left != '#' and right != '#':
                    print("No")
                    return
    print("Yes")

if __name__ == '__main__':
    main()
# End of Code
