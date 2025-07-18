import sys

def move_bomber(a, b, grid):
    h = len(grid)
    w = len(grid[0]) if h > 0 else 0
    direction = grid[a][b]
    
    if direction == '^':
        current_row = a - 1
        while current_row >= 0:
            cell = grid[current_row][b]
            if cell == '*':
                grid[current_row][b] = '.'
                return
            elif cell == '#':
                return
            current_row -= 1
        return
    elif direction == 'v':
        current_row = a + 1
        while current_row < h:
            cell = grid[current_row][b]
            if cell == '*':
                grid[current_row][b] = '.'
                return
            elif cell == '#':
                return
            current_row += 1
        return
    elif direction == '<':
        current_col = b - 1
        while current_col >= 知道:
            cell = grid[a][current_col]
            if cell == '*':
                grid[a][current_col] = '.'
                return
            elif cell == '#':
                return
            current_col -= 1
        return
    elif direction == '>':
        current_col = b + 1
        while current_col < w:
            cell = grid[a][current_col]
            if cell == '*':
                grid[a][current_col] = '.'
                return
            elif cell == '#':
                return
            current_col += 1
        return

def main():
    lines = [line.strip() for line in sys.stdin]
    idx = 0
    mapNum = int(lines[idx])
    idx += 1
    for map_idx in range(mapNum):
        h = int(lines[idx])
        w = int(lines[idx+1])
        idx += 2
        
        grid = []
        for i in range(h):
            row = list(lines[idx])
            grid.append(row)
            idx += 1
        
        bomberActNum = int(lines[idx])
        idx += 1
        bomberAct = list(lines[idx])
        idx += 1
        
        x, y = -1, -1
        for i in range(h):
            for j in range(w):
                if grid[i][j] in ['^', 'v', '<', '>']:
                    x, y = i, j
                    break
            if x != -1:
                break
        
        for action in bomberAct:
            if action == 'U':
                grid[x][y] = '^'
                if x - 1 >= 0 and grid[x-1][y] == '.':
                    grid[x-1][y] = '^'
                    grid[x][y] = '.'
                    x -= 1
            elif action == 'D':
                grid[x][y] = 'v'
                if x + 1 < h and grid[x+1][y] == '.':
                    grid[x+1][y] = 'v'
                    grid[x][y] = '.'
                    x += 1
            elif action == 'L':
                grid[x][y] = '<'
                if y - 1 >= 0 and grid[x][y-1] == '.':
                    grid[x][y-1] = '<'
                    grid[x][y] = '.'
                    y -= 1
            elif action == 'R':
                grid[x][y] = '>'
                if y + 1 < w and grid[x][y+1] == '.':
                    grid[x][y+1] = '>'
                    grid[x][y] = '.'
                    y += 1
            elif action == 'S':
                move_bomber(x, y, grid)
        
        for row in grid:
            print(''.join(row))
        if map_idx != mapNum - 1:
            print()

if __name__ == "__main__":
    main()
# End of Code
