import sys
import math
from collections import deque

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
    def __init__(self, vn, w, cm=-1):
        self.from_ = cm
        self.v2 = vn
        self.weight = w

class Edge2:
    def __init__(self, vn, w1, w2):
        self.v2 = vn
        self.cost1 = w1
        self.cost2 = w2

class Comparator_Edge:
    def __call__(self, a, b):
        if a.weight > b.weight:
            return -1
        elif a.weight < b.weight:
            return 1
        else:
            return b.v2 - a.v2

class V2Comp:
    def __call__(self, a, b):
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
    def __call__(self, a, b):
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

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    s = data[1]
    flaged = [False] * n
    
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

def pow10E97(ob, soeji, p):
    if ob == 0:
        return 0
    if soeji == 0:
        return 1
    if soeji == 2:
        return (ob * ob) % p
    
    d = getDigit2(soeji)
    ob_pow_2pow = [0] * d
    
    ob_pow_2pow[0] = ob
    for i in range(1, d):
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p
    
    ans = 1
    for i in range(d - 1, -1, -1):
        if soeji >= (1 << i):
            soeji -= (1 << i)
            ans = (ans * ob_pow_2pow[i]) % p
    return ans % p

def countFlaged(bit):
    ans = 0
    for i in range(getDigit2(bit)):
        if bit & (1 << i):
            ans += 1
    return ans

def getDigit2(num):
    cf = 1
    d = 0
    while num >= cf:
        d += 1
        cf = (1 << d)
    return d

if __name__ == "__main__":
    main()
# End of Code
