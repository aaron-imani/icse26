import sys

def main():
    mapNum = int(sys.stdin.readline().strip())
    for i in range(mapNum):
        if i != 0:
            print()
        h, w = map(int, sys.stdin.readline().split())
        battleTown = []
        x = -1
        y = -1
        for j in range(h):
            line = sys.stdin.readline().strip()
            row = list(line)
            battleTown.append(row)
            for k in range(w):
                c = row[k]
                if c in ['^', 'v', '<', '>']:
                    x = j
                    y = k
        bomberActNum = int(sys.stdin.readline().strip())
        bomberAct = sys.stdin.readline().strip()
        current_x, current_y = x, y
        for action in bomberAct:
            if action == 'U':
                battleTown[current_x][current_y] = '^'
                if current_x - 1 >= 0 and battleTown[current_x-1][current_y] == '.':
                    battleTown[current_x-1][current_y] = '^'
                    battleTown[current_x][current_y] = '.'
                    current_x -= 1
            elif action == 'D':
                battleTown[current_x][current_y] = 'v'
                if current_x + 1 < h and battleTown[current_x+1][current_y] == '.':
                    battleTown[current_x+1][current_y] = 'v'
                    battleTown[current_x][current_y] = '.'
                    current_x += 1
            elif action == 'L':
                battleTown[current_x][current_y] = '<'
                if current_y - 1 >= 0 and battleTown[current_x][current_y-1] == '.':
                    battleTown[current_x][current_y-1] = '<'
                    battleTown[current_x][current_y] = '.'
                    current_y -= 1
            elif action == 'R':
                battleTown[current_x][current_y] = '>'
                if current_y + 1 < w and battleTown[current_x][current_y+1] == '.':
                    battleTown[current_x][current_y+1] = '>'
                    battleTown[current_x][current_y] = '.'
                    current_y += 1
            elif action == 'S':
                a = current_x
                b = current_y
                move_bomber(a, b, battleTown, h, w)
        for row in battleTown:
            print(''.join(row))

def move_bomber(a, b, battleTown, h, w):
    if not (0 <= a <= h and 0 <= b <= w):
        return
    direction = battleTown[a][b]
    if direction == '^':
        for i in range(a-1, -1, -1):
            if a <= 0:
                return
            if battleTown[a-1][b] == '*':
                battleTown[a-1][b] = '.'
                return
            elif battleTown[a-1][b] == '#':
                return
            else:
                a -= 1
                if a == 0:
                    return
    elif direction == 'v':
        for i in range(a+1, h):
            if battleTown[a+1][b] == '*':
                battleTown[a+1][b] = '.'
                return
            elif battleTown[a+1][b] == '#':
                return
            else:
                a += 1
                if a == h:
                    return
    elif direction == '<':
        for i in range(b-1, -1, -1):
            if battleTown[a][b-1] == '*':
                battleTown[a][b-1] = '.'
                return
            elif battleTown[a][b-1] == '#':
                return
            else:
                b -= 1
                if b == 0:
                    return
    elif direction == '>':
        for i in range(b+1, w):
            if battleTown[a][b+1] == '*':
                battleTown[a][b+1] = '.'
                return
            elif battleTown[a][b+1] == '#':
                return
            else:
                b += 1
                if b == w:
                    return

if __name__ == "__main__":
    main()  # End of Code
