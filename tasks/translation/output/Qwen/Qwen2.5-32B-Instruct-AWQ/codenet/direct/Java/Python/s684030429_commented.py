import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin
        self.max = 0
        self.cur = 0

    def solve(self):
        a = self.ni()
        b = self.ni()
        print(max(0, a - 2 * b))

    def ni(self):
        return int(self.sc.readline())

    def nl(self):
        return int(self.sc.readline())

    def nf(self):
        return float(self.sc.readline())

    def nd(self):
        return float(self.sc.readline())

    def ns(self):
        return self.sc.readline().strip()

    def nst(self, s):
        return s.split()

    def ia(self, a):
        for i in range(len(a)):
            a[i] = self.ni()

    def la(self, a):
        for i in range(len(a)):
            a[i] = self.nl()

    def fa(self, a):
        for i in range(len(a)):
            a[i] = self.nf()

    def da(self, a):
        for i in range(len(a)):
            a[i] = self.nd()

    def sa(self, a, empty):
        if empty:
            for i in range(len(a)):
                a[i] = ""
        else:
            for i in range(len(a)):
                a[i] = self.ns()

    def ida(self, a, n, m):
        for i in range(n):
            for j in range(m):
                a[i][j] = self.ni()

    def lda(self, a, n, m):
        for i in range(n):
            for j in range(m):
                a[i][j] = self.nl()

    def dda(self, a, n, m):
        for i in range(n):
            for j in range(m):
                a[i][j] = self.nd()

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
        return toFind in a

    def lbs(self, a, toFind):
        a.sort()
        return toFind in a

    def stb(self, s):
        return int(s, 2)

if __name__ == "__main__":
    Main().solve()

# End of Code
