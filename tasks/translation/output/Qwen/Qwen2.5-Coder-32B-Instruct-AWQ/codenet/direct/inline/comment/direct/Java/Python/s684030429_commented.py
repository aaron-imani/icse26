import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin

    def solve(self):
        a = self.ni()
        b = self.ni()

        print(max(0, a - 2 * b))

    def ni(self):
        return int(self.sc.readline())

# main method
if __name__ == "__main__":
    main_instance = Main()
    main_instance.solve()

# End of Code
