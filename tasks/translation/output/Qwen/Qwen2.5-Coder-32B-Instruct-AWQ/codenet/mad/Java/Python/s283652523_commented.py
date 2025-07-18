import sys

MOD = int(1e9) + 7

class FastScanner:
    def __init__(self, file=sys.stdin):
        self.file = file
        self.buffer = []
        self.input = self.file.read()
        self.index = 0

    def close(self):
        if self.file != sys.stdin:
            self.file.close()

    def next(self):
        while self.index >= len(self.buffer):
            data = self.input[self.index:]
            if not data:
                break
            self.buffer.extend(data.split())
            self.index = 0
        if self.index >= len(self.buffer):
            return None
        result = self.buffer[self.index]
        self.index += 1
        return result

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextChar(self):
        return self.next()[0]

    def nextStr(self):
        return self.next()

    def nextLine(self):
        data = self.input[self.index:]
        newline_index = data.find('\n')
        if newline_index == -1:
            result = data
            self.index = len(self.input)
        else:
            result = data[:newline_index]
            self.index += newline_index + 1
        return result

    def nextIntArray(self, n):
        return [self.nextInt() for _ in range(n)]

    def nextLongArray(self, n):
        return [self.nextLong() for _ in range(n)]

    def nextDoubleArray(self, n):
        return [self.nextDouble() for _ in range(n)]

def solve():
    in_ = FastScanner()
    N = in_.nextInt()
    A = in_.nextIntArray(N)

    ans = 0
    sum_ = A[N - 1]
    for i in range(N - 2, -1, -1):
        ans += (sum_ * A[i]) % MOD
        ans %= MOD
        sum_ += A[i]
        sum_ %= MOD
    print(ans)

if __name__ == "__main__":
    solve()
# End of Code
