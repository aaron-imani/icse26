def solve(sc, pw):
    t = 1
    while t > 0:
        n = sc.nextLong()
        m = sc.nextLong()
        if n == 0:
            pw.println(0)
            continue
        if n == m:
            pw.println(0)
            continue
        if n > m:
            n = m + n % m
            n -= m
            pw.println(min(m - n, n))
            continue
        pw.println(min(m - n, n))
    t -= 1

def swap(chrr, i, j):
    temp = chrr[i]
    chrr[i] = chrr[j]
    chrr[j] = temp

def num(n):
    a = 0
    while n > 0:
        a += n & 1
        n >>= 1
    return a

class Pair:
    def __init__(self, a, b, i):
        self.u = a
        self.v = b
        self.i = i

def isPrime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b) if a > b else gcd(a, b % a)

def fast_pow(base, n, M):
    if n == 0:
        return 1
    if n == 1:
        return base
    halfn = fast_pow(base, n // 2, M)
    if n % 2 == 0:
        return (halfn * halfn) % M
    else:
        return ((halfn * halfn) % M * base) % M

def modInverse(n, M):
    return fast_pow(n, M - 2, M)

def feedArr(arr, sc):
    for i in range(len(arr)):
        arr[i] = sc.nextLong()

def printArr(arr):
    return ' '.join(map(str, arr))

class InputReader:
    def __init__(self, stream):
        self.reader = stream
        self.tokenizer = None

    def next(self):
        while self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            try:
                self.tokenizer = self.reader.readline().split()
            except Exception as e:
                raise RuntimeError(e)
        return self.tokenizer.pop(0)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

if __name__ == "__main__":
    import sys
    sc = InputReader(sys.stdin)
    pw = sys.stdout
    solve(sc, pw)
    pw.flush()
# End of Code
