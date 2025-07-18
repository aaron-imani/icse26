import sys

def check(p, q, balls, taken):
    N = len(balls)
    ret = 0
    while True:
        added = False
        start = 0
        x = -1
        y = -1
        for i in range(N):
            if not taken[i]:
                added = True
                ret += 1
                taken[i] = True
                start = i
                x = balls[i][0] + p
                y = balls[i][1] + q
                break
        if not added:
            break
        current_x = x
        current_y = y
        for i in range(start + 1, N):
            if balls[i][0] == current_x and balls[i][1] == current_y:
                taken[i] = True
                current_x += p
                current_y += q
    return ret

def solve():
    global ans, N, balls
    for add in range(1, N):
        taken = [False] * N
        p = balls[add][0] - balls[0][0]
        q = balls[add][1] - balls[0][1]
        current_ret = check(p, q, balls, taken)
        if current_ret < ans:
            ans = current_ret

def main():
    global ans, N, balls
    N = int(sys.stdin.readline())
    balls = []
    for _ in range(N):
        x, y = map(int, sys.stdin.readline().split())
        balls.append([x, y])
    ans = N
    balls.sort(key=lambda x: x[0])
    solve()
    for i in range(N):
        balls[i][0], balls[i][1] = balls[i][1], balls[i][0]
    balls.sort(key=lambda x: x[0])
    solve()
    print(ans)

if __name__ == "__main__":
    main()
# End of Code
