import sys

def main():
    input = sys.stdin.read().split()
    index = 0
    map_num = int(input[index])
    index += 1

    for _ in range(map_num):
        if _ > 0:
            print()
        h = int(input[index])
        w = int(input[index + 1])
        index += 2

        battle_town = []
        for _ in range(h):
            row = list(input[index])
            index += 1
            battle_town.append(row)

        x, y = -1, -1
        for i in range(h):
            for j in range(w):
                if battle_town[i][j] in ['^', 'v', '<', '>']:
                    x, y = i, j

        bomber_act_num = int(input[index])
        bomber_act = list(input[index + 1])
        index += 2

        if 0 <= x < h and 0 <= y < w:
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
                    x_of_bomber, y_of_bomber = x, y
                    move_bomber(battle_town, x_of_bomber, y_of_bomber)

            for row in battle_town:
                print(''.join(row))

def move_bomber(battle_town, a, b):
    if 0 <= a < len(battle_town) and 0 <= b < len(battle_town[0]):
        if battle_town[a][b] == '^':
            for i in range(a - 1, -1, -1):
                if battle_town[i][b] == '*':
                    battle_town[i][b] = '.'
                    return
                elif battle_town[i][b] == '#':
                    return
        elif battle_town[a][b] == 'v':
            for i in range(a + 1, len(battle_town)):
                if battle_town[i][b] == '*':
                    battle_town[i][b] = '.'
                    return
                elif battle_town[i][b] == '#':
                    return
        elif battle_town[a][b] == '<':
            for j in range(b - 1, -1, -1):
                if battle_town[a][j] == '*':
                    battle_town[a][j] = '.'
                    return
                elif battle_town[a][j] == '#':
                    return
        elif battle_town[a][b] == '>':
            for j in range(b + 1, len(battle_town[0])):
                if battle_town[a][j] == '*':
                    battle_town[a][j] = '.'
                    return
                elif battle_town[a][j] == '#':
                    return

if __name__ == "__main__":
    main()
# End of Code
