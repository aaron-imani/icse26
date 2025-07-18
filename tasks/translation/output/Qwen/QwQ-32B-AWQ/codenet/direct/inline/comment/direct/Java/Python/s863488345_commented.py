import sys

def main():
    input = sys.stdin.read().split()
    idx = 0
    map_num = int(input[idx]); idx +=1

    first = True

    for _ in range(map_num):
        h = int(input[idx]); idx +=1
        w = int(input[idx]); idx +=1

        grid = []
        for _ in range(h):
            line = input[idx]; idx +=1
            grid.append( list(line.strip()) )

        # Find tank's position and direction
        tank_x, tank_y = -1, -1
        for row in range(h):
            for col in range(w):
                c = grid[row][col]
                if c in {'^', 'v', '<', '>'}:
                    tank_x, tank_y = row, col
                    break
            if tank_x != -1:
                break

        # Read actions
        bomber_act_num = int(input[idx]); idx +=1
        actions = input[idx]; idx +=1

        for action in actions:
            if action == 'U':
                grid[tank_x][tank_y] = '^'
                new_x = tank_x -1
                new_y = tank_y
                if 0 <= new_x < h and 0 <= new_y < w and grid[new_x][new_y] == '.':
                    grid[tank_x][tank_y] = '.' 
                    tank_x = new_x
                    tank_y = new_y
                    grid[new_x][new_y] = '^'

            elif action == 'D':
                grid[tank_x][tank_y] = 'v'
                new_x = tank_x +1
                new_y = tank_y
                if 0 <= new_x < h and 0 <= new_y < w and grid[new_x][new_y] == '.':
                    grid[tank_x][tank_y] = '.' 
                    tank_x = new_x
                    tank_y = new_y
                    grid[new_x][new_y] = 'v'

            elif action == 'L':
                grid[tank_x][tank_y] = '<'
                new_x = tank_x 
                new_y = tank_y -1
                if 0 <= new_y < w and 0 <= new_x < h and grid[new_x][new_y] == '.' :
                    grid[tank_x][tank_y] = '.' 
                    tank_y = new_y
                    grid[new_x][new_y] = '<'

            elif action == 'R':
                grid[tank_x][tank_y] = '>'
                new_x = tank_x 
                new_y = tank_y +1
                if 0 <= new_y < w and 0 <= new_x < h and grid[new_x][new_y] == '.' :
                    grid[tank_x][tank_y] = '.' 
                    tank_y = new_y
                    grid[new_x][new_y] = '>'

            elif action == 'S':
                current_dir = grid[tank_x][tank_y]
                step_x, step_y = 0, 0
                if current_dir == '^':
                    step_x = -1
                    step_y = 0
                elif current_dir == 'v':
                    step_x = 1
                    step_y = 0
                elif current_dir == '<':
                    step_x = 0
                    step_y = -1
                elif current_dir == '>':
                    step_x = 0
                    step_y = 1

                current_shot_x = tank_x + step_x
                current_shot_y = tank_y + step_y

                while True:
                    if not (0 <= current_shot_x < h and 0 <= current_shot_y < w):
                        break
                    cell = grid[current_shot_x][current_shot_y]
                    if cell == '*':
                        grid[current_shot_x][current_shot_y] = '.'
                        break
                    elif cell == '#':
                        break
                    else:
                        current_shot_x += step_x
                        current_shot_y += step_y

        # Print the grid
        if not first:
            print()
        first = False
        for row in grid:
            print(''.join(row))

if __name__ == "__main__":
    main()  # End of Code
