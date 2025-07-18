import sys

def main():
    input = sys.stdin.read().split()
    index = 0
    mapNum = int(input[index])
    index += 1

    for _ in range(mapNum):
        if _ > 0:
            print("")
        h = int(input[index])
        w = int(input[index + 1])
        index += 2

        battleTown = []
        for _ in range(h):
            row = list(input[index])
            index += 1
            battleTown.append(row)

        x, y = -1, -1
        for i in range(h):
            for j in range(w):
                if battleTown[i][j] in ['^', 'v', '<', '>']:
                    x, y = i, j

        bomberActNum = int(input[index])
        bomberAct = list(input[index + 1])
        index += 2

        if 0 <= x < h and 0 <= y < w:
            for action in bomberAct:
                if action == 'U':
                    battleTown[x][y] = '^'
                    if x - 1 >= 0 and battleTown[x - 1][y] == '.':
                        battleTown[x - 1][y] = '^'
                        battleTown[x][y] = '.'
                        x -= 1
                elif action == 'D':
                    battleTown[x][y] = 'v'
                    if x + 1 < h and battleTown[x + 1][y] == '.':
                        battleTown[x + 1][y] = 'v'
                        battleTown[x][y] = '.'
                        x += 1
                elif action == 'L':
                    battleTown[x][y] = '<'
                    if y - 1 >= 0 and battleTown[x][y - 1] == '.':
                        battleTown[x][y - 1] = '<'
                        battleTown[x][y] = '.'
                        y -= 1
                elif action == 'R':
                    battleTown[x][y] = '>'
                    if y + 1 < w and battleTown[x][y + 1] == '.':
                        battleTown[x][y + 1] = '>'
                        battleTown[x][y] = '.'
                        y += 1
                elif action == 'S':
                    xOfBomber, yOfBomber = x, y
                    moveBomber(battleTown, xOfBomber, yOfBomber, h, w)

            for row in battleTown:
                print(''.join(row))

def moveBomber(battleTown, a, b, h, w):
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
            for j in range(b - 1, -1, -1):
                if battleTown[a][j] == '*':
                    battleTown[a][j] = '.'
                    return
                elif battleTown[a][j] == '#':
                    return
        elif battleTown[a][b] == '>':
            for j in range(b + 1, w):
                if battleTown[a][j] == '*':
                    battleTown[a][j] = '.'
                    return
                elif battleTown[a][j] == '#':
                    return

# End of Code
