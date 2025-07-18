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

class FastScanner:
    def __init__(self, input_stream):
        self.input = input_stream

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
        return self.input.readline().strip()

    def nextIntArray(self, n):
        return [self.nextInt() for _ in range(n)]

if __name__ == "__main__":
    main = Main()
    main.solve()

# End of Code
