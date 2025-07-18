MOD = 10**9 + 7

class FastScanner:
    def __init__(self, stream=None):
        if stream is None:
            self.stream = sys.stdin
        else:
            self.stream = stream

    def close(self):
        pass

    def next_int(self):
        return int(self.next_str())

    def next_long(self):
        return int(self.next_str())

    def next_double(self):
        return float(self.next_str())

    def next_char(self):
        return self.stream.read(1)

    def next_str(self):
        return self.stream.readline().strip()

    def next_line(self):
        return self.stream.readline().strip()

    def next_int_array(self, n):
        return [self.next_int() for _ in range(n)]

def solve(scanner, printer):
    N = scanner.next_int()
    A = scanner.next_int_array(N)

    ans = 0
    sum_ = A[N - 1]
    for i in range(N - 2, -1, -1):
        ans += (sum_ * A[i]) % MOD
        ans %= MOD
        sum_ += A[i]
        sum_ %= MOD
    printer.write(f"{ans}\n")

def main():
    import sys
    scanner = FastScanner()
    printer = sys.stdout
    solve(scanner, printer)
    printer.flush()

if __name__ == "__main__":
    main()  # End of Code
