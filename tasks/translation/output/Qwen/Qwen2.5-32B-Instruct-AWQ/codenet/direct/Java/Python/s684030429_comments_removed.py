import sys

class Main:
    def __init__(self):
        self.sc = Scanner()

    def solve(self):
        a = self.ni()
        b = self.ni()
        print(max(0, a - 2 * b))

class Scanner:
    def __init__(self):
        self.sc = sys.stdin

    def next_int(self):
        return int(self.sc.readline())

    def next_long(self):
        return int(self.sc.readline())

    def next_float(self):
        return float(self.sc.readline())

    def next_double(self):
        return float(self.sc.readline())

    def next_line(self):
        return self.sc.readline().strip()

    def next_string_tokenizer(self, s):
        return s.split()

def main():
    main_obj = Main()
    main_obj.solve()

if __name__ == "__main__":
    main()

# End of Code
