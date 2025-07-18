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

def main():
    input = sys.stdin.read
    data = input().split()
    index = 0
    map_num = int(data[index])
    index += 1
    results = []
    for _ in range(map_num):
        h = int(data[index])
        index += 1
        w = int(data[index])
        index += 1
        battle_town = []
        for _ in range(h):
            row = list(data[index])
            index += 1
            battle_town.append(row)
            for j, cell in enumerate(row):
                if cell in '^v<>':
                    x, y = _, j
        bomber_act_num = int(data[index])
        index += 1
        bomber_acts = list(data[index])
        index += 1
        for act in bomber_acts:
            if act == 'U':
                battle_town[x][y] = '^'
                if x > 0 and battle_town[x - 1][y] == '.':
                    battle_town[x - 1][y] = '^'
                    battle_town[x][y] = '.'
                    x -= 1
            elif act == 'D':
                battle_town[x][y] = 'v'
                if x < h - 1 and battle_town[x + 1][y] == '.':
                    battle_town[x + 1][y] = 'v'
                    battle_town[x][y] = '.'
                    x += 1
            elif act == 'L':
                battle_town[x][y] = '<'
                if y > 0 and battle_town[x][y - 1] == '.':
                    battle_town[x][y - 1] = '<'
                    battle_town[x][y] = '.'
                    y -= 1
            elif act == 'R':
                battle_town[x][y] = '>'
                if y < w - 1 and battle_town[x][y + 1] == '.':
                    battle_town[x][y + 1] = '>'
                    battle_town[x][y] = '.'
                    y += 1
            elif act == 'S':
                move_bomber(x, y)
        result = [''.join(row) for row in battle_town]
        results.append('\n'.join(result))
    print('\n\n'.join(results))

if __name__ == "__main__":
    main()  # End of Code
