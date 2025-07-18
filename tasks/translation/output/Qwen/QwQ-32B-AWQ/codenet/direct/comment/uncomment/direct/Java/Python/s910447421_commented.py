import sys

ans = 0
balls = []
N = 0

def main():
    global ans, balls, N
    N = int(sys.stdin.readline())
    balls = []
    for _ in range(N):
        x, y = map(int, sys.stdin.readline().split())
        balls.append([x, y])
    balls.sort(key=lambda x: x[0])
    ans = N
    solve()
    swapped_balls = [[y, x] for x, y in balls]
    swapped_balls.sort(key=lambda x: x[0])
    balls = swapped_balls.copy()
    solve()
    print(ans)

def solve():
    global ans, balls, N
    for add in range(1, N):
        taken = [False] * N
        p = balls[add][0] - balls[0][0]
        q = balls[add][1] - balls[0][1]
        current = check(p, q, taken)
        if current < ans:
            ans = current

def check(p, q, taken):
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
                start = i
                taken[start] = True
                x = balls[start][0] + p
                y = balls[start][1] + q
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
    main() # End of Code
