import sys

MOD = 10**9 + 7

class FastScanner:
    def __init__(self, stream=sys.stdin):
        self.input = stream

    def close(self):
        pass

    def next_int(self):
        return int(self.next_long())

    def next_long(self):
        try:
            sign = 1
            b = self.input.read(1)
            while b < '0' or b > '9':
                if b == '-':
                    sign = -1
                b = self.input.read(1)
            ret = int(b)
            while True:
                b = self.input.read(1)
                if b < '0' or b > '9':
                    return ret * sign
                ret = ret * 10 + int(b)
        except Exception:
            return -1

    def next_double(self):
        try:
            sign = 1
            b = self.input.read(1)
            while b < '0' or b > '9':
                if b == '-':
                    sign = -1
                b = self.input.read(1)
            ret = int(b)
            while True:
                b = self.input.read(1)
                if b < '0' or b > '9':
                    break
                ret = ret * 10 + int(b)
            if b != '.':
                return sign * ret
            div = 1
            b = self.input.read(1)
            while '0' <= b <= '9':
                ret = ret * 10 + int(b)
                div *= 10
                b = self.input.read(1)
            return sign * ret / div
        except Exception:
            return float('NaN')

    def next_char(self):
        try:
            b = self.input.read(1)
            while b.isspace():
                b = self.input.read(1)
            return b
        except Exception:
            return 0

    def next_str(self):
        try:
            b = self.input.read(1)
            while b.isspace():
                b = self.input.read(1)
            sb = []
            while b != '' and not b.isspace():
                sb.append(b)
                b = self.input.read(1)
            return ''.join(sb)
        except Exception:
            return ''

    def next_line(self):
        try:
            b = self.input.read(1)
            sb = []
            while b != '' and b != '\n':
                sb.append(b)
                b = self.input.read(1)
            return ''.join(sb)
        except Exception:
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
out_stream = sys.stdout

solve()

in_stream.close()
out_stream.close()
# End of Code
