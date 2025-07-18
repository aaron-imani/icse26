import sys

ans = 0
balls = []
N = 0

def main():
    global ans, balls, N
    N = int(sys.stdin.readline())
    ans = N
    balls = []
    for _ in range(N):
        x, y = map(int, sys.stdin.readline().split())
        balls.append([x, y])
    
    balls.sort(key=lambda x: x[0])
    solve()
    
    # Swap x and y for each ball
    for i in range(N):
        balls[i][0], balls[i][1] = balls[i][1], balls[i][0]
    balls.sort(key=lambda x: x[0])
    solve()
    
    print(ans)

def solve():
    global ans, balls, N
    for add in range(1, N):
        p = balls[add][0] - balls[0][0]
        q = balls[add][1] - balls[0][1]
        taken = [False] * N
        current_ret = check(p, q, taken)
        ans = min(ans, current_ret)

def check(p, q, taken):
    global balls, N
    ret = 0
    while True:
        added = False
        start = 0
        x = -1
        y = -1
        # Find first not taken point
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
        # Now go through the rest of the balls from start+1 to end
        for i in range(start + 1, N):
            if not taken[i] and balls[i][0] == x and balls[i][1] == y:
                taken[i] = True
                x += p
                y += q
    return ret

if __name__ == "__main__":
    main()
# End of Code
