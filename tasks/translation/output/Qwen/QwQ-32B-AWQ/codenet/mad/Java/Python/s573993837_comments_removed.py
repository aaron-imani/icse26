class InputReader:
    def __init__(self, stream):
        self.reader = stream
        self.tokens = []
    
    def next(self):
        while not self.tokens:
            line = self.reader.readline()
            if not line:
                return None
            self.tokens = line.split()
        return self.tokens.pop(0)
    
    def nextInt(self):
        return int(self.next())
    
    def nextLong(self):
        return int(self.next())
    
    def nextDouble(self):
        return float(self.next())

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
        self.val = 0

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
        return (( (halfn * halfn) % M ) * base ) % M

def modInverse(n, M):
    return fast_pow(n, M - 2, M)

def feedArrLong(arr, sc):
    for i in range(len(arr)):
        arr[i] = sc.nextLong()

def feedArrDouble(arr, sc):
    for i in range(len(arr)):
        arr[i] = sc.nextDouble()

def feedArrInt(arr, sc):
    for i in range(len(arr)):
        arr[i] = sc.nextInt()

def feedArrString(arr, sc):
    for i in range(len(arr)):
        arr[i] = sc.next()

def printArr(arr):
    return ' '.join(map(str, arr)) + ' '

def solve(sc, pw):
    t = 1
    while t > 0:
        t -= 1
        n = sc.nextLong()
        m = sc.nextLong()
        if n == 0:
            print(0, file=pw)
            continue
        if n == m:
            print(0, file=pw)
            continue
        if n > m:
            n %= m
        res = min(m - n, n)
        print(res, file=pw)

if __name__ == '__main__':
    import sys
    in_reader = InputReader(sys.stdin)
    out = sys.stdout
    solve(in_reader, out)
    # End of Code
