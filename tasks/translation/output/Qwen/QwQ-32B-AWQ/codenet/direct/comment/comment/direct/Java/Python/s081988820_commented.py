import sys

class Main:
    def solve(self):
        data = list(map(int, sys.stdin.read().split()))
        idx = 0
        H = data[idx]; idx += 1
        W = data[idx]; idx += 1
        c = [[0]*10 for _ in range(10)]
        for i in range(10):
            for j in range(10):
                c[i][j] = data[idx]
                idx += 1
        min_ = [0]*10
        for i in range(10):
            min_[i] = c[i][1]
        for tc in range(10):
            for i in range(10):
                for j in range(10):
                    current = c[i][j] + min_[j]
                    if current < min_[i]:
                        min_[i] = current
        ans = 0
        for _ in range(H*W):
            A = data[idx]
            idx += 1
            if A >= 0:
                ans += min_[A]
        print(ans)

if __name__ == '__main__':
    main = Main()
    main.solve()
# End of Code
