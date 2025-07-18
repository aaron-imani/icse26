MOD1 = 1000000007
MOD2 = 998244353

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
    E = None

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
        if c < 0:
            c += MOD2
        return S((f.D * c * mod_inv(9)) % MOD2, s.l, s.r)

class F:
    I = None

    def __init__(self, D, N):
        self.D = D
        self.N = N

    @staticmethod
    def composite(f, g):
        return F(f.D, f.N)

class LazySegTree:
    def __init__(self, dat, op, E, mapping, composition, Id):
        self.MAX = len(dat)
        self.N = 1 << (self.MAX - 1).bit_length()
        self.Log = (self.N).bit_length() - 1
        self.Op = op
        self.E = E
        self.Mapping = mapping
        self.Composition = composition
        self.Id = Id
        self.Dat = [E] * (self.N * 2)
        self.Laz = [Id] * self.N
        for i in range(self.MAX):
            self.Dat[self.N + i] = dat[i]
        for i in range(self.N - 1, 0, -1):
            self.Dat[i] = self.Op(self.Dat[i << 1], self.Dat[i << 1 | 1])

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
            self.Dat[p] = self.Op(self.Dat[p << 1], self.Dat[p << 1 | 1])
            p >>= 1

    def update_from_range(self, l, r):
        for i in range(1, self.Log + 1):
            if (l >> i) << i != l:
                lki = l >> i
                self.Dat[lki] = self.Op(self.Dat[lki << 1], self.Dat[lki << 1 | 1])
            if (r >> i) << i != r:
                rki = (r - 1) >> i
                self.Dat[rki] = self.Op(self.Dat[rki << 1], self.Dat[rki << 1 | 1])

    def push_to(self, k):
        for i in range(self.Log, 0, -1):
            if (k >> i) << i != k:
                self.push(k >> i)

    def push_to_range(self, lk, rk):
        for i in range(self.Log, 0, -1):
            if (lk >> i) << i != lk:
                self.push(lk >> i)
            if (rk >> i) << i != rk:
                self.push(rk >> i)

    def push(self, k):
        if self.Laz[k] == self.Id:
            return
        lk, rk = k << 1, k << 1 | 1
        self.Dat[lk] = self.Mapping(self.Laz[k], self.Dat[lk])
        self.Dat[rk] = self.Mapping(self.Laz[k], self.Dat[rk])
        if lk < self.N:
            self.Laz[lk] = self.Composition(self.Laz[k], self.Laz[lk])
        if rk < self.N:
            self.Laz[rk] = self.Composition(self.Laz[k], self.Laz[rk])
        self.Laz[k] = self.Id

    def exclusive_range_check(self, p):
        if p < 0 or p >= self.MAX:
            raise IndexError(f"Index {p} is not in [{0}, {self.MAX}).")

    def inclusive_range_check(self, p):
        if p < 0 or p > self.MAX:
            raise IndexError(f"Index {p} is not in [{0}, {self.MAX}].")

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    def next_int():
        nonlocal index
        val = int(data[index])
        index += 1
        return val

    def next_long():
        nonlocal index
        val = int(data[index])
        index += 1
        return val

    N = next_int()
    Q = next_int()
    tenmod = [1] * (N + 1)
    for j in range(1, N + 1):
        tenmod[j] = (tenmod[j - 1] * 10) % MOD2

    dat = [S(tenmod[N - i - 1], i, i) for i in range(N)]
    lazy_seg_tree = LazySegTree(dat, S.op, S.E, S.map, F.composite, F.I)

    for _ in range(Q):
        l = next_int() - 1
        r = next_int() - 1
        D = next_long()
        lazy_seg_tree.apply(l, r + 1, F(D, N))
        print(lazy_seg_tree.all_prod().sum)

# End of Code
