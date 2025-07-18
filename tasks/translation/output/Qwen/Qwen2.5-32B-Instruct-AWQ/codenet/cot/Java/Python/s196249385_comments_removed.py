from typing import List

class Main:
    sc = None
    pr = None

    @staticmethod
    def solve():
        n = Main.sc.nextInt()
        k = Main.sc.nextInt()

        a = [0] * n
        for i in range(n):
            a[i] = Main.sc.nextInt()

        cumsum = [0] * (n + 1)
        for i in range(n):
            cumsum[i + 1] = cumsum[i] + a[i]

        b = []
        max_val = 0
        for i in range(n):
            for j in range(i, n):
                b.append(cumsum[j + 1] - cumsum[i])
                max_val = max(max_val, cumsum[j + 1] - cumsum[i])

        mask = 1 << (max_val.bit_length() - 1)
        while mask > 0:
            tmp = [e for e in b if (e & mask) != 0]
            if len(tmp) >= k:
                b = tmp
            mask >>= 1

        if len(b) < k:
            Main.pr.println(0)
        else:
            ans = -1
            for e in b:
                ans &= e
            Main.pr.println(ans)

    @staticmethod
    def main():
        Main.sc = Scanner()
        Main.pr = Printer()
        Main.solve()
        Main.pr.close()
        Main.sc.close()

class Scanner:
    def __init__(self):
        self.input = input

    def nextInt(self):
        return int(self.input())

class Printer:
    def __init__(self):
        self.output = print

    def println(self, value):
        self.output(value)

    def close(self):
        pass

Main.main()
# End of Code
