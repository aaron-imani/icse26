import sys

class FastScanner:
    def __init__(self):
        self.tokens = []
        self.position = 0
        self.input = sys.stdin.read().split()
    def next(self):
        if self.position >= len(self.input):
            return None
        self.position += 1
        return self.input[self.position - 1]
    def nextInt(self):
        return int(self.next())

ans = 100
balls = []
N = 0

def solve():
    global ans, balls, N
    for add in range(1, N):
        p = balls[add][0] - balls[0][0]
        q = balls[add][1] - balls[0][1]
        taken = [False] * N
        ret = check(p, q, taken)
        if ret < ans:
            ans = ret

def check(p, q, taken):
    global balls, N
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

def main():
    global ans, balls, N
    scanner = FastScanner()
    N = scanner.nextInt()
    ans = N
    balls = []
    for _ in range(N):
        x = scanner.nextInt()
        y = scanner.nextInt()
        balls.append([x, y])
    balls.sort(key=lambda x: x[0])
    solve()
    # Swap x and y
    for i in range(N):
        balls[i][0], balls[i][1] = balls[i][1], balls[i][0]
    balls.sort(key=lambda x: x[0])
    solve()
    print(ans)

if __name__ == "__main__":
    main() # End of Code
