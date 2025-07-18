import sys

MOD = 10**9 + 7

class FastScanner:
    def __init__(self, stream=sys.stdin):
        self.stream = stream
        self.buffer = ''
        self.tokens = []
    
    def read_line(self):
        line = self.stream.readline()
        self.tokens = line.split()
        self.buffer = ""
    
    def next_int(self):
        if not self.tokens:
            self.read_line()
        token = self.tokens.pop(0)
        return int(token)
    
    def next_long(self):
        if not self.tokens:
            self.read_line()
        token = self.tokens.pop(0)
        return int(token)
    
    def next_double(self):
        if not self.tokens:
            self.read_line()
        token = self.tokens.pop(0)
        return float(token)
    
    def next_str(self):
        if not self.tokens:
            self.read_line()
        token = self.tokens.pop(0)
        return token
    
    def next_int_array(self, n):
        return [self.next_int() for _ in range(n)]
    
def solve():
    scanner = FastScanner()
    N = scanner.next_int()
    A = scanner.next_int_array(N)
    
    ans = 0
    sum_val = A[N-1]
    for i in range(N-2, -1, -1):
        ans += (sum_val * A[i]) % MOD
        ans %= MOD
        sum_val += A[i]
        sum_val %= MOD
    print(ans)

if __name__ == "__main__":
    solve()  # End of Code
