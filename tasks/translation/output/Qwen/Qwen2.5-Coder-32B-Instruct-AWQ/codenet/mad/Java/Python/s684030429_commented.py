import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin

    def solve(self):
        a = self.ni()
        b = self.ni()
        print(max(0, a - 2 * b))

    def ni(self):
        return int(self.sc.readline().strip())

    def nl(self):
        return int(self.sc.readline().strip())

    def nf(self):
        return float(self.sc.readline().strip())

    def nd(self):
        return float(self.sc.readline().strip())

    def ns(self):
        return self.sc.readline().strip()

    def ia(self, n):
        return [self.ni() for _ in range(n)]

    def la(self, n):
        return [self.nl() for _ in range(n)]

    def fa(self, n):
        return [self.nf() for _ in range(n)]

    def da(self, n):
        return [self.nd() for _ in range(n)]

    def sa(self, n, empty=False):
        if empty:
            return [""] * n
        else:
            return [self.ns() for _ in range(n)]

    def ida(self, n, m):
        return [self.ia(m) for _ in range(n)]

    def lda(self, n, m):
        return [self.la(m) for _ in range(n)]

    def dda(self, n, m):
        return [self.da(m) for _ in range(n)]

    def stoi(self, s):
        return int(s)

    def stod(self, s):
        return float(s)

    def lmin(self, a):
        return min(a)

    def imin(self, a):
        return min(a)

    def lmax(self, a):
        return max(a)

    def imax(self, a):
        return max(a)

    def ibs(self, a, toFind):
        a.sort()
        min_index = 0
        max_index = len(a) - 1
        found = False

        while min_index <= max_index and not found:
            mid = min_index + (max_index - min_index) // 2
            if a[mid] == toFind:
                found = True
            elif toFind > a[mid]:
                min_index = mid + 1
            else:
                max_index = mid - 1

        return found

    def lbs(self, a, toFind):
        a.sort()
        min_index = 0
        max_index = len(a) - 1
        found = False

        while min_index <= max_index and not found:
            mid = min_index + (max_index - min_index) // 2
            if a[mid] == toFind:
                found = True
            elif toFind > a[mid]:
                min_index = mid + 1
            else:
                max_index = mid - 1

        return found

    def stb(self, s):
        return int(s, 2)

if __name__ == "__main__":
    main = Main()
    main.solve()
# End of Code
