import sys

MOD = 10**9 + 7

class FastScanner:
    def __init__(self, stream=sys.stdin):
        self.input = stream

    def close(self):
        pass

    def next_int(self):
        try:
            return int(self.input.readline().strip())
        except Exception as e:
            print(e)
            return -1

    def next_double(self):
        try:
            return float(self.input.readline().strip())
        except Exception as e:
            print(e)
            return float('NaN')

    def next_str(self):
        try:
            return self.input.readline().strip()
        except Exception as e:
            print(e)
            return ''

    def next_int_array(self, n):
        return [self.next_int() for _ in range(n)]

def solve():
    N = in_stream.next_int()
    A = in_stream.next_int_array(N)
    
    ans = 0
    sum_val = A[N-1]
    for i in range(N-2, -1, -1):
        ans += (sum_val * A[i]) % MOD
        ans %= MOD
        sum_val += A[i]
        sum_val %= MOD
    print(ans)

in_stream = FastScanner(sys.stdin)
solve()
# End of Code
