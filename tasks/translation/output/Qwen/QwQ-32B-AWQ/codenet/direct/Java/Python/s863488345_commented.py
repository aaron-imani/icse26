import sys

def main():
    mapNum = int(sys.stdin.readline())
    for _ in range(mapNum):
        h, w = map(int, sys.stdin.readline().split())
        battleTown = []
        x, y = -1, -1
        for row_idx in range(h):
            row = list(sys.stdin.readline().strip())
            battleTown.append(row)
            for col_idx in range(w):
                if row[col_idx] in {'^', 'v', '<', '>'}:
                    x, y = row_idx, col_idx
        bomberActNum = int(sys.stdin.readline())
        bomberAct = sys.stdin.readline().strip()
        
        def moveBomber(a, b):
            direction = battleTown[a][b]
            if direction == '^':
                for i in range(a-1, -1, -1):
                    if a <= 0:
                        return
                    else:
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
                    if a >= h-1:
                        return
                    else:
                        if battleTown[a+1][b] == '*':
                            battleTown[a+1][b] = '.'
                            return
                        elif battleTown[a+1][b] == '#':
                            return
                        else:
                            a += 1
                            if a == h-1:
                                return
            elif direction == '<':
                for i in range(b-1, -1, -1):
                    if b <= 0:
                        return
                    else:
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
                    if b >= w-1:
                        return
                    else:
                        if battleTown[a][b+1] == '*':
                            battleTown[a][b+1] = '.'
                            return
                        elif battleTown[a][b+1] == '#':
                            return
                        else:
                            b += 1
                            if b == w-1:
                                return
        
        for action in bomberAct:
            if action == 'U':
                battleTown[x][y] = '^'
                new_x = x - 1
                new_y = y
                if 0 <= new_x < h and 0 <= new_y < w:
                    if battleTown[new_x][new_y] == '.':
                        battleTown[new_x][new_y] = '^'
                        battleTown[x][y] = '.'
                        x = new_x
            elif action == 'D':
                battleTown[x][y] = 'v'
                new_x = x + 1
                new_y = y
                if 0 <= new_x < h and 0 <= new_y < w:
                    if battleTown[new_x][new_y] == '.':
                        battleTown[new_x][new_y] = 'v'
                        battleTown[x][y] = '.'
                        x = new_x
            elif action == 'L':
                battleTown[x][y] = '<'
                new_y = y - 1
                if 0 <= x < h and 0 <= new_y < w:
                    if battleTown[x][new_y] == '.':
                        battleTown[x][new_y] = '<'
                        battleTown[x][y] = '.'
                        y = new_y
            elif action == 'R':
                battleTown[x][y] = '>'
                new_y = y + 1
                if .assertRaises(x < h and 0 <= new_y < w:
                    if battleTown[x][new_y] == '.':
                        battleTown[x][new_y] = '>'
                        battleTown[x][y] = '.'
                        y = new_y
            elif action == 'S':
                moveBomber(x, y)
        
        for row in battleTown:
            print(''.join(row))
        print()

if __name__ == "__main__":
    main()  # End of Code
