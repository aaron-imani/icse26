import sys

def solve(sc):
    while True:
        n = sc.next_long()
        m = sc.next_long()
        if n == 0:
            print(0)
            break
        if n == m:
            print(0)
            break
        if n > m:
            n = m + n % m
            n -= m
            print(min(m - n, n))
            break
        print(min(m - n, n))
        break

def swap(chrr, i, j):
    chrr[i], chrr[j] = chrr[j], chrr[i]

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

def is_prime(n):
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

def mod_inverse(n, M):
    return fast_pow(n, M - 2, M)

def feed_arr(arr, sc):
    for i in range(len(arr)):
        arr[i] = sc.next_long()

def print_arr(arr):
    return ' '.join(map(str, arr))

class InputReader:
    def __init__(self, stream):
        self.reader = stream
        self.buffer = []
        self.token = 0

    def next(self):
        while self.token >= len(self.buffer):
            a = self.reader.readline()
            if a == '':
                return None
            self.buffer = a.split()
            self.token = 0
        result = self.buffer[self.token]
        self.token += 1
        return result

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

if __name__ == "__main__":
    sc = InputReader(sys.stdin)
    solve(sc)
# End of Code
