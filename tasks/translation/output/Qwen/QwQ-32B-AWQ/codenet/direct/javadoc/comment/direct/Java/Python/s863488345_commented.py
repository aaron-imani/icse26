import sys

def move_bomber(a, b, battleTown, h, w):
    direction = battleTown[a][b]
    if direction == '^':
        current_x = a - 1
        current_y = b
        while current_x >= 0:
            cell = battleTown[current_x][current_y]
            if cell == '*':
                battleTown[current_x][current_y] = '.'
                break
            elif cell == '#':
                break
            else:
                current_x -= 1
    elif direction == 'v':
        current_x = a + 1
        current_y = b
        while current_x < h:
            cell = battleTown[current_x][current_y]
            if cell == '*':
                battleTown[current_x][current_y] = '.'
                break
            elif cell == '#':
                break
            else:
                current_x += 1
    elif direction == '<':
        current_x = a
        current_y = b - 1
        while current_y >= 0:
            cell = battleTown[current_x][current_y]
            if cell == '*':
                battleTown[current_x][current_y] = '.'
                break
            elif cell == '#':
                break
            else:
                current_y -= 1
    elif direction == '>':
        current_x = a
        current_y = b + 1
        while current_y < w:
            cell = battleTown[current_x][current_y]
            if cell == '*':
                battleTown[current_x][current_y] = '.'
                break
            elif cell == '#':
                break
            else:
                current_y += 1

def main():
    mapNum = int(sys.stdin.readline())
    for _ in range(mapNum):
        if _ > 0:
            print()
        h, w = map(int, sys.stdin.readline().split())
        battleTown = []
        current_x, current_y = -1, -1
        for j in range(h):
            line = sys.stdin.readline().strip()
            row = list(line)
            battleTown.append(row)
            for k in range(w):
                if row[k] in {'^', 'v', '<', '>'}:
                    current_x, current_y = j, k
        bomberActNum = int(sys.stdin.readline())
        bomberAct = sys.stdin.readline().strip()
        for cmd in bomberAct:
            if cmd == 'U':
                new_x = current_x - 1
                new_y = current_y
                if 0 <= new_x < h and 0 <= new_y < w and battleTown[new_x][new_y] == '.':
                    battleTown[current_x][current_y] = '.'
                    current_x = new_x
                    current_y = new_y
                    battleTown[new_x][new_y] = '^'
                else:
                    battleTown[current_x][current_y] = '^'
            elif cmd == 'D':
                new_x = current_x + 1
                new_y = current_y
                if 0 <= new_x < h and 0 <= new_y < w and battleTown[new_x][new_y] == '.':
                    battleTown[current_x][current_y] = '.'
                    current_x = new_x
                    current_y = new_y
                    battleTown[new_x][new_y] = 'v'
                else:
                    battleTown[current_x][current_y] = 'v'
            elif cmd == 'L':
                new_x = current_x
                new_y = current_y - 1
                if 0 <= new_x < h and 0 <= new_y < w and battleTown[new_x][new_y] == '.':
                    battleTown[current_x][current_y] = '.'
                    current_y = new_y
                    battleTown[new_x][new_y] = '<'
                else:
                    battleTown[current_x][current_y] = '<'
            elif cmd == 'R':
                new_x = current_x
                new_y = current_y + 1
                if 0 <= new_x < h and 0 <= new_y < w and battleTown[new_x][new_y] == '.':
                    battleTown[current_x][current_y] = '.'
                    current_y = new_y
                    battleTown[new_x][new_y] = '>'
                else:
                    battleTown[current_x][current_y] = '>'
            elif cmd == 'S':
                move_bomber(current_x, current_y, battleTown, h, w)
        for row in battleTown:
            print(''.join(row))
if __name__ == "__main__":
    main() # End of Code
