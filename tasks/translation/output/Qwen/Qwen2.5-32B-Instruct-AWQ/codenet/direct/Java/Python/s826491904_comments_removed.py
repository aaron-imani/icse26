import sys

class Main:
    def __init__(self):
        self.sc = Scanner()

    def solve(self):
        N = self.sc.nextInt()
        max_val = min_val = self.sc.nextInt()
        for i in range(1, N):
            in_val = self.sc.nextInt()
            max_val = max(max_val, in_val)
            min_val = min(min_val, in_val)
        print(max_val - min_val)

class Scanner:
    def __init__(self):
        self.tokens = iter(sys.stdin.read().split())

    def nextInt(self):
        return int(next(self.tokens))

if __name__ == "__main__":
    Main().solve()  # End of Code
