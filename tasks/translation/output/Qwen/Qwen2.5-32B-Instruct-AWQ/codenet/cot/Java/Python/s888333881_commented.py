import sys

class Graph0n:
    def __init__(self, sz):
        self.dt = [Node0n() for _ in range(sz)]

    def add(self, vn, val):
        self.dt[vn].add(val)

    def add2(self, vn, val):
        self.dt[vn].add(val)
        self.dt[val].add(vn)

    def get(self, vn, index):
        return self.dt[vn].get(index)

    def get_all(self, vn):
        return self.dt[vn].get_all()

    def size_of(self, vn):
        return self.dt[vn].size()

    def clear(self):
        for node in self.dt:
            node.clear()

class Node0n:
    def __init__(self):
        self.next_vs = []

    def add(self, val):
        self.next_vs.append(val)

    def get(self, ad):
        return self.next_vs[ad]

    def get_all(self):
        return self.next_vs

    def size(self):
        return len(self.next_vs)

    def clear(self):
        self.next_vs.clear()

class Edge:
    def __init__(self, vn, w):
        self.v2 = vn
        self.weight = w

    def __init__(self, cm, vn, w):
        self.from_ = cm
        self.v2 = vn
        self.weight = w

class Edge2:
    def __init__(self, vn, w1, w2):
        self.v2 = vn
        self.cost1 = w1
        self.cost2 = w2

class Comparator_Edge:
    def compare(self, a, b):
        if a.weight > b.weight:
            return -1
        elif a.weight < b.weight:
            return 1
        else:
            return b.v2 - a.v2

class V2Comp:
    def compare(self, a, b):
        if a.v2 > b.v2:
            return -1
        elif a.v2 < b.v2:
            return 1
        elif a.weight > b.weight:
            return -1
        elif a.weight < b.weight:
            return 1
        else:
            return 0

class antiV2:
    def compare(self, a, b):
        if a.v2 > b.v2:
            return 1
        elif a.v2 < b.v2:
            return -1
        elif a.weight > b.weight:
            return -1
        elif a.weight < b.weight:
            return 1
        else:
            return 0

class Vector:
    def __init__(self, sx, sy):
        self.x = sx
        self.y = sy

INF = int(1e8)
INFL = int(1e17)
e97 = int(1e9) + 7

def abs(a):
    return a if a >= 0 else -a

def min(a, b):
    return a if a > b else b

def max(a, b):
    return a if a > b else b

def minN(*ins):
    return min(ins)

def maxN(*ins):
    return max(ins)

def minExAd(dt, ad):
    min_val = INF
    for i in range(len(dt)):
        if i != ad and dt[i] < min_val:
            min_val = dt[i]
    return min_val

def minExVal(dt, ex_val):
    min_val = INF
    for i in range(len(dt)):
        if dt[i] != ex_val and dt[i] < min_val:
            min_val = dt[i]
    return min_val

def maxExAd(dt, ad):
    max_val = -INF
    for i in range(len(dt)):
        if i != ad and dt[i] > max_val:
            max_val = dt[i]
    return max_val

def maxExVal(dt, ex_val):
    max_val = -INF
    for i in range(len(dt)):
        if dt[i] != ex_val and dt[i] > max_val:
            max_val = dt[i]
    return max_val

def sumA(dt):
    return sum(dt)

def same3(a, b, c):
    return a == b == c

def dif3(a, b, c):
    return a != b and b != c and c != a

def triangle_inequality(a, b, c):
    return a + b > c and b + c > a and c + a > b

def hypod(a, b):
    return (a**2 + b**2)**0.5

def factorial(n):
    return 1 if n == 0 else n * factorial(n-1)

def facP(n, p):
    ans = 1
    for i in range(n, 0, -1):
        ans *= i
        ans %= p
    return ans

def lcm(m, n):
    return m * n // gcd(m, n)

def gcd(m, n):
    return gcd(n, m % n) if n != 0 else m

def is_prime(a):
    if a == 1:
        return False
    for i in range(2, int(a**0.5) + 1):
        if a % i == 0:
            return False
    return True

def modinv(a, p):
    b, u, v = p, 1, 0
    while b > 0:
        t = a // b
        a, b = b, a % b
        u, v = v, u - t * v
    u %= p
    if u < 0:
        u += p
    return u

def pow(n, k):
    return n**k

def pow2(in_):
    return in_**2

def getDigit2(num):
    d = 0
    while num >= (1 << d):
        d += 1
    return d

def getDigit10(num):
    d = 0
    while num >= 10**d:
        d += 1
    return d

def isINF(in_):
    return in_ * 20 > INF

def isINFL(in_):
    return in_ * 10000 > INFL

def pow10E97(ob, soeji, p):
    if ob == 0:
        return 0
    if soeji == 0:
        return 1
    if soeji == 2:
        return (ob * ob) % p

    d = getDigit2(soeji)
    ob_pow_2pow = [ob] + [0] * (d - 1)
    for i in range(1, d):
        ob_pow_2pow[i] = (ob_pow_2pow[i-1] * ob_pow_2pow[i-1]) % p

    ans = 1
    for i in range(d-1, -1, -1):
        if soeji >= (1 << i):
            soeji -= (1 << i)
            ans = (ans * ob_pow_2pow[i]) % p
    return ans % p

def flag(pos):
    return 1 << pos

def isFlaged(bit, pos):
    return (bit & (1 << pos)) > 0

def deflag(bit, pos):
    return bit & ~(1 << pos)

def countFlaged(bit):
    return bin(bit).count('1')

def showflag(bit):
    for i in range(getDigit2(bit)):
        if isFlaged(bit, i):
            print("O", end="")
        else:
            print(".", end="")
    print()

def biSearch(dt, target):
    left, right = 0, len(dt) - 1
    while left <= right:
        mid = (left + right) // 2
        if dt[mid] == target:
            return mid
        if dt[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def biSearchMax(dt, target):
    left, right = -1, len(dt)
    while (right - left) > 1:
        mid = left + (right - left) // 2
        if dt[mid] <= target:
            left = mid
        else:
            right = mid
    return left

def biSearchMaxAL(dt, target):
    left, right = -1, len(dt)
    while (right - left) > 1:
        mid = left + (right - left) // 2
        if dt[mid] <= target:
            left = mid
        else:
            right = mid
    return left

def fill_parent(ob):
    for i in range(len(ob)):
        ob[i] = i

def get_root_uf(parent, index):
    if parent[index] == index:
        return index
    root = get_root_uf(parent, parent[index])
    parent[index] = root
    return root

def is_same_uf(parent, x, y):
    return get_root_uf(parent, x) == get_root_uf(parent, y)

def unite_uf(parent, receiver, attacker):
    parent[get_root_uf(parent, attacker)] = get_root_uf(parent, receiver)

Xdir4 = [1, 0, 0, -1]
Ydir4 = [0, 1, -1, 0]

Xdir8 = [1, 1, 1, 0, 0, -1, -1, -1]
Ydir8 = [1, 0, -1, 1, -1, 1, 0, -1]

def is_in_area(y, x, h, w):
    return 0 <= y < h and 0 <= x < w

def show2(dt, lit_x, lit_y):
    for j in range(len(dt)):
        for i in range(len(dt[j])):
            if i == lit_y and j == lit_x:
                print("X", end="")
            elif dt[j][i]:
                print("O", end="")
            else:
                print(".", end="")
        print()

def show2(dt, cmnt):
    for i in range(len(dt)):
        for j in range(len(dt[i])):
            print(dt[i][j], end=",")
        print(f"<-{cmnt}:{i}")

def disp_que(dt):
    while dt:
        print(dt.popleft(), end="")
    print("\n")

def disp_list(dt):
    for i in range(len(dt)):
        print(dt[i], end=",")
    print("\n")

def prtlnas(as_):
    for i in range(len(as_)):
        print(as_[i])

def prtspas(as_):
    print(as_[0], end="")
    for i in range(1, len(as_)):
        print(f" {as_[i]}", end="")
    print()

def fill(ob, res):
    for i in range(len(ob)):
        ob[i] = res

class FastScanner:
    def __init__(self):
        self.buffer = []
        self.ptr = 0

    def hasNext(self):
        if self.ptr < len(self.buffer):
            return True
        self.buffer = sys.stdin.readline().split()
        self.ptr = 0
        return self.ptr < len(self.buffer)

    def next(self):
        if not self.hasNext():
            raise Exception("No more input")
        self.ptr += 1
        return self.buffer[self.ptr - 1]

    def nexL(self):
        if not self.hasNext():
            raise Exception("No more input")
        n = 0
        minus = False
        if self.buffer[self.ptr - 1] == '-':
            minus = True
            self.ptr += 1
        while self.hasNext():
            if '0' <= self.buffer[self.ptr - 1] <= '9':
                n = n * 10 + int(self.buffer[self.ptr - 1])
                self.ptr += 1
            else:
                break
        return -n if minus else n

    def nexI(self):
        nl = self.nexL()
        if nl < -2**31 or nl > 2**31 - 1:
            raise Exception("Integer overflow")
        return int(nl)

    def nexD(self):
        return float(self.next())

    def ni(self, array2):
        for i in range(len(array2)):
            array2[i] = self.nexL()

    def ni(self, array2):
        for i in range(len(array2)):
            array2[i] = self.nexI()

    def ni(self, as_, bs):
        for i in range(len(as_)):
            as_[i] = self.nexI()
            bs[i] = self.nexI()

    def ni(self, as_, bs):
        for i in range(len(as_)):
            as_[i] = self.nexL()
            bs[i] = self.nexL()

    def ni(self, as_, bs, cs):
        for i in range(len(as_)):
            as_[i] = self.nexI()
            bs[i] = self.nexI()
            cs[i] = self.nexI()

    def nisan(self, as_):
        for i in range(len(as_)):
            for j in range(len(as_[0])):
                as_[i][j] = self.nexI()

def main():
    sc = FastScanner()
    out = sys.stdout.write

    n = sc.nexI()
    s = sc.next()
    flaged = [False] * n
    for i in range(n):
        if s[i] == '1':
            flaged[i] = True

    pop1st = sum(flaged)
    surp1 = 0
    for i in range(n):
        surp1 = (surp1 * 2 + flaged[i]) % (pop1st + 1)

    surp9 = 0
    if pop1st > 1:
        for i in range(n):
            surp9 = (surp9 * 2 + flaged[i]) % (pop1st - 1)

    for p in range(n):
        if flaged[p]:
            if pop1st == 1:
                out("0\n")
                continue
            dw = surp9
            dif = pow(2, n - p - 1, pop1st - 1)
            dw = (dw - dif + pop1st - 1) % (pop1st - 1)
            ans = 1
            while dw != 0:
                if dw < 0:
                    out("1/0\n")
                count = bin(dw).count('1')
                dw %= count
                ans += 1
            out(f"{ans}\n")
        else:
            dw = surp1
            dif = pow(2, n - p - 1, pop1st + 1)
            dw = (dw + dif) % (pop1st + 1)
            ans = 1
            while dw != 0:
                if dw < 0:
                    out("1/0\n")
                count = bin(dw).count('1')
                dw %= count
                ans += 1
            out(f"{ans}\n")

if __name__ == "__main__":
    main()
# End of Code
