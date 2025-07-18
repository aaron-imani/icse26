import sys

class Solver:
    def solve(self, testNumber, in_stream, out_stream):
        ans = 0
        K = in_stream.nextInt()
        S = in_stream.nextInt()
        wk = 0
        for x in range(K + 1):
            for y in range(K + 1):
                wk = S - x - y
                if wk >= 0 and wk <= K:
                    ans += 1
        out_stream.println(ans)

class Pair:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def getString(self):
        return f"[{self.key}] [{self.value}]"

class MyInput:
    def __init__(self, is_stream):
        self.in_stream = is_stream
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
                self.read_len = self.in_stream.read(self.buffer)
            except Exception as e:
                raise EOFError()
            if self.read_len <= 0:
                raise EOFError()
        ch = self.buffer[self.pos]
        self.pos += 1
        return ch

    def nextInt(self):
        len = 0
        self.str[len] = self.nextChar()
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

    def nextLong(self):
        len = 0
        self.str[len] = self.nextChar()
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

    def nextString(self):
        ret = ''.join(self.nextDChar()).strip()
        return ret

    def nextDChar(self):
        len = 0
        len = self.reads(len, self.is_space)
        ret = [''] * (len + 1)
        for i in range(len):
            ret[i] = self.str[i]
        ret[len] = '\0'
        return ret

    def nextChar(self):
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
        except EOFError as e:
            pass
        return len

class PrintWriter:
    def __init__(self, out_stream):
        self.out_stream = out_stream

    def println(self, value):
        self.out_stream.write(str(value) + '\n')

def main():
    in_stream = MyInput(sys.stdin.buffer)
    out_stream = PrintWriter(sys.stdout)
    solver = Solver()
    solver.solve(1, in_stream, out_stream)
    out_stream.out_stream.flush()

if __name__ == "__main__":
    main()  # End of Code
