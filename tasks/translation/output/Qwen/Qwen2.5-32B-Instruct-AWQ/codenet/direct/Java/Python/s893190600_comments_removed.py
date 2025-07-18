import sys
from collections import defaultdict, deque

class Solver:
    def __init__(self, in_stream, out_stream):
        self.in_stream = in_stream
        self.out_stream = out_stream

    def solve(self):
        H = int(self.in_stream.readline())
        W = int(self.in_stream.readline())
        C = [['#'] * (W + 2) for _ in range(H + 2)]
        for i in range(1, H + 1):
            line = self.in_stream.readline().strip()
            for j in range(1, W + 1):
                C[i][j] = line[j - 1]
        
        if H == 1 and W == 1:
            self.out_stream.write("No\n")
            return
        
        for i in range(1, H + 1):
            for j in range(1, W + 1):
                if C[i][j] == '#' and C[i-1][j] != '#' and C[i+1][j] != '#' and C[i][j-1] != '#' and C[i][j+1] != '#':
                    self.out_stream.write("No\n")
                    return
        
        self.out_stream.write("Yes\n")

class MyInput:
    def __init__(self, in_stream):
        self.in_stream = in_stream
        self.pos = 0
        self.read_len = 0
        self.buffer = [''] * (1024 * 8)
        self.str = [''] * (500 * 8 * 2)
        self.is_digit = [False] * 256
        self.is_space = [False] * 256
        self.is_line_sep = [False] * 256

        for i in range(10):
            self.is_digit[ord('0') + i] = True
        self.is_digit[ord('-')] = True
        self.is_space[ord(' ')] = self.is_space[ord('\r')] = self.is_space[ord('\n')] = self.is_space[ord('\t')] = True
        self.is_line_sep[ord('\r')] = self.is_line_sep[ord('\n')] = True

    def read(self):
        if self.pos >= self.read_len:
            self.pos = 0
            try:
                self.read_len = self.in_stream.readinto(self.buffer)
            except Exception as e:
                raise RuntimeError(e)
            if self.read_len <= 0:
                raise EOFError()
        ch = self.buffer[self.pos]
        self.pos += 1
        return ch

    def next_int(self):
        len = 0
        self.str[len] = self.read()
        len = self.reads(len, self.is_space)
        i = 0
        ret = 0
        if self.str[0] == '-':
            i = 1
        for i in range(i, len):
            ret = ret * 10 + ord(self.str[i]) - ord('0')
        if self.str[0] == '-':
            ret = -ret
        return ret

    def next_long(self):
        len = 0
        self.str[len] = self.read()
        len = self.reads(len, self.is_space)
        i = 0
        ret = 0
        if self.str[0] == '-':
            i = 1
        for i in range(i, len):
            ret = ret * 10 + ord(self.str[i]) - ord('0')
        if self.str[0] == '-':
            ret = -ret
        return ret

    def next_double(self):
        len = 0
        self.str[len] = self.read()
        len = self.reads(len, self.is_space)
        i = 0
        ret = 0.0
        if self.str[0] == '-':
            i = 1
        cnt = 0
        for i in range(i, len):
            if self.str[i] == '.':
                cnt = 10
                continue
            if cnt == 0:
                ret = ret * 10 + ord(self.str[i]) - ord('0')
            else:
                ret = ret + (ord(self.str[i]) - ord('0')) / cnt
                cnt *= 10
        if self.str[0] == '-':
            ret = -ret
        return ret

    def next_string(self):
        ret = ''.join(self.next_dchar()).strip()
        return ret

    def next_dchar(self):
        len = 0
        len = self.reads(len, self.is_space)
        ret = [''] * (len + 1)
        for i in range(len):
            ret[i] = self.str[i]
        ret[len] = '\0'
        return ret

    def read_char(self):
        while True:
            c = self.read()
            if not self.is_space[ord(c)]:
                return c

    def reads(self, len, accept):
        try:
            while True:
                c = self.read()
                if accept[ord(c)]:
                    break
                if len == len(self.str):
                    self.str = [''] * (len(self.str) * 3 // 2)
                self.str[len] = c
                len += 1
        except EOFError:
            pass
        return len

def main():
    in_stream = sys.stdin
    out_stream = sys.stdout
    solver = Solver(in_stream, out_stream)
    solver.solve()

if __name__ == "__main__":
    main()

# End of Code
