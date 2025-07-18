H, W = map(int, input().split())
grid = [ ['.']*(W+2) for _ in range(H+2) ]
for i in range(1, H+1):
    line = input().strip()
    for j in range(1, W+1):
        grid[i][j] = line[j-1]
if H == 1 and W == 1:
    print("No")
    exit()
for i in range(1, H+1):
    for j in range(1, W+1):
        if grid[i][j] == '#':
            up = grid[i-1][j]
            down = grid[i+1][j]
            left = grid[i][j-1]
            right = grid[i][j+1]
            if up != '#' and down != '#' and left != '#' and right != '#':
                print("No")
                exit()
print("Yes")
# End of Code
