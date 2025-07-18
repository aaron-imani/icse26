import sys
import math

class Solver:
    def __init__(self):
        self.hp = Helper()
        self.MAXN = 1000006
        self.MOD = 10**9 + 7

    def solve(self):
        tc = self.hp.nextInt() if self.TESTCASES else 1
        for tce in range(1, tc + 1):
            self.solve_case(tce)

    def solve_case(self, tc):
        N = self.hp.nextInt()
        K = self.hp.nextLong()
        A = self.hp.getIntArray(N)

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
            self.hp.println(cycle[int(K % len(cycle))] + 1)

    TESTCASES = False


class Helper:
    def __init__(self):
        self.MOD = 10**9 + 7
        self.MAXN = 1000006
        self.rnd = random.Random()

    def getLongArray(self, size):
        return [self.nextLong() for _ in range(size)]

    def getIntArray(self, size):
        return [self.nextInt() for _ in range(size)]

    def getStringArray(self, size):
        return [self.next() for _ in range(size)]

    def joinElements(self, *ar):
        return ' '.join(map(str, ar))

    def gcd(self, a, b):
        return a if b == 0 else self.gcd(b, a % b)

    def max(self, *ar):
        return max(ar)

    def min(self, *ar):
        return min(ar)

    def sum(self, *ar):
        return sum(ar)

    def shuffle(self, ar):
        random.shuffle(ar)

    def reverse(self, ar):
        ar.reverse()

    def pow(self, base, exp, MOD):
        base %= MOD
        ret = 1
        while exp > 0:
            if exp & 1:
                ret = ret * base % MOD
            base = base * base % MOD
            exp >>= 1
        return ret

    def initIO(self, input_stream=sys.stdin, output_stream=sys.stdout):
        self.input_stream = input_stream
        self.output_stream = output_stream
        self.buffer = []
        self.buffer_index = 0

    def next(self):
        while not self.buffer:
            line = self.input_stream.readline().strip()
            if not line:
                break
            self.buffer.extend(line.split())
        if not self.buffer:
            return None
        return self.buffer.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def print(self, a):
        self.output_stream.write(str(a))

    def printsp(self, a):
        self.print(a)
        self.print(' ')

    def println(self):
        self.output_stream.write('\n')

    def flush(self):
        self.output_stream.flush()


if __name__ == "__main__":
    solver = Solver()
    solver.solve()
# End of Code
