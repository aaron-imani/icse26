import sys

MOD = 10**9 + 7

class FastScanner:
    def __init__(self, stream=sys.stdin):
        self.stream = stream
        self.buffer = ''
    
    def next(self):
        while not self.buffer:
            self.buffer = self.stream.readline().strip()
        result, self.buffer = self.buffer.split(' ', 1) if ' ' in self.buffer else (self.buffer, '')
        return result
    
    def next_int(self):
        return int(self.next())
    
    def next_long(self):
        return int(self.next())
    
    def next_double(self):
        return float(self.next())
    
    def next_str(self):
        return self.next()
    
    def next_line(self):
        return self.stream.readline().strip()
    
    def next_int_array(self, n):
        return [self.next_int() for _ in range(n)]
    
    def next_long_array(self, n):
        return [self.next_long() for _ in range(n)]
    
    def next_double_array(self, n):
        return [self.next_double() for _ in range(n)]

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
