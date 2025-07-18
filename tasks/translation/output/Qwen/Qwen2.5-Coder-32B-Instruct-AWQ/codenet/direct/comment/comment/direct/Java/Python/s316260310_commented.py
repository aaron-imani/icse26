import sys
import math

class Main:
    def __init__(self):
        self.solver = Solver()

    def run(self):
        try:
            self.solver.solve()
            sys.exit(0)
        except Exception as e:
            print(e, file=sys.stderr)
            sys.exit(1)

if __name__ == "__main__":
    main_instance = Main()
    main_instance.run()

class Solver:
    def __init__(self):
        self.hp = Helper(10**9 + 7, 1000006)
        self.TESTCASES = False

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

class Helper:
    def __init__(self, mod, maxn):
        self.MOD = mod
        self.MAXN = maxn
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

    def initIO(self, input_stream, output_stream):
        self.input_stream = input_stream
        self.output_stream = output_stream
        self.buffer = []
        self.buffer_index = 0

    def next(self):
        while not self.buffer or self.buffer_index == len(self.buffer):
            line = self.input_stream.readline().strip()
            if not line:
                return None
            self.buffer = line.split()
            self.buffer_index = 0
        result = self.buffer[self.buffer_index]
        self.buffer_index += 1
        return result

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

    def println(self, a):
        self.print(a)
        self.println()

    def flush(self):
        self.output_stream.flush()

# End of Code
