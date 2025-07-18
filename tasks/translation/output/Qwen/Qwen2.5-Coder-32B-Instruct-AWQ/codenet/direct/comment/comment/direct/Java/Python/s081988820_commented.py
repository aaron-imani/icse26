import sys

class Main:
    def __init__(self):
        self.input = sys.stdin.read().split()
        self.index = 0

    def next(self):
        result = self.input[self.index]
        self.index += 1
        return result

    def next_int(self):
        return int(self.next())

    def solve(self):
        H = self.next_int()
        W = self.next_int()
        c = [[self.next_int() for _ in range(10)] for _ in range(10)]
        min_cost = [c[i][1] for i in range(10)]
        for _ in range(10):
            for i in range(10):
                for j in range(10):
                    min_cost[i] = min(min_cost[i], c[i][j] + min_cost[j])
        ans = 0
        for _ in range(H * W):
            A = self.next_int()
            if A >= 0:
                ans += min_cost[A]
        print(ans)

if __name__ == "__main__":
    main = Main()
    main.solve()

# End of Code
