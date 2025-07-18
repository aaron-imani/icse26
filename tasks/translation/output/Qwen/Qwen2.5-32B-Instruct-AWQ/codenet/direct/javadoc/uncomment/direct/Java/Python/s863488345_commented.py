import sys

def move_bomber(a, b):
    if 0 <= a < h and 0 <= b < w:
        if battle_town[a][b] == '^':
            for i in range(a - 1, -1, -1):
                if battle_town[i][b] == '*':
                    battle_town[i][b] = '.'
                    return
                elif battle_town[i][b] == '#':
                    return
        elif battle_town[a][b] == 'v':
            for i in range(a + 1, h):
                if battle_town[i][b] == '*':
                    battle_town[i][b] = '.'
                    return
                elif battle_town[i][b] == '#':
                    return
        elif battle_town[a][b] == '<':
            for i in range(b - 1, -1, -1):
                if battle_town[a][i] == '*':
                    battle_town[a][i] = '.'
                    return
                elif battle_town[a][i] == '#':
                    return
        elif battle_town[a][b] == '>':
            for i in range(b + 1, w):
                if battle_town[a][i] == '*':
                    battle_town[a][i] = '.'
                    return
                elif battle_town[a][i] == '#':
                    return

map_num = int(input())
for _ in range(map_num):
    if _ > 0:
        print("")
    h, w = map(int, input().split())
    battle_town = []
    x, y = 0, 0
    for _ in range(h):
        row = list(input().strip())
        battle_town.append(row)
        for j in range(w):
            if battle_town[-1][j] in '^v<>':
                x, y = len(battle_town) - 1, j
    bomber_act_num = int(input())
    bomber_act = list(input().strip())

    for act in bomber_act:
        if act == 'U':
            battle_town[x][y] = '^'
            if x - 1 >= 0 and battle_town[x - 1][y] == '.':
                battle_town[x - 1][y] = '^'
                battle_town[x][y] = '.'
                x -= 1
        elif act == 'D':
            battle_town[x][y] = 'v'
            if x + 1 < h and battle_town[x + 1][y] == '.':
                battle_town[x + 1][y] = 'v'
                battle_town[x][y] = '.'
                x += 1
        elif act == 'L':
            battle_town[x][y] = '<'
            if y - 1 >= 0 and battle_town[x][y - 1] == '.':
                battle_town[x][y - 1] = '<'
                battle_town[x][y] = '.'
                y -= 1
        elif act == 'R':
            battle_town[x][y] = '>'
            if y + 1 < w and battle_town[x][y + 1] == '.':
                battle_town[x][y + 1] = '>'
                battle_town[x][y] = '.'
                y += 1
        elif act == 'S':
            move_bomber(x, y)

    for row in battle_town:
        print("".join(row))
# End of Code
