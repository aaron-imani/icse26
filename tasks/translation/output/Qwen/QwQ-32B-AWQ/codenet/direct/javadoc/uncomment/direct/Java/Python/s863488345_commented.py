import sys

def move_bomber(grid, a, b):
    direction = grid[a][b]
    h = len(grid)
    w = len(grid[0]) if h > 0 else 0
    if direction == '^':
        current_row = a - 1
        current_col = b
        while current_row >= 0:
            cell = grid[current_row][current_col]
            if cell == '*':
                grid[current_row][current_col] = '.'
                return
            elif cell == '#':
                return
            else:
                current_row -= 1
    elif direction == 'v':
        current_row = a + 1
        current_col = b
        while current_row < h:
            cell = grid[current_row][current_col]
            if cell == '*':
                grid[current_row][current_col] = '.'
                return
            elif cell == '#':
                return
            else:
                current_row += 1
    elif direction == '<':
        current_row = a
        current_col = b - 1
        while current_col >= 0:
            cell = grid[current_row][current_col]
            if cell == '*':
                grid[current_row][current_col] = '.'
                return
            elif cell == '#':
                return
            else:
                current_col -= 1
    elif direction == '>':
        current_row = a
        current_col = b + 1
        while current_col < w:
            cell = grid[current_row][current_col]
            if cell == '*':
                grid[current_row][current_col] = '.'
                return
            elif cell == '#':
                return
            else:
                current_col += 1

def main():
    import sys
    map_num = int(sys.stdin.readline())
    for i in range(map_num):
        if i > 0:
            print()
        h, w = map(int, sys.stdin.readline().split())
        battle_town = []
        for _ in range(h):
            line = sys.stdin.readline().strip()
            battle_town.append(list(line))
        x, y = -1, -1
        for j in range(h):
            for k in range(w):
                if battle_town[j][k] in {'^', 'v', '<', '>'}:
                    x, y = j, k
                    break
            if x != -1:
                break
        bomber_act_num = int(sys.stdin.readline())
        bomber_act = sys.stdin.readline().strip()
        for c in bomber_act:
            if c == 'U':
                battle_town[x][y] = '^'
                if x > 0 and battle_town[x-1][y] == '.':
                    prev_x = x
                    x -= 1
                    battle_town[x][y] = '^'
                    battle_town[prev_x][y] = '.'
            elif c == 'D':
                battle_town[x][y] = 'v'
                if x < h-1 and battle_town[x+1][y] == '.':
                    prev_x = x
                    x += 1
                    battle_town[x][y] = 'v'
                    battle_town[prev_x][y] = '.'
            elif c == 'L':
                battle_town[x][y] = '<'
                if y > 0 and battle_town[x][y-1] == '.':
                    prev_y = y
                    y -= 1
                    battle_town[x][y] = '<'
                    battle_town[x][prev_y] = '.'
            elif c == 'R':
                battle_town[x][y] = '>'
                if y < w-1 and battle_town[x][y+1] == '.':
                    prev_y = y
                    y += 1
                    battle_town[x][y] = '>'
                    battle_town[x][prev_y] = '.'
            elif c == 'S':
                move_bomber(battle_town, x, y)
        for row in battle_town:
            print(''.join(row))

if __name__ == '__main__':
    main()  # End of Code
