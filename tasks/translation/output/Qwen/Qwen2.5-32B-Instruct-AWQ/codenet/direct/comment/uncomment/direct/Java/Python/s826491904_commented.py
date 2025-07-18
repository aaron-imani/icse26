import sys

class Main:
    def __init__(self):
        self.sc = Scanner()

    def solve(self):
        N = int(input())
        max_val = min_val = int(input())
        for _ in range(1, N):
            in_val = int(input())
            max_val = max(max_val, in_val)
            min_val = min(min_val, in_val)
        print(max_val - min_val)

class Scanner:
    def nextInt(self):
        return int(input())

if __name__ == "__main__":
    main = Main()
    main.solve()  # End of Code
