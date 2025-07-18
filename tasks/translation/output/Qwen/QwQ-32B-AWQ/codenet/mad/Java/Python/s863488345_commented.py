import sys

def main():
    global battle_town, h, w, x, y
    input = sys.stdin.read().split()
    idx = 0
    map_num = int(input[idx]); idx +=1

    for _ in range(map_num):
        if _ > 0:
            print()
        h = int(input[idx]); idx +=1
        w = int(input[idx]); idx +=1
        battle_town = []
        for _ in range(h):
            line = input[idx]; idx +=1
            battle_town.append(list(line))
        x, y = 0, 0
        for i in range(h):
            for j in range(w):
                if battle_town[i][j] in '^v<>':
                    x, y = i, j
        bomber_act_num = int(input[idx]); idx +=1
        bomber_act = list(input[idx]); idx +=1

        for action in bomber_act:
            if action == 'U':
                battle_town[x][y] = '^'
                if x -1 >=0 and battle_town[x-1][y] == '.':
                    battle_town[x-1][y] = '^'
                    battle_town[x][y] = '.'
                    x -=1
            elif action == 'D':
                battle_town[x][y] = 'v'
                if x+1 < h and battle_town[x+1][y] == '.':
                    battle_town[x+1][y] = 'v'
                    battle_town[x][y] = '.'
                    x +=1
            elif action == 'L':
                battle_town[x][y] = '<'
                if y-1 >=0 and battle_town[x][y-1] == '.':
                    battle_town[x][y-1] = '<'
                    battle_town[x][y] = '.'
                    y -=1
            elif action == 'R':
                battle_town[x][y] = '>'
                if y+1 < w and battle_town[x][y+1] == '.':
                    battle_town[x][y+1] = '>'
                    battle_town[x][y] = '.'
                    y +=1
            elif action == 'S':
                a, b = x, y
                move_bomber(a, b)
        for row in battle_town:
            print(''.join(row))

def move_bomber(a, b):
    global h, w, battle_town
    if not (0 <= a < h and 0 <= b < w):
        return
    direction = battle_town[a][b]
    if direction == '^':
        for i in range(a-1, -1, -1):
            cell = battle_town[i][b]
            if cell == '*':
                battle_town[i][b] = '.'
                return
            elif cell == '#':
                return
    elif direction == 'v':
        for i in range(a+1, h):
            cell = battle_town[i][b]
            if cell == '*':
                battle_town[i][b] = '.'
                return
            elif cell == '#':
                return
    elif direction == '<':
        for j in range(b-1, -1, -1):
            cell = battle_town[a][j]
            if cell == '*':
                battle_town[a][j] = '.'
                return
            elif cell == '#':
                return
    elif direction == '>':
        for j in range(b+1, w):
            cell = battle_town[a][j]
            if cell == '*':
                battle_town[a][j] = '.'
                return
            elif cell == '#':
                return

if __name__ == "__main__":
    main()
# End of Code
