def main():
    H, W = map(int, input().split())
    grid = [['.' for _ in range(W + 2)] for _ in range(H + 2)]
    for i in range(H):
        s = input().strip()
        for j in range(W):
            grid[i + 1][j + 1] = s[j]
    if H == 1 and W == 1:
        print("No")
        return
    for i in range(1, H + 1):
        for j in range(1, W + 1):
            if grid[i][j] == '#':
                up = grid[i - 1][j]
                down = grid[i + 1][j]
                left = grid[i][j - 1]
                right = grid[i][j + 1]
                if up != '#' and down != '#' and left != '#' and right != '#':
                    print("No")
                    return
    print("Yes")

if __name__ == "__main__":
    main()
# End of Code
