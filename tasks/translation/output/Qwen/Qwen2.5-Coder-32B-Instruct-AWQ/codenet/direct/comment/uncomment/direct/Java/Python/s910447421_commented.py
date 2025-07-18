import sys
import math

class Main:
    def __init__(self):
        self.ans = 100
        self.balls = []
        self.N = 0
        self.taken = []

    def main(self):
        input = sys.stdin.read().split()
        index = 0
        self.N = int(input[index])
        index += 1
        self.ans = self.N
        self.balls = [[0, 0] for _ in range(self.N)]
        for i in range(self.N):
            self.balls[i][0] = int(input[index])
            index += 1
            self.balls[i][1] = int(input[index])
            index += 1
        self.balls.sort(key=lambda x: x[0])
        self.solve()
        for i in range(self.N):
            x = self.balls[i][0]
            y = self.balls[i][1]
            self.balls[i][0] = y
            self.balls[i][1] = x
        self.balls.sort(key=lambda x: x[0])
        self.solve()
        print(self.ans)

    def solve(self):
        for add in range(1, self.N):
            self.taken = [False] * self.N
            p = self.balls[add][0] - self.balls[0][0]
            q = self.balls[add][1] - self.balls[0][1]
            self.ans = min(self.ans, self.check(p, q))

    def check(self, p, q):
        ret = 0
        while True:
            added = False
            start = 0
            x = -1
            y = -1
            for i in range(self.N):
                if not self.taken[i]:
                    added = True
                    ret += 1
                    start = i
                    self.taken[i] = True
                    x = self.balls[i][0] + p
                    y = self.balls[i][1] + q
                    break
            if not added:
                break
            for i in range(start + 1, self.N):
                if self.balls[i][0] == x and self.balls[i][1] == y:
                    self.taken[i] = True
                    x += p
                    y += q
        return ret

if __name__ == "__main__":
    main_instance = Main()
    main_instance.main()

# End of Code
