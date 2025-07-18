import sys

def main():
    global ans, balls, N
    N = int(sys.stdin.readline())
    balls = []
    for _ in range(N):
        x, y = map(int, sys.stdin.readline().split())
        balls.append([x, y])
    ans = N
    solve()
    # Swap coordinates and re-sort
    for i in range(N):
        x, y = balls[i]
        balls[i] = [y, x]
    balls.sort(key=lambda a: a[0])
    solve()
    print(ans)

def solve():
    global ans, balls, N
    for add in range(1, N):
        p = balls[add][0] - balls[0][0]
        q = balls[add][1] - balls[0][1]
        current = check(p, q)
        if current < ans:
            ans = current

def check(p, q):
    global N, balls
    taken = [False] * N
    ret = 0
    while True:
        added = False
        start = AZY = -1
        x = -1
        y = -1
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
    main() # End of Code
