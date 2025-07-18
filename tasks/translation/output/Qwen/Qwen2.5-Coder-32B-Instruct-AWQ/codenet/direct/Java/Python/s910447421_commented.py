import sys
import math

class Main:
    ans = 100
    balls = []
    N = 0
    taken = []

    @staticmethod
    def main():
        input = sys.stdin.read().split()
        index = 0
        Main.N = int(input[index])
        index += 1
        Main.ans = Main.N
        Main.balls = [[0, 0] for _ in range(Main.N)]
        for i in range(Main.N):
            Main.balls[i][0] = int(input[index])
            index += 1
            Main.balls[i][1] = int(input[index])
            index += 1
        Main.balls.sort(key=lambda x: x[0])
        Main.solve()
        for i in range(Main.N):
            x = Main.balls[i][0]
            y = Main.balls[i][1]
            Main.balls[i][0] = y
            Main.balls[i][1] = x
        Main.balls.sort(key=lambda x: x[0])
        Main.solve()
        print(Main.ans)

    @staticmethod
    def solve():
        for add in range(1, Main.N):
            Main.taken = [False] * Main.N
            p = Main.balls[add][0] - Main.balls[0][0]
            q = Main.balls[add][1] - Main.balls[0][1]  # Differences
            Main.ans = min(Main.ans, Main.check(p, q))

    @staticmethod
    def check(p, q):
        ret = 0
        while True:
            added = False
            start = 0
            x = -1
            y = -1  # Coordinates that we want next
            for i in range(Main.N):
                if not Main.taken[i]:
                    added = True
                    ret += 1
                    start = i
                    Main.taken[i] = True
                    x = Main.balls[i][0] + p
                    y = Main.balls[i][1] + q
                    break
            if not added:
                break
            for i in range(start + 1, Main.N):
                if Main.balls[i][0] == x and Main.balls[i][1] == y:
                    Main.taken[i] = True
                    x += p
                    y += q
        return ret

if __name__ == "__main__":
    Main.main()
# End of Code
