class InputReader:
    def __init__(self):
        import sys
        self.tokens = []
        self.token_ptr = 0
        for line in sys.stdin:
            self.tokens.extend(line.split())

    def next_int(self):
        if self.token_ptr >= len(self.tokens):
            raise EOFError("No more tokens.")
        token = self.tokens[self.token_ptr]
        self.token_ptr += 1
        return int(token)

    def next_line(self):
        import sys
        return sys.stdin.readline().rstrip()

class Main:
    def __init__(self):
        self.sc = InputReader()
        self.max = 0
        self.cur = 0

    def ni(self):
        return self.sc.next_int()

    def ns(self):
        return self.sc.next_line()

    def solve(self):
        a = self.ni()
        b = self.ni()
        print(max(0, a - 2 * b))

if __name__ == "__main__":
    main = Main()
    main.solve()
# End of Code
