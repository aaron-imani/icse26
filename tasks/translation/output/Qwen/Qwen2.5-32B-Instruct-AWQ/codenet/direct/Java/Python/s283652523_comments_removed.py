import sys

class Main:
    def __init__(self):
        self.inp = FastScanner(sys.stdin)
        self.out = sys.stdout

    def solve(self):
        N = self.inp.nextInt()
        A = self.inp.nextIntArray(N)
        
        ans = 0
        MOD = 10**9 + 7
        sum_val = A[N-1]
        for i in range(N-2, -1, -1):
            ans += (sum_val * A[i]) % MOD
            ans %= MOD
            sum_val += A[i]
            sum_val %= MOD
        self.out.write(f"{ans}\n")

    def m(self):
        self.solve()
        self.out.flush()

class FastScanner:
    def __init__(self, stream):
        self.input = stream

    def close(self):
        pass

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextChar(self):
        return self.input.read(1)

    def nextStr(self):
        return self.next()

    def nextLine(self):
        return self.input.readline().strip()

    def next(self):
        while True:
            buffer = self.input.readline()
            if buffer:
                tokens = buffer.split()
                for token in tokens:
                    yield token
            else:
                return

    def nextIntArray(self, n):
        return [self.nextInt() for _ in range(n)]

    def nextIntArrayDec(self, n):
        return [self.nextInt() - 1 for _ in range(n)]

    def nextIntArray1Index(self, n):
        return [0] + [self.nextInt() for _ in range(n)]

    def nextLongArray(self, n):
        return [self.nextLong() for _ in range(n)]

    def nextLongArrayDec(self, n):
        return [self.nextLong() - 1 for _ in range(n)]

    def nextLongArray1Index(self, n):
        return [0] + [self.nextLong() for _ in range(n)]

    def nextDoubleArray(self, n):
        return [self.nextDouble() for _ in range(n)]

if __name__ == "__main__":
    main = Main()
    main.m()  # End of Code
