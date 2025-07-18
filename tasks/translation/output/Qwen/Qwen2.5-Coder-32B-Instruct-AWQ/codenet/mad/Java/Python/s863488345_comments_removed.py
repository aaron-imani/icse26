import sys

def main():
    mapNum = int(input().strip())

    for i in range(mapNum):
        if 1 <= i < mapNum:
            print("")
        h, w = map(int, input().strip().split())
        battleTown = [list(input().strip()) for _ in range(h)]

        x, y = -1, -1
        for j in range(h):
            for k in range(w):
                if battleTown[j][k] in ['^', 'v', '<', '>']:
                    x, y = j, k

        bomberActNum = int(input().strip())
        bomberAct = input().strip()

        if 0 <= x < h and 0 <= y < w:
            for l in range(bomberActNum):
                if bomberAct[l] == 'U':
                    battleTown[x][y] = '^'
                    if x - 1 >= 0 and battleTown[x - 1][y] == '.':
                        battleTown[x - 1][y] = '^'
                        battleTown[x][y] = '.'
                        x -= 1
                elif bomberAct[l] == 'D':
                    battleTown[x][y] = 'v'
                    if x + 1 < h and battleTown[x + 1][y] == '.':
                        battleTown[x + 1][y] = 'v'
                        battleTown[x][y] = '.'
                        x += 1
                elif bomberAct[l] == 'L':
                    battleTown[x][y] = '<'
                    if y - 1 >= 0 and battleTown[x][y - 1] == '.':
                        battleTown[x][y - 1] = '<'
                        battleTown[x][y] = '.'
                        y -= 1
                elif bomberAct[l] == 'R':
                    battleTown[x][y] = '>'
                    if y + 1 < w and battleTown[x][y + 1] == '.':
                        battleTown[x][y + 1] = '>'
                        battleTown[x][y] = '.'
                        y += 1
                elif bomberAct[l] == 'S':
                    xOfBomber, yOfBomber = x, y
                    moveBomber(xOfBomber, yOfBomber, h, w, battleTown)

            for s in range(h):
                for k in range(w):
                    print(battleTown[s][k], end='')
                print()

def moveBomber(a, b, h, w, battleTown):
    if 0 <= a < h and 0 <= b < w:
        if battleTown[a][b] == '^':
            for i in range(a - 1, -1, -1):
                if battleTown[i][b] == '*':
                    battleTown[i][b] = '.'
                    return
                elif battleTown[i][b] == '#':
                    return
        elif battleTown[a][b] == 'v':
            for i in range(a + 1, h):
                if battleTown[i][b] == '*':
                    battleTown[i][b] = '.'
                    return
                elif battleTown[i][b] == '#':
                    return
        elif battleTown[a][b] == '<':
            for i in range(b - 1, -1, -1):
                if battleTown[a][i] == '*':
                    battleTown[a][i] = '.'
                    return
                elif battleTown[a][i] == '#':
                    return
        elif battleTown[a][b] == '>':
            for i in range(b + 1, w):
                if battleTown[a][i] == '*':
                    battleTown[a][i] = '.'
                    return
                elif battleTown[a][i] == '#':
                    return

if __name__ == "__main__":
    main()

# End of Code
