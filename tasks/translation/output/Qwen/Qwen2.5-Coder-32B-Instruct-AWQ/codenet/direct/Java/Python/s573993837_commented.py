import sys
import math

def main():
    input = sys.stdin.read().split()
    index = 0
    def next():
        nonlocal index
        index += 1
        return input[index - 1]
    
    def nextInt():
        return int(next())
    
    def nextLong():
        return int(next())
    
    def nextDouble():
        return float(next())
    
    t = 1
    while t > 0:
        n = nextLong()
        m = nextLong()
        if n == 0:
            print(0)
            t -= 1
            continue
        if n == m:
            print(0)
            t -= 1
            continue
        if n > m:
            n = m + n % m
            n -= m
            print(min(m - n, n))
            t -= 1
            continue
        print(min(m - n, n))
        t -= 1

def swap(chrr, i, j):
    chrr[i], chrr[j] = chrr[j], chrr[i]

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
        arr[i] = sc()

def printArr(arr):
    return ' '.join(map(str, arr))

if __name__ == "__main__":
    main()
# End of Code
