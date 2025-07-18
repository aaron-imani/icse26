import sys

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
    return gcd(b, a % b)

def fast_pow(base, n, M):
    if n == 0:
        return 1
    if n == 1:
        return base
    half_n = fast_pow(base, n // 2, M)
    if n % 2 == 0:
        return (half_n * half_n) % M
    else:
        return ((half_n * half_n) % M * base) % M

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
        self.tokenizer = None

    def next(self):
        while self.tokenizer is None or not self.tokenizer.hasMoreTokens():
            self.tokenizer = self.reader.readline().split()
        return self.tokenizer.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

def solve(sc, pw):
    t = 1
    while t > 0:
        n = sc.next_long()
        m = sc.next_long()
        if n == 0:
            pw.write(str(0) + '\n')
            continue
        if n == m:
            pw.write(str(0) + '\n')
            continue
        if n > m:
            n = m + n % m
            n -= m
            pw.write(str(min(m - n, n)) + '\n')
            continue
        pw.write(str(min(m - n, n)) + '\n')
    pw.flush()

def main():
    sc = InputReader(sys.stdin)
    pw = sys.stdout
    solve(sc, pw)

if __name__ == "__main__":
    main()
# End of Code
