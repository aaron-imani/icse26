class S:
    E = None

    def __init__(self, sum_val, l, r):
        self.sum = sum_val % MOD2
        self.l = l
        self.r = r

    @staticmethod
    def op(s1, s2):
        new_sum = (s1.sum + s2.sum) % MOD2
        new_l = min(s1.l, s2.l)
        new_r = max(s1.r, s2.r)
        return S(new_sum, new_l, new_r)

    @staticmethod
    def map(f, s):
        N = f.N
        term1 = tenmod[N - s.l]
        term2 = tenmod[N - s.r - 1]
        c = (term1 - term2) % MOD2
        new_sum = (f.D * c) % MOD2
        new_sum = (new_sum * inv9) % MOD2
        return S(new_sum, s.l, s.r)

S.E = S(0, float('inf'), float('-inf'))

class F:
    I = None

    def __init__(self, D, N):
        self.D = D
        self.N = N

    @staticmethod
    def composite(f, g):
        return F(f.D, f.N)

F.I = F(0, 0)

class LazySegTree:
    def __init__(self, dat, op_func, e, mapping_func, composition_func, id_f):
        self.N = 1
        self.MAX = len(dat)
        while self.N < self.MAX:
            self.N <<= 1
        self.Log = (self.N).bit_length() - 1
        self.Op = op_func
        self.E = e
        self.Mapping = mapping_func
        self.Composition = composition_func
        self.Id_f = id_f

        self.Dat = [self.E] * (2 * self.N)
        self.Laz = [self.Id_f] * self.N

        for i in range(self.MAX):
            self.Dat[self.N + i] = dat[i]
        for i in range(self.N - 1, 0, -1):
            self.Dat[i] = self.Op(self.Dat[2 * i], self.Dat[2 * i + 1])

    def allProd(self):
        return self.Dat[1].sum

    def apply(self, l, r, f):
        if l >= r:
            return
        l_internal = l + self.N
        r_internal = r + self.N
        self.pushTo(l_internal, r_internal)
        l2 = l_internal
        r2 = r_internal
        while l2 < r2:
            if (l2 & 1) == 1:
                self.Dat[l2] = self.Mapping(f, self.Dat[l2])
                if l2 < self.N:
                    self.Laz[l2] = self.Composition(f, self.Laz[l2])
                l2 += 1
            if (r2 & 1) == 1:
                r2 -= 1
                self.Dat[r2] = self.Mapping(f, self.Dat[r2])
                if r2 < self.N:
                    self.Laz[r2] = self.Composition(f, self.Laz[r2])
            l2 >>= 1
            r2 >>= 1
        self.updateFrom(l_internal, r_internal)

    def pushTo(self, l, r):
        for i in range(self.Log, 0, -1):
            l_node = l >> i
            if (l_node << i) != l:
                self.push(l_node)
            r_node = (r - 1) >> i
            if (r_node << i) != (r - 1):
                self.push(r_node)

    def push(self, k):
        if self.Laz[k] == self.Id_f:
            return
        left = 2 * k
        right = 2 * k + 1
        self.Dat[left] = self.Mapping(self.Laz[k], self.Dat[left])
        self.Dat[right] = self.Mapping(self.Laz[k], self.Dat[right])
        if left < self.N:
            self.Laz[left] = self.Composition(self.Laz[k], self.Laz[left])
            self.Laz[right] = self.Composition(self.Laz[k], self.Laz[right])
        self.Laz[k] = self.Id_f

    def updateFrom(self, l, r):
        for i in range(1, self.Log + 1):
            l_node = l >> i
            if (l_node << i) != l:
                self.Dat[l_node] = self.Op(self.Dat[2 * l_node], self.Dat[2 * l_node + 1])
            r_node = (r - 1) >> i
            if (r_node << i) != (r - 1):
                self.Dat[r_node] = self.Op(self.Dat[2 * r_node], self.Dat[2 * r_node + 1])

MOD2 = 998244353
inv9 = 0

def modPow(x, y):
    res = 1
    while y > 0:
        if y % 2 == 1:
            res = (res * x) % MOD2
        x = (x * x) % MOD2
        y = y // 2
    return res

def modInv(x):
    return modPow(x, MOD2 - 2)

inv9 = modInv(9)

def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    N = int(input[ptr]); ptr +=1
    Q = int(input[ptr]); ptr +=1

    global tenmod
    tenmod = [0] * (N + 1)
    tenmod[0] = 1
    for j in range(1, N + 1):
        tenmod[j] = (tenmod[j-1] * 10) % MOD2

    dat = []
    for i in range(N):
        coeff = tenmod[N - i - 1]
        s = S(coeff, i, i)
        dat.append(s)

    lazySegTree = LazySegTree(dat, S.op, S.E, S.map, F.composite, F.I)

    for _ in range(Q):
        l = int(input[ptr])-1; ptr +=1
        r = int(input[ptr])-1; ptr +=1
        D = int(input[ptr]); ptr +=1
        f = F(D, N)
        lazySegTree.apply(l, r+1, f)
        print(lazySegTree.allProd())

if __name__ == "__main__":
    main()
#End of Code
