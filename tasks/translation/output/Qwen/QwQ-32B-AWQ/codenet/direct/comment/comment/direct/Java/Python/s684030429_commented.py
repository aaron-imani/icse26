class Main:
    def __init__(self):
        import sys
        self.tokens = iter(sys.stdin.read().split())
        self.max = 0
        self.cur = 0

    def ni(self):
        return int(next(self.tokens))

    def nl(self):
        return int(next(self.tokens))

    def nf(self):
        return float(next(self.tokens))

    def nd(self):
        return float(next(self.tokens))

    def ns(self):
        return next(self.tokens)

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
        min_val = float('inf')
        for num in a:
            if num < min_val:
                min_val = num
        return min_val

    def imin(self, a):
        min_val = float('inf')
        for num in a:
            if num < min_val:
                min_val = num
        return min_val

    def lmax(self, a):
        max_val = -float('inf')
        for num in a:
            if num > max_val:
                max_val = num
        return max_val

    def imax(self, a):
        max_val = -float('inf')
        for num in a:
            if num > max_val:
                max_val = num
        return max_val

    def ibs(self, a, toFind):
        a_sorted = sorted(a)
        min_i = 0
        max_i = len(a) - 1
        found = False
        while min_i <= max_i and not found:
            mid = (min_i + max_i) // 2
            if a_sorted[mid] == toFind:
                found = True
            elif toFind > a_sorted[mid]:
                min_i = mid + 1
            else:
                max_i = mid - 1
        return found

    def lbs(self, a, toFind):
        a_sorted = sorted(a)
        min_i = 0
        max_i = len(a) - 1
        found = False
        while min_i <= max_i and not found:
            mid = (min_i + max_i) // 2
            if a_sorted[mid] == toFind:
                found = True
            elif toFind > a_sorted[mid]:
                min_i = mid + 1
            else:
                max_i = mid - 1
        return found

    def stb(self, s):
        sum_val = 0
        k = 0
        for c in reversed(s):
            num = int(c)
            sum_val += num * (2 ** k)
            k += 1
        return sum_val

    def solve(self):
        a = self.ni()
        b = self.ni()
        print(max(0, a - 2 * b))

if __name__ == "__main__":
    main = Main()
    main.solve()  # End of Code
