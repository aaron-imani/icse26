import sys

def move_bomber(a, b):
    if 0 <= a and a <= h and 0 <= b and b <= w:
        if battle_town[a][b] == '^':
            for i in range(a-1, -1, -1):
                if battle_town[i][b] == '*':
                    battle_town[i][b] = '.'
                    return
                elif battle_town[i][b] == '#':
                    return
                a = i
                if a == 0:
                    return
        if battle_town[a][b] == 'v':
            for i in range(a+1, h):
                if battle_town[i][b] == '*':
                    battle_town[i][b] = '.'
                    return
                elif battle_town[i][b] == '#':
                    return
                a = i
                if a == h - 1:
                    return
        if battle_town[a][b] == '<':
            for i in range(b-1, -1, -1):
                if battle_town[a][i] == '*':
                    battle_town[a][i] = '.'
                    return
                elif battle_town[a][i] == '#':
                    return
                b = i
                if b == 0:
                    return
        if battle_town[a][b] == '>':
            for i in range(b+1, w):
                if battle_town[a][i] == '*':
                    battle_town[a][i] = '.'
                    return
                elif battle_town[a][i] == '#':
                    return
                b = i
                if b == w - 1:
                    return

map_num = int(input())
for _ in range(map_num):
    if _ > 0:
        print("")
    h, w = map(int, input().split())
    battle_town = []
    for _ in range(h):
        row = list(input().strip())
        battle_town.append(row)
        for j, c in enumerate(row):
            if c in '^v<>':
                x, y = _, j
    bomber_act_num = int(input())
    bomber_act = list(input().strip())
    for act in bomber_act:
        if act == 'U':
            battle_town[x][y] = '^'
            if x - 1 >= 0 and battle_town[x-1][y] == '.':
                battle_town[x-1][y] = '^'
                battle_town[x][y] = '.'
                x -= 1
        if act == 'D':
            battle_town[x][y] = 'v'
            if x + 1 < h and battle_town[x+1][y] == '.':
                battle_town[x+1][y] = 'v'
                battle_town[x][y] = '.'
                x += 1
        if act == 'L':
            battle_town[x][y] = '<'
            if y - 1 >= 0 and battle_town[x][y-1] == '.':
                battle_town[x][y-1] = '<'
                battle_town[x][y] = '.'
                y -= 1
        if act == 'R':
            battle_town[x][y] = '>'
            if y + 1 < w and battle_town[x][y+1] == '.':
                battle_town[x][y+1] = '>'
                battle_town[x][y] = '.'
                y += 1
        if act == 'S':
            move_bomber(x, y)
    for row in battle_town:
        print(''.join(row))
# End of Code
