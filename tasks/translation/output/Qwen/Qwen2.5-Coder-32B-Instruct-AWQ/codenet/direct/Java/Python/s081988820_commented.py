import sys
import math
from collections import defaultdict

class Main:
    def __init__(self):
        pass

    def solve(self):
        import sys
        input = sys.stdin.read
        data = input().split()
        index = 0

        H = int(data[index])
        W = int(data[index + 1])
        index += 2

        c = [[0] * 10 for _ in range(10)]
        for i in range(10):
            for j in range(10):
                c[i][j] = int(data[index])
                index += 1

        min_cost = [c[i][1] for i in range(10)]
        for tc in range(10):
            for i in range(10):
                for j in range(10):
                    min_cost[i] = min(min_cost[i], c[i][j] + min_cost[j])

        ans = 0
        for h in range(H):
            for w in range(W):
                A = int(data[index])
                index += 1
                if A >= 0:
                    ans += min_cost[A]

        print(ans)

class Scanner:
    def __init__(self, input):
        self.input = input
        self.index = 0

    def hasNext(self):
        return self.index < len(self.input)

    def next(self):
        while self.hasNext() and self.input[self.index].isspace():
            self.index += 1
        if not self.hasNext():
            return None
        start = self.index
        while self.hasNext() and not self.input[self.index].isspace():
            self.index += 1
        return self.input[start:self.index]

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

# End of Code
