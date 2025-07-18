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
        for node in self.dt:
            node.clear()

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
        self.from_v = cm
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
    return (a ** 2 + b ** 2) ** 0.5

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
    for i in range(2, int(a ** 0.5) + 1):
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

def pow2(in_val):
    return in_val ** 2

def getDigit2(num):
    d = 0
    cf = 1
    while num >= cf:
        d += 1
        cf <<= d
    return d

def getDigit10(num):
    d = 0
    cf = 1
    while num >= cf:
        d += 1
        cf *= 10
    return d

def isINF(in_val):
    return in_val * 20 > INF

def isINFL(in_val):
    return in_val * 10000 > INFL

def pow10E97(ob, soeji, p):
    if ob == 0:
        return 0
    if soeji == 0:
        return 1
    if soeji == 2:
        return (ob * ob) % p

    d = getDigit2(soeji)
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

def isFlaged(bit, pos):
    return (bit & (1 << pos)) > 0

def deflag(bit, pos):
    return bit & ~(1 << pos)

def countFlaged(bit):
    ans = 0
    for i in range(getDigit2(bit)):
        if (bit & (1 << i)) > 0:
            ans += 1
    return ans

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
        mid = (right + left) // 2
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

def main():
    input = sys.stdin.readline
    n = int(input())
    s = input().strip()
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
                print(0)
                continue
            dw = surp9
            dif = pow10E97(2, n - p - 1, pop1st - 1)
            dw -= dif
            dw += (pop1st - 1)
            dw %= (pop1st - 1)

            ans = 1
            while dw != 0:
                if dw < 0:
                    print(1 / 0)
                count = countFlaged(dw)
                dw %= count
                ans += 1
            print(ans)
        else:
            dw = surp1
            dif = pow10E97(2, n - p - 1, pop1st + 1)
            dw += dif
            dw %= (pop1st + 1)

            ans = 1
            while dw != 0:
                if dw < 0:
                    print(1 / 0)
                count = countFlaged(dw)
                dw %= count
                ans += 1
            print(ans)

if __name__ == "__main__":
    main()  # End of Code
