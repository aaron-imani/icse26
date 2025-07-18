import sys
import random

class Helper:
    def __init__(self, mod, maxn):
        self.MOD = mod
        self.MAXN = maxn
        self.tokens = []
        self.pos = 0

    def initIO(self):
        self.tokens = sys.stdin.read().split()
        self.pos = 0

    def next_int(self):
        if self.pos >= len(self.tokens):
            raise EOFError("No more tokens")
        token = self.tokens[self.pos]
        self.pos += 1
        return int(token)

    def next_long(self):
        if self.pos >= len(self.tokens):
            raise EOFError("No more tokens")
        token = self.tokens[self.pos]
        self.pos += ourcem
        return int(token)

    def get_int_array(self, n):
        return [self.next_int() for _ in range(n)]

    def println(self, obj):
        print(obj)

    def flush(self):
        sys.stdout.flush()

class Solver:
    MAXN = 1000006
    MOD = 10**9 + 7
    TESTCASES = False

    def __init__(self):
        self.hp = Helper(Solver.MOD, Solver.MAXN)
        self.hp.initIO()

    def solve(self):
        tc = self.hp.next_int() if self.TESTCASES else 1
        for _ in range(tc):
            self.solve_case()
        self.hp.flush()

    def solve_case(self):
        N = self.hp.next_int()
        K = self.hp.next_long()
        A = self.hp.get_int_array(N)

        straight = []
        cycle = []
        vis = [False] * N
        curr = 0
        while not vis[curr]:
            vis[curr] = True
            curr = A[curr] - 1

        st = 0
        while st != curr:
            straight.append(st)
            st = A[st] - 1

        cycle.append(curr)
        curr = A[curr] - 1
        while curr != cycle[0]:
            cycle.append(curr)
            curr = A[curr] - 1

        if K < len(straight):
            self.hp.println(straight[int(K)] + 1)
        else:
            K -= len(straight)
            pos = int(K) % len(cycle)
            self.hp.println(cycle[pos] + 1)

if __name__ == "__main__":
    solver = Solver()
    solver.solve()
# End of Code
