import sys

class Solver:
    def solve(self, testNumber):
        ans = 0
        K = int(input())
        S = int(input())
        wk = 0
        for x in range(K + 1):
            for y in range(K + 1):
                wk = S - x - y
                if 0 <= wk <= K:
                    ans += 1
        print(ans)


class MyInput:
    def __init__(self, inputStream):
        self.in_stream = inputStream
        self.pos = 0
        self.read_len = 0
        self.buffer = [0] * (1024 * 8)
        self.str = [0] * (500 * 8 * 2)
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
                raise Exception("Error reading from input stream")
            if self.read_len <= 0:
                raise EOFError("End of file reached")
        return self.buffer[self.pos]

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

    def next_string(self):
        ret = ''.join(chr(c) for c in self.next_dchar()).strip()
        return ret

    def next_dchar(self):
        len = 0
        len = self.reads(len, self.is_space)
        ret = [0] * (len + 1)
        for i in range(len):
            ret[i] = self.str[i]
        ret[len] = 0x00
        return ret

    def next_char(self):
        while True:
            c = self.read()
            if not self.is_space[c]:
                return chr(c)

    def reads(self, len, accept):
        try:
            while True:
                c = self.read()
                if accept[c]:
                    break
                if len == len(self.str):
                    self.str = [0] * (len(self.str) * 3 // 2)
                self.str[len] = c
                len += 1
        except EOFError:
            pass
        return len


def main():
    in_stream = sys.stdin
    out_stream = sys.stdout
    my_input = MyInput(in_stream)
    out = out_stream

    solver = Solver()
    solver.solve(1)

    out.flush()


if __name__ == "__main__":
    main()
# End of Code
