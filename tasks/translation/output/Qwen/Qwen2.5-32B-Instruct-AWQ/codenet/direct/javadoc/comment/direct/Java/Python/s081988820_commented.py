import sys

class Main:
    def __init__(self):
        self.sc = Scanner(sys.stdin)

    def solve(self):
        H = self.sc.nextInt()
        W = self.sc.nextInt()
        c = [[0 for _ in range(10)] for _ in range(10)]
        for i in range(10):
            for j in range(10):
                c[i][j] = self.sc.nextInt()
        min_cost = [c[i][1] for i in range(10)]
        for _ in range(10):
            for i in range(10):
                for j in range(10):
                    min_cost[i] = min(min_cost[i], c[i][j] + min_cost[j])
        ans = 0
        for h in range(H):
            for w in range(W):
                A = self.sc.nextInt()
                if A >= 0:
                    ans += min_cost[A]
        print(ans)

class Scanner:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = []
        self.pos = 0

    def next(self):
        while not self.buffer:
            try:
                self.buffer = self.stream.readline().split()
            except EOFError:
                break
        self.pos = 0
        return self.buffer[self.pos]

    def nextInt(self):
        self.pos += 1
        return int(self.next())

    def nextLong(self):
        self.pos += 1
        return int(self.next())

    def nextDouble(self):
        self.pos += 1
        return float(self.next())

if __name__ == "__main__":
    main = Main()
    main.solve()  # End of Code
