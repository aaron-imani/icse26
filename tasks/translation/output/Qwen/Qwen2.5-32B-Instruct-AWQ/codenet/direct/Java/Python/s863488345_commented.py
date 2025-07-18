import sys

def move_bomber(a, b):
    if 0 <= a < h and 0 <= b < w:
        if battle_town[a][b] == '^':
            for i in range(a-1, -1, -1):
                if battle_town[i][b] == '*':
                    battle_town[i][b] = '.'
                    return
                elif battle_town[i][b] == '#':
                    return
                else:
                    a = i
                    if a == 0:
                        return
        elif battle_town[a][b] == 'v':
            for i in range(a+1, h):
                if battle_town[i][b] == '*':
                    battle_town[i][b] = '.'
                    return
                elif battle_town[i][b] == '#':
                    return
                else:
                    a = i
                    if a == h - 1:
                        return
        elif battle_town[a][b] == '<':
            for i in range(b-1, -1, -1):
                if battle_town[a][i] == '*':
                    battle_town[a][i] = '.'
                    return
                elif battle_town[a][i] == '#':
                    return
                else:
                    b = i
                    if b == 0:
                        return
        elif battle_town[a][b] == '>':
            for i in range(b+1, w):
                if battle_town[a][i] == '*':
                    battle_town[a][i] = '.'
                    return
                elif battle_town[a][i] == '#':
                    return
                else:
                    b = i
                    if b == w - 1:
                        return

def main():
    input = sys.stdin.read
    data = input().split()
    index = 0

    map_num = int(data[index])
    index += 1

    for _ in range(map_num):
        if _ > 0:
            print()
        h = int(data[index])
        index += 1
        w = int(data[index])
        index += 1

        battle_town = []
        for _ in range(h):
            row = list(data[index])
            index += 1
            battle_town.append(row)
            for k, char in enumerate(row):
                if char in '^v<>':
                    x, y = _, k

        bomber_act_num = int(data[index])
        index += 1
        bomber_act = list(data[index])
        index += 1

        for act in bomber_act:
            if act == 'U':
                battle_town[x][y] = '^'
                if x - 1 >= 0 and battle_town[x-1][y] == '.':
                    battle_town[x-1][y] = '^'
                    battle_town[x][y] = '.'
                    x -= 1
            elif act == 'D':
                battle_town[x][y] = 'v'
                if x + 1 < h and battle_town[x+1][y] == '.':
                    battle_town[x+1][y] = 'v'
                    battle_town[x][y] = '.'
                    x += 1
            elif act == 'L':
                battle_town[x][y] = '<'
                if y - 1 >= 0 and battle_town[x][y-1] == '.':
                    battle_town[x][y-1] = '<'
                    battle_town[x][y] = '.'
                    y -= 1
            elif act == 'R':
                battle_town[x][y] = '>'
                if y + 1 < w and battle_town[x][y+1] == '.':
                    battle_town[x][y+1] = '>'
                    battle_town[x][y] = '.'
                    y += 1
            elif act == 'S':
                move_bomber(x, y)

        for row in battle_town:
            print(''.join(row))

if __name__ == "__main__":
    main()  # End of Code
