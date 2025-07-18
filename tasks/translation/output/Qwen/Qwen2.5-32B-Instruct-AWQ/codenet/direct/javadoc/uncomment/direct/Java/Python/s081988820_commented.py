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
            self.buffer = self.stream.readline().split()
        return self.buffer.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

def main():
    main_obj = Main()
    main_obj.solve()

if __name__ == "__main__":
    main()

# End of Code
