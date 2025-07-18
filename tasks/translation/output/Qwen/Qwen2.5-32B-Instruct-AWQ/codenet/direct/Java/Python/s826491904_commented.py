import sys

class Main:
    def solve(self):
        N = int(input())
        max_val = min_val = int(input())
        for _ in range(1, N):
            num = int(input())
            max_val = max(max_val, num)
            min_val = min(min_val, num)
        print(max_val - min_val)

if __name__ == "__main__":
    main = Main()
    main.solve()  # End of Code
