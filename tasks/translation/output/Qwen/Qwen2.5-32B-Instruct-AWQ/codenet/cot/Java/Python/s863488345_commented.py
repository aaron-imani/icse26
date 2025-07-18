mapNum = 0  # Buttle Town図の数
h = 0  # 地図の大きさの縦
w = 0  # 地図の大きさの横
battleTown = []  # Buttle Town地図取込用
bomberActNum = 0  # 指示された戦車の行動数
bomberAct = []  # 指示された戦車の行動
tank = [0, 0]
xOfTank = 0
yOfTank = 0
xOfBomber = 0
yOfBomber = 0
s = 0  # 表示用
k = 0  # 表示用
a = 0  # x Of Bomber
b = 0  # y Of Bomber
x = 0  # tankの位置x
y = 0  # tankの位置y

def main():
    global mapNum, h, w, battleTown, bomberActNum, bomberAct, xOfTank, yOfTank, xOfBomber, yOfBomber, s, k, a, b, x, y
    mapNum = int(input())

    for i in range(mapNum):
        if 1 <= i < mapNum:
            print("")
        h = int(input())
        w = int(input())

        battleTown = [['' for _ in range(w)] for _ in range(h)]

        for j in range(h):
            c = input()
            for k in range(w):
                battleTown[j][k] = c[k]

                if battleTown[j][k] in ['^', 'v', '<', '>']:
                    x = j
                    y = k

        bomberActNum = int(input())
        bomberAct = list(input())

        if 0 <= x <= h and 0 <= y <= w:
            for l in range(bomberActNum):
                if bomberAct[l] == 'U':
                    battleTown[x][y] = '^'
                    if x - 1 >= 0 and battleTown[x - 1][y] == '.':
                        battleTown[x - 1][y] = '^'
                        battleTown[x][y] = '.'
                        x -= 1
                if bomberAct[l] == 'D':
                    battleTown[x][y] = 'v'
                    if x + 1 < h and battleTown[x + 1][y] == '.':
                        battleTown[x + 1][y] = 'v'
                        battleTown[x][y] = '.'
                        x += 1
                if bomberAct[l] == 'L':
                    battleTown[x][y] = '<'
                    if y - 1 >= 0 and battleTown[x][y - 1] == '.':
                        battleTown[x][y - 1] = '<'
                        battleTown[x][y] = '.'
                        y -= 1
                if bomberAct[l] == 'R':
                    battleTown[x][y] = '>'
                    if y + 1 < w and battleTown[x][y + 1] == '.':
                        battleTown[x][y + 1] = '>'
                        battleTown[x][y] = '.'
                        y += 1
                if bomberAct[l] == 'S':
                    xOfBomber = x
                    yOfBomber = y
                    moveBomber(xOfBomber, yOfBomber)

            for s in range(h):
                for k in range(w):
                    print(battleTown[s][k], end="")
                print()

def moveBomber(a, b):
    if 0 <= a <= h and 0 <= b <= w:
        if battleTown[a][b] == '^':
            for i in range(a - 1, -1, -1):
                if battleTown[i][b] == '*':
                    battleTown[i][b] = '.'
                    return
                elif battleTown[i][b] == '#':
                    return
                else:
                    a -= 1
                    if a == 0:
                        return
        if battleTown[a][b] == 'v':
            for i in range(a + 1, h):
                if battleTown[i][b] == '*':
                    battleTown[i][b] = '.'
                    return
                elif battleTown[i][b] == '#':
                    return
                else:
                    a += 1
                    if a == h:
                        return
        if battleTown[a][b] == '<':
            for i in range(b - 1, -1, -1):
                if battleTown[a][i] == '*':
                    battleTown[a][i] = '.'
                    return
                elif battleTown[a][i] == '#':
                    return
                else:
                    b -= 1
                    if b == 0:
                        return
        if battleTown[a][b] == '>':
            for i in range(b + 1, w):
                if battleTown[a][i] == '*':
                    battleTown[a][i] = '.'
                    return
                elif battleTown[a][i] == '#':
                    return
                else:
                    b += 1
                    if b == w:
                        return

if __name__ == "__main__":
    main()
# End of Code
