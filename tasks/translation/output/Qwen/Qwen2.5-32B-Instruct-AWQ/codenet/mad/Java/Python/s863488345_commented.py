def move_bomber(a, b):
    if 0 <= a < h and 0 <= b < w:
        if battle_town[a][b] == '^':
            for i in range(a-1, -1, -1):
                if battle_town[i][b] == '*':
                    battle_town[i][b] = '.
                    return
                elif battle_town[i][b] == '#':
                    return
                else:
                    a = i
        elif battle_town[a][b] == 'v':
            for i in range(a+1, h):
                if battle_town[i][b] == '*':
                    battle_town[i][b] = '.
                    return
                elif battle_town[i][b] == '#':
                    return
                else:
                    a = i
        elif battle_town[a][b] == '<':
            for i in range(b-1, -1, -1):
                if battle_town[a][i] == '*':
                    battle_town[a][i] = '.
                    return
                elif battle_town[a][i] == '#':
                    return
                else:
                    b = i
        elif battle_town[a][b] == '>':
            for i in range(b+1, w):
                if battle_town[a][i] == '*':
                    battle_town[a][i] = '.
                    return
                elif battle_town[a][i] == '#':
                    return
                else:
                    b = i

map_num = int(input())
for i in range(map_num):
    if i > 0:
        print()
    h, w = map(int, input().split())
    battle_town = [list(input()) for _ in range(h)]
    x, y = 0, 0
    for j in range(h):
        for k in range(w):
            if battle_town[j][k] in '^v<>':
                x, y = j, k
    bomber_act_num = int(input())
    bomber_act = list(input())
    for l in range(bomber_act_num):
        if bomber_act[l] == 'U':
            battle_town[x][y] = '^'
            if x - 1 >= 0 and battle_town[x-1][y] == '.':
                battle_town[x-1][y] = '^'
                battle_town[x][y] = '.
                x -= 1
        elif bomber_act[l] == 'D':
            battle_town[x][y] = 'v'
            if x + 1 < h and battle_town[x+1][y] == '.':
                battle_town[x+1][y] = 'v'
                battle_town[x][y] = '.
                x += 1
        elif bomber_act[l] == 'L':
            battle_town[x][y] = '<'
            if y - 1 >= 0 and battle_town[x][y-1] == '.':
                battle_town[x][y-1] = '<'
                battle_town[x][y] = '.
                y -= 1
        elif bomber_act[l] == 'R':
            battle_town[x][y] = '>'
            if y + 1 < w and battle_town[x][y+1] == '.':
                battle_town[x][y+1] = '>'
                battle_town[x][y] = '.
                y += 1
        elif bomber_act[l] == 'S':
            move_bomber(x, y)
    for s in range(h):
        print(''.join(battle_town[s]))

# End of Code
