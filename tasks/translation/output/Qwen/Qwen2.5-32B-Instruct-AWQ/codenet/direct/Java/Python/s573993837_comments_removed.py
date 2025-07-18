import sys
from math import gcd

def solve(sc, pw):
    t = 1
    while t > 0:
        t -= 1
        n = sc.nextLong()
        m = sc.nextLong()
        if n == 0:
            pw.write(f"{0}\n")
            continue
        if n == m:
            pw.write(f"{0}\n")
            continue
        if n > m:
            n = m + n % m
            n -= m
            pw.write(f"{min(m - n, n)}\n")
            continue
        pw.write(f"{min(m - n, n)}\n")

def swap(chrr, i, j):
    temp = chrr[i]
    chrr[i] = chrr[j]
    chrr[j] = temp

def num(n):
    a = 0
    while n > 0:
        a += (n & 1)
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
                self.tokenizer = iter(self.reader.readline().split())
            except:
                raise RuntimeError("Error reading input")
        return next(self.tokenizer)

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

if __name__ == "__main__":
    inputStream = sys.stdin
    outputStream = sys.stdout
    in_reader = InputReader(inputStream)
    out_writer = outputStream
    solve(in_reader, out_writer)
    out_writer.flush()  # Equivalent to out.close() in Java

# End of Code
