import sys

def main():
    global ans
    N = int(sys.stdin.readline())
    balls = []
    for _ in range(N):
        x, y = map(int, sys.stdin.readline().split())
        balls.append([x, y])
    ans = N
    solve(balls, N)
    # Swap x and y for each ball
    for ball in balls:
        ball[0], ball[1] = ball[1], ball[0]
    balls.sort(key=lambda x: x[0])
    solve(balls, N)
    print(ans)

def solve(balls, N):
    global ans
    for add in range(1, N):
        p = balls[add][0] - balls[0][0]
        q = balls[add][1] - balls[0][1]
        current = check(p, q, balls, N)
        if current < ans:
            ans = current

def check(p, q, balls, N):
    taken = [False] * N
    ret = 0
    while True:
        added = False
        start = 0
        x, y = -1, -1
        for i in range(N):
            if not taken[i]:
                added = True
                ret += 1
                start = i
                taken[i] = True
                x = balls[i][0] + p
                y = balls[i][1] + q
                break
        if not added:
            break
        for i in range(start + 1, N):
            if balls[i][0] == x and balls[i][1] == y:
                taken[i] = True
                x += p
                y += q
    return ret

if __name__ == "__main__":
    ans = 0
    main()
# End of Code
