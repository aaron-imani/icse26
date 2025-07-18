import sys

class Solver:
    def solve(self, test_number, in_stream, out_stream):
        ans = 0
        K = in_stream.nextInt()
        S = in_stream.nextInt()
        for x in range(K + 1):
            for y in range(K + 1):
                wk = S - x - y
                if 0 <= wk <= K:
                    ans += 1
        out_stream.write(f"{ans}\n")

class MyInput:
    def __init__(self, input_stream):
        self.in_stream = input_stream
        self.buffer = []
        self.pos = 0

    def read(self):
        if self.pos >= len(self.buffer):
            self.buffer = self.in_stream.readline().strip()
            self.pos = 0
        if not self.buffer:
            raise EOFError("End of file reached")
        ch = self.buffer[self.pos]
        self.pos += 1
        return ch

    def next_int(self):
        num_str = ""
        while True:
            ch = self.read()
            if ch.isdigit() or ch == '-':
                num_str += ch
            else:
                break
        return int(num_str)

    def next_long(self):
        num_str = ""
        while True:
            ch = self.read()
            if ch.isdigit() or ch == '-':
                num_str += ch
            else:
                break
        return int(num_str)

    def next_string(self):
        string = ""
        while True:
            ch = self.read()
            if not ch.isspace():
                string += ch
            else:
                break
        return string.strip()

def main():
    in_stream = MyInput(sys.stdin)
    out_stream = sys.stdout
    solver = Solver()
    solver.solve(1, in_stream, out_stream)

if __name__ == "__main__":
    main()  # End of Code
