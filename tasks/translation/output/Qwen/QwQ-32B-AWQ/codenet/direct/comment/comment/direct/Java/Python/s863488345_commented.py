import sys

def move_bomber(a, b, battle_town, h, w):
    direction = battle_town[a][b]
    if direction == '^':
        i = a - 1
        while i >= 0:
            current_char = battle_town[i][b]
            if current_char == '*':
                battle_town[i][b] = '.'
                return
            elif current_char == '#':
                return
            else:
                i -= 1
    elif direction == 'v':
        i = a + 1
        while i < h:
            current_char = battle_town[i][b]
            if current_char == '*':
                battle_town[i][b] = '.'
                return
            elif current_char == '#':
                return
            else:
                i += 1
    elif direction == '<':
        j = b - 1
        while j >= 0:
            current_char = battle_town[a][j]
            if current_char == '*':
                battle_town[a][j] = '.'
                return
            elif current_char == '#':
                return
            else:
                j -= 1
    elif direction == '>':
        j = b + 1
        while j < w:
            current_char = battle_town[a][j]
            if current_char == '*':
                battle_town[a][j] = '.'
                return
            elif current_char == '#':
                return
            else:
                j += 1

def main():
    data = sys.stdin.read().split()
    idx = 0
    mapNum = int(data[idx]); idx +=1

    for _ in range(mapNum):
        if _ != 0:
            print()
        h = int(data[idx]); idx +=1
        w = int(data[idx]); idx +=1

        battle_town = []
        for i in range(h):
            line = data[idx]; idx +=1
            battle_town.append(list(line))

        x, y = -1, -1
        for i in range(h):
            for j in range(w):
                if battle_town[i][j] in {'^', 'v', '<', '>'}:
                    x, y = i, j
                    break
            if x != -1:
                break

        bomberActNum = int(data[idx]); idx +=1
        bomberAct = list(data[idx]); idx +=1

        for act in bomberAct:
            if act == 'U':
                new_x, new_y = x-1, y
                if 0 <= new_x < h and 0 <= new_y < w and battle_town[new_x][new_y] == '.':
                    battle_town[x][y], x, y = '.', new_x, new_y
                    battle_town[x][y] = '^'
                else:
                    battle_town[x][y] = '^'
            elif act == 'D':
                new_x, new_y = x+1, y
                if 0 <= new_x < h and 0 <= new_y < w and battle_town[new_x][new_y] == '.':
                    battle_town[x][y], x, y = '.', new_x, new_y
                    battle_town[x][y] = 'v'
                else:
                    battle_town[x][y] = 'v'
            elif act == 'L':
                new_x, new_y = x, y-1
                if 0 <= new_x < h and 0 <= new_y < w and battle_town[new_x][new_y] == '.':
                    battle_town[x][y], y = '.', new_y
                    battle_town[x][y] = '<'
                else:
                    battle_town[x][y] = '<'
            elif act == 'R':
                new_x, new_y = x, y+1
                if 0 <= new_x < h and 0 <= new_y < w and battle_town[new_x][new_y] == '.':
                    battle_town[x][y], y = '.', new_y
                    battle_town[x][y] = '>'
                else:
                    battle_town[x][y] = '>'
            elif act == 'S':
                move_bomber(x, y, battle_town, h, w)

        for row in battle_town:
            print(''.join(row))

if __name__ == "__main__":
    main()
# End of Code
