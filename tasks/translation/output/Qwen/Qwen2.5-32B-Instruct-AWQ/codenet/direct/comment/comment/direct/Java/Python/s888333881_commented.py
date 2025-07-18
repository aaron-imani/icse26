import sys

class Graph0n:
    def __init__(self, sz):
        self.dt = [Node0n() for _ in range(sz)]
    
    def add(self, vn, val):
        self.dt[vn].add(val)
    
    def add2(self, vn, val):
        self.dt[vn].add(val)
        self.dt[val].add(vn)
    
    def get(self, vn, index=None):
        if index is None:
            return self.dt[vn].getAll()
        return self.dt[vn].get(index)
    
    def sizeOf(self, vn):
        return self.dt[vn].size()
    
    def clear(self):
        for i in range(len(self.dt)):
            self.dt[i].clear()

class Node0n:
    def __init__(self):
        self.next_vs = []
    
    def add(self, val):
        self.next_vs.append(val)
    
    def get(self, ad):
        return self.next_vs[ad]
    
    def getAll(self):
        return self.next_vs
    
    def size(self):
        return len(self.next_vs)
    
    def clear(self):
        self.next_vs.clear()

class Edge:
    def __init__(self, vn, w, cm=-1):
        self.from_cm = cm
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

def fill(array, value):
    for i in range(len(array)):
        array[i] = value

def abs(a):
    return a if a >= 0 else -a

def min(a, b):
    return a if a > b else b

def max(a, b):
    return a if a > b else b

def minN(*ins):
    min_val = ins[0]
    for i in range(1, len(ins)):
        if ins[i] < min_val:
            min_val = ins[i]
    return min_val

def maxN(*ins):
    max_val = ins[0]
    for i in range(1, len(ins)):
        if ins[i] > max_val:
            max_val = ins[i]
    return max_val

def minExAd(dt, ad):
    min_val = float('inf')
    for i in range(len(dt)):
        if i != ad and dt[i] < min_val:
            min_val = dt[i]
    return min_val

def minExVal(dt, ex_val):
    min_val = float('inf')
    for i in range(len(dt)):
        if dt[i] != ex_val and dt[i] < min_val:
            min_val = dt[i]
    return min_val

def maxExAd(dt, ad):
    max_val = -float('inf')
    for i in range(len(dt)):
        if i != ad and dt[i] > max_val:
            max_val = dt[i]
    return max_val

def maxExVal(dt, ex_val):
    max_val = -float('inf')
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
    ans = 1
    for i in range(n, 0, -1):
        ans *= i
    return ans

def facP(n, p):
    ans = 1
    for i in range(n, 0, -1):
        ans *= i
        ans %= p
    return ans

def lcm(m, n):
    return m * n // gcd(m, n)

def gcd(m, n):
    if m < n:
        return gcd(n, m)
    if n == 0:
        return m
    return gcd(n, m % n)

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
        pe = a % b
        a, b = b, pe
        pe = u - t * v
        u, v = v, pe
    u %= p
    if u < 0:
        u += p
    return u

def pow(n, k):
    return n ** k

def pow2(in_):
    return in_ * in_

def get_digit2(num):
    cf, d = 1, 0
    while num >= cf:
        d += 1
        cf <<= d
    return d

def get_digit10(num):
    cf, d = 1, 0
    while num >= cf:
        d += 1
        cf *= 10
    return d

def is_INF(in_):
    return in_ * 20 > 10**8

def is_INFL(in_):
    return in_ * 10000 > 10**17

def pow10E97(ob, soeji, p):
    if ob == 0:
        return 0
    if soeji == 0:
        return 1
    if soeji == 2:
        return (ob * ob) % p

    d = get_digit2(soeji)
    ob_pow_2pow = [None] * d
    ob_pow_2pow[0] = ob
    for i in range(1, d):
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p

    ans = 1
    for i in range(d - 1, -1, -1):
        if soeji >= (1 << i):
            soeji -= (1 << i)
            ans = (ans * ob_pow_2pow[i]) % p
    return ans % p

def flag(pos):
    return 1 << pos

def is_flaged(bit, pos):
    return (bit & (1 << pos)) > 0

def deflag(bit, pos):
    return bit & ~(1 << pos)

def count_flaged(bit):
    ans = 0
    for i in range(get_digit2(bit)):
        if (bit & (1 << i)) > 0:
            ans += 1
    return ans

def show_flag(bit):
    for i in range(get_digit2(bit)):
        if is_flaged(bit, i):
            print("O", end="")
        else:
            print(".", end="")
    print()

def bi_search(dt, target):
    left, right = 0, len(dt) - 1
    while left <= right:
        mid = (right + left) // 2
        if dt[mid] == target:
            return mid
        if dt[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def bi_search_max(dt, target):
    left, right = -1, len(dt)
    while (right - left) > 1:
        mid = left + (right - left) // 2
        if dt[mid] <= target:
            left = mid
        else:
            right = mid
    return left

def bi_search_max_al(dt, target):
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

XDIR4 = [1, 0, 0, -1]
YDIR4 = [0, 1, -1, 0]

XDIR8 = [1, 1, 1, 0, 0, -1, -1, -1]
YDIR8 = [1, 0, -1, 1, -1, 1, 0, -1]

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
        print(dt.popleft())
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
        self.in_ = sys.stdin.buffer
        self.buffer = bytearray(1024)
        self.ptr = 0
        self.buflen = 0

    def hasNextByte(self):
        if self.ptr < self.buflen:
            return True
        self.ptr = 0
        self.buflen = self.in_.readinto(self.buffer)
        return self.buflen > 0

    def readByte(self):
        if self.hasNextByte():
            byte = self.buffer[self.ptr]
            self.ptr += 1
            return byte
        return -1

    def isPrintableChar(self, c):
        return 33 <= c <= 126

    def hasNext(self):
        while self.hasNextByte() and not self.isPrintableChar(self.buffer[self.ptr]):
            self.ptr += 1
        return self.hasNextByte()

    def next(self):
        if not self.hasNext():
            raise StopIteration
        sb = []
        b = self.readByte()
        while self.isPrintableChar(b):
            sb.append(chr(b))
            b = self.readByte()
        return "".join(sb)

    def nexL(self):
        if not self.hasNext():
            raise StopIteration
        n = 0
        minus = False
        b = self.readByte()
        if b == ord('-'):
            minus = True
            b = self.readByte()
        if not ('0' <= chr(b) <= '9'):
            raise ValueError
        while True:
            if '0' <= chr(b) <= '9':
                n *= 10
                n += b - ord('0')
            elif b == -1 or not self.isPrintableChar(b) or b == ord(':'):
                return -n if minus else n
            else:
                raise ValueError
            b = self.readByte()

    def nexI(self):
        nl = self.nexL()
        if nl < -2**31 or nl > 2**31 - 1:
            raise ValueError
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

if __name__ == "__main__":
    sc = FastScanner()
    out = sys.stdout.write

    n = sc.nexI()
    s = sc.next()
    flaged = [False] * n
    fill(flaged, False)

    pop1st = 0
    for i in range(n):
        if s[i] == '1':
            flaged[i] = True
            pop1st += 1

    surp1 = 0
    for i in range(n):
        surp1 *= 2
        if flaged[i]:
            surp1 += 1
        surp1 %= (pop1st + 1)

    surp9 = 0
    if pop1st > 1:
        for i in range(n):
            surp9 *= 2
            if flaged[i]:
                surp9 += 1
            surp9 %= (pop1st - 1)

    for p in range(n):
        if flaged[p]:
            if pop1st == 1:
                out.write("0\n")
                continue
            dw = surp9
            dif = pow10E97(2, n - p - 1, pop1st - 1)
            dw -= dif
            dw += (pop1st - 1)
            dw %= (pop1st - 1)
            ans = 1
            while dw != 0:
                if dw < 0:
                    out.write("1/0\n")
                count = count_flaged(dw)
                dw %= count
                ans += 1
            out.write(f"{ans}\n")
        else:
            dw = surp1
            dif = pow10E97(2, n - p - 1, pop1st + 1)
            dw += dif
            dw %= (pop1st + 1)
            ans = 1
            while dw != 0:
                if dw < 0:
                    out.write("1/0\n")
                count = count_flaged(dw)
                dw %= count
                ans += 1
            out.write(f"{ans}\n")

# End of Code
