import sys

class Main:
    def __init__(self):
        pass

    def solve(self):
        import sys
        input = sys.stdin.read
        data = input().split()
        index = 0

        H = int(data[index])
        W = int(data[index + 1])
        index += 2

        c = [[0] * 10 for _ in range(10)]
        for i in range(10):
            for j in range(10):
                c[i][j] = int(data[index])
                index += 1

        min_cost = [c[i][1] for i in range(10)]
        for _ in range(10):
            for i in range(10):
                for j in range(10):
                    min_cost[i] = min(min_cost[i], c[i][j] + min_cost[j])

        ans = 0
        for h in range(1, H + 1):  # Adjusted to 1-based indexing
            for w in range(1, W + 1):  # Adjusted to 1-based indexing
                A = int(data[index])
                index += 1
                if A >= 0:
                    ans += min_cost[A]

        print(ans)

if __name__ == "__main__":
    main = Main()
    main.solve()
# End of Code
