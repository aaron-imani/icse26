MOD = 10**9 + 7

class FastScanner:
    def __init__(self, stream):
        self.input = stream

    def close(self):
        self.input.close()

    def next_int(self):
        return int(self.next_long())

    def next_long(self):
        sign = 1
        b = self.input.read(1)
        while b < '0' or b > '9':
            if b == '-':
                sign = -1
            b = self.input.read(1)
        ret = 0
        while b >= '0' and b <= '9':
            ret = ret * 10 + (ord(b) - ord('0'))
            b = self.input.read(1)
        return ret * sign

    def next_double(self):
        sign = 1
        b = self.input.read(1)
        while b < '0' or b > '9':
            if b == '-':
                sign = -1
            b = self.input.read(1)
        ret = 0
        while b >= '0' and b <= '9':
            ret = ret * 10 + (ord(b) - ord('0'))
            b = self.input.read(1)
        if b == '.':
            div = 1
            b = self.input.read(1)
            while b >= '0' and b <= '9':
                ret = ret * 10 + (ord(b) - ord('0'))
                div *= 10
                b = self.input.read(1)
            return sign * ret / div
        return sign * ret

    def next_char(self):
        b = self.input.read(1)
        while b.isspace():
            b = self.input.read(1)
        return b

    def next_str(self):
        b = self.input.read(1)
        while b.isspace():
            b = self.input.read(1)
        sb = []
        while b != -1 and not b.isspace():
            sb.append(b)
            b = self.input.read(1)
        return ''.join(sb)

    def next_line(self):
        sb = []
        b = self.input.read(1)
        while b != -1 and b != '\n':
            sb.append(b)
            b = self.input.read(1)
        return ''.join(sb)

    def next_int_array(self, n):
        return [self.next_int() for _ in range(n)]

def solve():
    N = in_stream.next_int()
    A = in_stream.next_int_array(N)
    ans, sum_ = 0, A[N - 1]
    for i in range(N - 2, -1, -1):
        ans += (sum_ * A[i]) % MOD
        ans %= MOD
        sum_ += A[i]
        sum_ %= MOD
    print(ans)

if __name__ == "__main__":
    in_stream = FastScanner(sys.stdin)
    solve()
    in_stream.close()
# End of Code
