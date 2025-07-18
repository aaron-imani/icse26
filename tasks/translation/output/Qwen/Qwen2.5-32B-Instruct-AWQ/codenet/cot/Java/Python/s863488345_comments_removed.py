map_num = 0
h = 0
w = 0
battle_town = []
bomber_act_num = 0
bomber_act = []
tank = [0, 0]
x_of_tank = 0
y_of_tank = 0
x_of_bomber = 0
y_of_bomber = 0
s = 0
k = 0
a = 0
b = 0
x = 0
y = 0

def main():
    global map_num, h, w, battle_town, bomber_act_num, bomber_act, x, y
    map_num = int(input())

    for i in range(map_num):
        if 1 <= i < map_num:
            print("")
        h = int(input())
        w = int(input())

        battle_town = [['' for _ in range(w)] for _ in range(h)]

        for j in range(h):
            c = list(input())
            for k in range(w):
                battle_town[j][k] = c[k]

                if battle_town[j][k] in ['^', 'v', '<', '>']:
                    x = j
                    y = k

        bomber_act_num = int(input())
        bomber_act = list(input())

        if 0 <= x <= h and 0 <= y <= w:
            for l in range(bomber_act_num):
                if bomber_act[l] == 'U':
                    battle_town[x][y] = '^'
                    if x - 1 >= 0 and battle_town[x - 1][y] == '.':
                        battle_town[x - 1][y] = '^'
                        battle_town[x][y] = '.'
                        x -= 1
                if bomber_act[l] == 'D':
                    battle_town[x][y] = 'v'
                    if x + 1 < h and battle_town[x + 1][y] == '.':
                        battle_town[x + 1][y] = 'v'
                        battle_town[x][y] = '.'
                        x += 1
                if bomber_act[l] == 'L':
                    battle_town[x][y] = '<'
                    if y - 1 >= 0 and battle_town[x][y - 1] == '.':
                        battle_town[x][y - 1] = '<'
                        battle_town[x][y] = '.'
                        y -= 1
                if bomber_act[l] == 'R':
                    battle_town[x][y] = '>'
                    if y + 1 < w and battle_town[x][y + 1] == '.':
                        battle_town[x][y + 1] = '>'
                        battle_town[x][y] = '.'
                        y += 1
                if bomber_act[l] == 'S':
                    x_of_bomber = x
                    y_of_bomber = y
                    move_bomber(x_of_bomber, y_of_bomber)

            for s in range(h):
                for k in range(w):
                    print(battle_town[s][k], end="")
                print()

def move_bomber(a, b):
    global battle_town, h, w
    if 0 <= a <= h and 0 <= b <= w:
        if battle_town[a][b] == '^':
            for i in range(a - 1, -1, -1):
                if a <= 0:
                    return
                if battle_town[i][b] == '*':
                    battle_town[i][b] = '.'
                    return
                elif battle_town[i][b] == '#':
                    return
                else:
                    a -= 1
                    if a == 0:
                        return
        if battle_town[a][b] == 'v':
            for i in range(a + 1, h):
                if battle_town[i][b] == '*':
                    battle_town[i][b] = '.'
                    return
                elif battle_town[i][b] == '#':
                    return
                else:
                    a += 1
                    if a == h:
                        return
        if battle_town[a][b] == '<':
            for i in range(b - 1, -1, -1):
                if battle_town[a][i] == '*':
                    battle_town[a][i] = '.'
                    return
                elif battle_town[a][i] == '#':
                    return
                else:
                    b -= 1
                    if b == 0:
                        return
        if battle_town[a][b] == '>':
            for i in range(b + 1, w):
                if battle_town[a][i] == '*':
                    battle_town[a][i] = '.'
                    return
                elif battle_town[a][i] == '#':
                    return
                else:
                    b += 1
                    if b == w:
                        return

if __name__ == "__main__":
    main()  # End of Code
