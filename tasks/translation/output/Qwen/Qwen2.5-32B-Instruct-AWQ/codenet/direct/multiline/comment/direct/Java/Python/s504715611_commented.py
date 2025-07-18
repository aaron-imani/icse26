class UnionFind:
    def __init__(self, n):
        self.Parent = [-1] * n

    def root(self, A):
        if self.Parent[A] < 0:
            return A
        self.Parent[A] = self.root(self.Parent[A])
        return self.Parent[A]

    def size(self, A):
        return -self.Parent[self.root(A)]

    def connect(self, A, B):
        A = self.root(A)
        B = self.root(B)
        if A == B:
            return False
        if self.size(A) < self.size(B):
            A, B = B, A
        self.Parent[A] += self.Parent[B]
        self.Parent[B] = A
        return True


class FastScanner:
    def __init__(self):
        self.buffer = []
        self.ptr = 0

    def hasNextByte(self):
        if self.ptr < len(self.buffer):
            return True
        try:
            self.buffer = input().strip()
            self.ptr = 0
        except EOFError:
            pass
        return self.ptr < len(self.buffer)

    def readByte(self):
        if self.hasNextByte():
            result = self.buffer[self.ptr]
            self.ptr += 1
            return ord(result)
        return -1

    @staticmethod
    def isPrintableChar(c):
        return 33 <= c <= 126

    def hasNext(self):
        while self.hasNextByte() and not FastScanner.isPrintableChar(self.buffer[self.ptr]):
            self.ptr += 1
        return self.hasNextByte()

    def next(self):
        if not self.hasNext():
            raise NoSuchElementException("No more elements")
        sb = []
        b = self.readByte()
        while FastScanner.isPrintableChar(b):
            sb.append(chr(b))
            b = self.readByte()
        return "".join(sb)

    def nextLong(self):
        if not self.hasNext():
            raise NoSuchElementException("No more elements")
        n = 0
        minus = False
        b = self.readByte()
        if b == ord('-'):
            minus = True
            b = self.readByte()
        if b < ord('0') or b > ord('9'):
            raise NumberFormatException("Invalid number format")
        while True:
            if ord('0') <= b <= ord('9'):
                n *= 10
                n += b - ord('0')
            elif b == -1 or not FastScanner.isPrintableChar(b):
                return -n if minus else n
            else:
                raise NumberFormatException("Invalid number format")
            b = self.readByte()

    def nextInt(self):
        nl = self.nextLong()
        if nl < -2**31 or nl > 2**31 - 1:
            raise NumberFormatException("Number out of range")
        return int(nl)

    def nextDouble(self):
        return float(self.next())

    def nextchar(self):
        try:
            return input()[0]
        except Exception as e:
            raise RuntimeError(e)


def main():
    scan = FastScanner()
    str_input = scan.next()
    print("Yes" if str_input[2] == str_input[3] and str_input[4] == str_input[5] else "No")


if __name__ == "__main__":
    main()  # End of Code
