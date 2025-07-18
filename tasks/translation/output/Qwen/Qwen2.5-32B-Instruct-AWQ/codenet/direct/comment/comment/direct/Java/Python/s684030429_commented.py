# Python translation of the provided Java code

class Main:
    def __init__(self):
        self.sc = None
        self.max = 0
        self.cur = 0

    def solve(self):
        a = self.ni()
        b = self.ni()

        print(max(0, a - 2 * b))

    # Utility methods
    def ni(self):
        return int(input())

    def nl(self):
        return int(input())

    def nf(self):
        return float(input())

    def nd(self):
        return float(input())

    def ns(self):
        return input()

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

    def ibs(self, a, to_find):
        a.sort()
        return to_find in a

    def lbs(self, a, to_find):
        a.sort()
        return to_find in a

    def stb(self, s):
        sum_val = 0
        k = 0
        for i in reversed(range(len(s))):
            sum_val += int(s[i]) * pow(2, k)
            k += 1
        return sum_val

if __name__ == "__main__":
    main_instance = Main()
    main_instance.solve()  # End of Code
