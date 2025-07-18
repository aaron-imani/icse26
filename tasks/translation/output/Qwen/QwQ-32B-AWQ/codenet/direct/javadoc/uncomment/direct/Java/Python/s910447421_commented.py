import sys

ans = 0
balls = []
N = 0

def main():
    global ans, balls, N
    data = list(map(int, sys.stdin.read().split()))
    idx = 0
    N = data[idx]
    idx += 1
    ans = N  # Initialize ans to N
    balls = []
    for _ in range(N):
        x = data[idx]
        y = data[idx+1]
        idx += 2
        balls.append((x, y))
    
    # First processing
    balls.sort(key=lambda x: x[0])
    solve()
    
    # Swap x and y, sort again
    new_balls = [(y, x) for (x, y) in balls]
    balls = new_balls
    balls.sort(key=lambda x: x[0])
    solve()
    
    print(ans)
    
def solve():
    global ans, balls, N
    for add in range(1, N):
        taken = [False] * N
        p = balls[add][0] - balls[0][0]
        q = balls[add][1] - balls[0][1]
        current_ret = check(p, q, taken)
        if current_ret < ans:
            ans = current_ret

def check(p, q, taken):
    global N, balls
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
        # Process the rest
        for i in range(start + 1, N):
            if balls[i][0] == x and balls[i][1] == y and not taken[i]:
                taken[i] = True
                x += p
                y += q
    return ret

if __name__ == "__main__":
    main()
# End of Code
