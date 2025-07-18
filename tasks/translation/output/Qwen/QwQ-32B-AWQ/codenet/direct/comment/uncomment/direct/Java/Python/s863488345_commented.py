import sys

def move_bomber(a, b, battle_town, h, w):
    direction = battle_town[a][b]
    if direction == '^':
        current_a = a
        current_b = b
        while True:
            next_a = current_a - 1
            if next_a < 0:
                break
            cell = battle_town[next_a][current_b]
            if cell == '*':
                battle_town[next_a][current_b] = '.'
                break
            elif cell == '#':
                break
            else:
                current_a = next_a
    elif direction == 'v':
        current_a = a
        current_b = b
        while True:
            next_a = current_a + 1
            if next_a >= h:
                break
            cell = battle_town[next_a][current_b]
            if cell == '*':
                battle_town[next_a][current_b] = '.'
                break
            elif cell == '#':
                break
            else:
                current_a = next_a
    elif direction == '<':
        current_a = a
        current_b = b
        while True:
            next_b = current_b - 1
            if next_b < 0:
                break
            cell = battle_town[current_a][next_b]
            if cell == '*':
                battle_town[current_a][next_b] = '.'
                break
            elif cell == '#':
                break
            else:
                current_b = next_b
    elif direction == '>':
        current_a = a
        current_b = b
        while True:
            next_b = current_b + 1
            if next_b >= w:
                break
            cell = battle_town[current_a][next_b]
            if cell == '*':
                battle_town[current_a][next_b] = '.'
                break
            elif cell == '#':
                break
            else:
                current_b = next_b

def main():
    mapNum = int(sys.stdin.readline())
    for i in range(mapNum):
        if i > 0:
            print()
        h, w = map(int, sys.stdin.readline().split())
        battle_town = []
        x, y = -1, -1
        for row_idx in range(h):
            line = sys.stdin.readline().strip()
            row = list(line)
            battle_town.append(row)
            for col_idx in range(w):
                if row[col_idx] in ['^', 'v', '<', '>']:
                    x = row_idx
                    y = col_idx
        bomberActNum = int(sys.stdin.readline())
        bomberAct = sys.stdin.readline().strip()
        for action in bomberAct:
            if action == 'U':
                new_dir = '^'
                battle_town[x][y] = new_dir
                next_x = x - 1
                next_y = y
                if 0 <= next_x < h and 0 <= next_y < w:
                    if battle_town[next_x][next_y] == '.':
                        battle_town[x][y] = '.'
                        battle_town[next_x][next_y] = new_dir
                        x = next_x
                        y = next_y
            elif action == 'D':
                new_dir = 'v'
                battle_town[x][y] = new_dir
                next_x = x + 1
                next_y = y
                if 0 <= next_x < h and 0 <= next_y < w:
                    if battle_town[next_x][next_y] == '.':
                        battle_town[x][y] = '.'
                        battle_town[next_x][next_y] = new_dir
                        x = next_x
                        y = next_y
            elif action == 'L':
                new_dir = '<'
                battle_town[x][y] = new_dir
                next_x = x
                next_y = y - 1
                if 0 <= next_x < h and 0 <= next_y < w:
                    if battle_town[next_x][next_y] == '.':
                        battle_town[x][y] = '.'
                        battle_town[next_x][next_y] = new_dir
                        x = next_x
                        y = next_y
            elif action == 'R':
                new_dir = '>'
                battle_town[x][y] = new_dir
                next_x = x
                next_y = y + 1
                if 0 <= next_x < h and 0 <= next_y < w:
                    if battle_town[next_x][next_y] == '.':
                        battle_town[x][y] = '.'
                        battle_town[next_x][next_y] = new_dir
                        x = next_x
                        y = next_y
            elif action == 'S':
                move_bomber(x, y, battle_town, h, w)
        for row in battle_town:
            print(''.join(row))

if __name__ == "__main__":
    main() # End of Code
