MOD1 = 1000000007
MOD2 = 998244353
tenmod = [1]

def mod_inv(x):
    return pow(x, MOD2 - 2, MOD2)

def mod_pow(x, y):
    z = 1
    while y > 0:
        if y % 2 == 0:
            x = (x * x) % MOD2
            y //= 2
        else:
            z = (z * x) % MOD2
            y -= 1
    return z

class S:
    def __init__(self, sum_val, l, r):
        self.sum = sum_val
        self.l = l
        self.r = r

    @staticmethod
    def op(s1, s2):
        sum_val = (s1.sum + s2.sum) % MOD2
        return S(sum_val, min(s1.l, s2.l), max(s1.r, s2.r))

    @staticmethod
    def map(f, s):
        c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]) % MOD2
        return S(((f.D * c) % MOD2 * mod_inv(9)) % MOD2, s.l, s.r)

class F:
    def __init__(self, D, N):
        self.D = D
        self.N = N

    @staticmethod
    def composite(f, g):
        return F(f.D, f.N)

class LazySegTree:
    def __init__(self, n, op, e, mapping, composition, identity):
        self.MAX = n
        k = 1
        while k < n:
            k <<= 1
        self.N = k
        self.Log = k.bit_length()
        self.Op = op
        self.E = e
        self.Mapping = mapping
        self.Composition = composition
        self.Id = identity
        self.Dat = [e] * (k << 1)
        self.Laz = [identity] * k
        self.build()

    def build(self):
        for i in range(self.N - 1, 0, -1):
            self.Dat[i] = self.Op(self.Dat[i << 1 | 0], self.Dat[i << 1 | 1])

    def set(self, p, x):
        p += self.N
        self.push_to(p)
        self.Dat[p] = x
        self.update_from(p)

    def get(self, p):
        p += self.N
        self.push_to(p)
        return self.Dat[p]

    def all_prod(self):
        return self.Dat[1]

    def apply(self, l, r, f):
        if l > r:
            raise ValueError("Invalid range")
        l += self.N
        r += self.N
        self.push_to(l, r)
        l2, r2 = l, r
        while l2 < r2:
            if l2 & 1:
                self.Dat[l2] = self.Mapping(f, self.Dat[l2])
                if l2 < self.N:
                    self.Laz[l2] = self.Composition(f, self.Laz[l2])
                l2 += 1
            if r2 & 1:
                r2 -= 1
                self.Dat[r2] = self.Mapping(f, self.Dat[r2])
                if r2 < self.N:
                    self.Laz[r2] = self.Composition(f, self.Laz[r2])
            l2 >>= 1
            r2 >>= 1
        self.update_from(l, r)

    def update_from(self, p):
        p >>= 1
        while p > 0:
            self.Dat[p] = self.Op(self.Dat[p << 1 | 0], self.Dat[p << 1 | 1])
            p >>= 1

    def push_to(self, k):
        for i in range(self.Log, 0, -1):
            self.push(k >> i)

    def push(self, k):
        if self.Laz[k] == self.Id:
            return
        lk, rk = k << 1 | 0, k << 1 | 1
        self.Dat[lk] = self.Mapping(self.Laz[k], self.Dat[lk])
        self.Dat[rk] = self.Mapping(self.Laz[k], self.Dat[rk])
        if lk < self.N:
            self.Laz[lk] = self.Composition(self.Laz[k], self.Laz[lk])
        if rk < self.N:
            self.Laz[rk] = self.Composition(self.Laz[k], self.Laz[rk])
        self.Laz[k] = self.Id

    def push_to(self, lk, rk):
        for i in range(self.Log, 0, -1):
            if ((lk >> i) << i) != lk:
                self.push(lk >> i)
            if ((rk >> i) << i) != rk:
                self.push(rk >> i)

    def update_from(self, lk, rk):
        for i in range(1, self.Log + 1):
            if ((lk >> i) << i) != lk:
                lki = lk >> i
                self.Dat[lki] = self.Op(self.Dat[lki << 1 | 0], self.Dat[lki << 1 | 1])
            if ((rk >> i) << i) != rk:
                rki = (rk - 1) >> i
                self.Dat[rki] = self.Op(self.Dat[rki << 1 | 0], self.Dat[rki << 1 | 1])

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    idx = 0
    N = int(data[idx])
    idx += 1
    Q = int(data[idx])
    idx += 1
    for i in range(1, N + 1):
        tenmod.append((tenmod[-1] * 10) % MOD2)
    dat = [S(tenmod[N - i - 1], i, i) for i in range(N)]
    lazy_seg_tree = LazySegTree(N, S.op, S(0, float('inf') // 2, -float('inf') // 2), S.map, F.composite, F(0, 0))
    for _ in range(Q):
        l = int(data[idx]) - 1
        idx += 1
        r = int(data[idx]) - 1
        idx += 1
        D = int(data[idx])
        idx += 1
        lazy_seg_tree.apply(l, r + 1, F(D, N))
        print(lazy_seg_tree.all_prod().sum)

if __name__ == "__main__":
    main()
# End of Code
