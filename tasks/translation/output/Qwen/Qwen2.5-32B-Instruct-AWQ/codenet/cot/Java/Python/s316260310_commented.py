import sys
import threading

class Main:
    def run(self):
        try:
            Solver().solve()
            sys.exit(0)
        except Exception as e:
            print(e)
            sys.exit(1)

    def main(self):
        #thread = threading.Thread(target=self.run)
        #thread.start()
        self.run()

class Solver:
    def __init__(self):
        self.hp = Helper()
        self.hp.init_io(sys.stdin, sys.stdout)
        self.MAXN = 1000_006
        self.MOD = 10**9 + 7

    def solve(self):
        tc = 1 if not self.TESTCASES else self.hp.next_int()
        for tce in range(1, tc + 1):
            self.solve(tce)
        self.hp.flush()

    def solve(self, tc):
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
            self.hp.println(cycle[int(K % len(cycle))] + 1)

class Helper:
    def __init__(self):
        self.MOD = 10**9 + 7
        self.MAXN = 1000_006
        self.rnd = random.Random()

    def init_io(self, stdin, stdout):
        self.stdin = stdin
        self.stdout = stdout

    def next_int(self):
        return int(self.stdin.readline().strip())

    def next_long(self):
        return int(self.stdin.readline().strip())

    def get_int_array(self, size):
        return [self.next_int() for _ in range(size)]

    def println(self, value):
        self.stdout.write(str(value) + "\n")

    def flush(self):
        self.stdout.flush()

if __name__ == "__main__":
    Main().main()
# End of Code
