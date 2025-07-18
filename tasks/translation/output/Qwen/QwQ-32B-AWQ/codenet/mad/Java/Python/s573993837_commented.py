import sys
class InputReader:
    def __init__(self):
        self.tokens = []
        self.position = 0
        self.tokens = sys.stdin.read().split()
    def next(self):
        if self.position >= len(self.tokens):
            raise EOFError()
        self.position +=1
        return self.tokens[self.position-1]
    def nextInt(self):
        return int(self.next())
    def nextLong(self):
        return int(self.next())
    def nextDouble(self):
        return float(self.next())
def solve(sc, pw):
    t = 1
    for _ in range(t):
        n = sc.nextLong()
        m = sc.nextLong()
        if n == 0:
            print(0, file=pw)
            continue
        if n == m:
            print(0, file=pw)
            continue
        if n > m:
            n %= m
        res = min(m - n, n)
        print(res, file=pw)
def main():
    sc = InputReader()
    solve(sc, sys.stdout)
if __name__ == "__main__":
    main()
#End of Code
