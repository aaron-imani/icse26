# Python program For handling Input/Output 

class Main:
    def __init__(self):
        self.sc = input
        self.max = 0
        self.cur = 0

    # actual logic
    def solve(self):
        a = self.ni()
        b = self.ni()

        print(max(0, a - 2 * b))

    # input an integer from scanner
    def ni(self):
        return int(self.sc())

    # input a long from scanner
    def nl(self):
        return int(self.sc())

    # input a float from scanner
    def nf(self):
        return float(self.sc())

    # input a double from scanner
    def nd(self):
        return float(self.sc())

    # input a sentence from scanner
    def ns(self):
        return self.sc()

    # input an intger array
    def ia(self, a):
        for i in range(len(a)):
            a[i] = self.ni()

    # input a long array
    def la(self, a):
        for i in range(len(a)):
            a[i] = self.nl()

    # input a float array
    def fa(self, a):
        for i in range(len(a)):
            a[i] = self.nf()

    # input a double array
    def da(self, a):
        for i in range(len(a)):
            a[i] = self.nd()

    # input a string array either with all empty input or from scanner
    def sa(self, a, empty):
        if empty:
            for i in range(len(a)):
                a[i] = ""
        else:
            for i in range(len(a)):
                a[i] = self.ns()

    # input two dimensional integer array
    def ida(self, a, n, m):
        for i in range(n):
            for j in range(m):
                a[i][j] = self.ni()

    # input two dimensional long array
    def lda(self, a, n, m):
        for i in range(n):
            for j in range(m):
                a[i][j] = self.nl()

    # input two dimensional double array
    def dda(self, a, n, m):
        for i in range(n):
            for j in range(m):
                a[i][j] = self.nd()

    # convert string to integer
    def stoi(self, s):
        return int(s)

    # convert string to double
    def stod(self, s):
        return float(s)

    # find minimum in a long array
    def lmin(self, a):
        return min(a)

    # find minimum in a integer array
    def imin(self, a):
        return min(a)

    # find maximum in a long array
    def lmax(self, a):
        return max(a)

    # find maximum in an integer array
    def imax(self, a):
        return max(a)

    # check whether an element is present in an integer array by binary search
    def ibs(self, a, toFind):
        a.sort()
        min_val = 0
        max_val = len(a) - 1
        found = False

        while min_val <= max_val and not found:
            mid = min_val + (max_val - min_val) // 2
            if a[mid] == toFind:
                found = True
            elif toFind > a[mid]:
                min_val = mid + 1
            else:
                max_val = mid - 1

        return found

    # check whether an element is present in a long array
    def lbs(self, a, toFind):
        a.sort()
        min_val = 0
        max_val = len(a) - 1
        found = False

        while min_val <= max_val and not found:
            mid = min_val + (max_val - min_val) // 2
            if a[mid] == toFind:
                found = True
            elif toFind > a[mid]:
                min_val = mid + 1
            else:
                max_val = mid - 1

        return found

    def stb(self, s):
        sum_val = 0
        k = 0
        for i in range(len(s) - 1, -1, -1):
            sum_val += int(s[i]) * (2 ** k)
            k += 1
        return sum_val

# main method
if __name__ == "__main__":
    main_instance = Main()
    main_instance.solve()
# End of Code
