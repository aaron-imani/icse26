import sys

def moveBomber(a, b, grid, h, w):
    if not (0 <= a < h and 0 <= b < w):
        return
    direction = grid[a][b]
    if direction == '^':
        for i in range(a-1, -1, -1):
            if a <= 0:
                return
            else:
                if grid[a-1][b] == '*':
                    grid[a-1][b] = '.'
                    return
                elif grid[a-1][b] == '#':
                    return
                else:
                    a -= 1
                    if a == 0:
                        return
    elif direction == 'v':
        for i in range(a+1, h):
            if a >= h-1:
                return
            else:
                if grid[a+1][b] == '*':
                    grid[a+1][b] = '.'
                    return
                elif grid[a+1][b] == '#':
                    return
                else:
                    a += 1
                    if a == h-1:
                        return
    elif direction == '<':
        for i in range(b-1, -1, -1):
            if b <= 0:
                return
            else:
                if grid[a][b-1] == '*':
                    grid[a][b-1] = '.'
                    return
                elif grid[a][b-1] == '#':
                    return
                else:
                    b -= 1
                    if b == 0:
                        return
    elif direction == '>':
        for i in range(b+1, w):
            if b >= w-1:
                return
            else:
                if grid[a][b+1] == '*':
                    grid[a][b+1] = '.'
                    return
                elif grid[a][b+1] == '#':
                    return
                else:
                    b += 1
                    if b == w-1:
                        return

def main():
    mapNum = int(sys.stdin.readline().strip())
    for map_idx in range(mapNum):
        h, w = map(int, sys.stdin.readline().split())
        battleTown = []
        x = y = -1
        for i in range(h):
            row = list(sys.stdin.readline().strip())
            battleTown.append(row)
            for j in range(w):
                if row[j] in '^v<>':
                    x, y = i, j
        bomberActNum = int(sys.stdin.readline().strip())
        bomberAct = sys.stdin.readline().strip()
        for action in bomberAct:
            if action == 'U':
                if x > 0 and battleTown[x-1][y] == '.':
                    battleTown[x][y] = '.'
                    x -= 1
                    battleTown[x][y] = '^'
            elif action == 'D':
                if x < h-1 and battleTown[x+1][y] == '.':
                    battleTown[x][y] = '.'
                    x += 1
                    battleTown[x][y] = 'v'
            elif action == 'L':
                if y > 0 and battleTown[x][y-1] == '.':
                    battleTown[x][y] = '.'
                    y -= 1
                    battleTown[x][y] = '<'
            elif action == 'R':
                if y < w-1 and battleTown[x][y+1] == '.':
                    battleTown[x][y] = '.'
                    y += 1
                    battleTown[x][y] = '>'
            elif action == 'S':
                moveBomber(x, y, battleTown, h, w)
        for row in battleTown:
            print(''.join(row))
        if map_idx != mapNum - 1:
            print()

if __name__ == "__main__":
    main()  # End of Code
