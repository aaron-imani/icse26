MOD1 = 1000000007
MOD2 = 998244353
inv9 = pow(9, MOD2 - 2, MOD2)

class S:
    E = None

    def __init__(self, sum, l, r):
        self.sum = sum
        self.l = l
        self.r = r

    @staticmethod
    def op(s1, s2):
        sum = s1.sum + s2.sum
        if sum >= MOD2:
            sum -= MOD2
        return S(sum, min(s1.l, s2.l), max(s1.r, s2.r))

    @staticmethod
    def map(f, s):
        c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]) % MOD2
        return S(((f.D * c) % MOD2 * inv9) % MOD2, s.l, s.r)

S.E = S(0, float('inf') // 2, -float('inf') // 2)

class F:
    I = None

    def __init__(self, D, N):
        self.D = D
        self.N = N

    @staticmethod
    def composite(f, g):
        return F(f.D, f.N)

F.I = F(0, 0)

def modPow(x, y):
    z = 1
    while y > 0:
        if y % 2 == 0:
            x = (x * x) % MOD2
            y //= 2
        else:
            z = (z * x) % MOD2
            y -= 1
    return z

class LazySegTree:
    def __init__(self, n, op, e, mapping, composition, id):
        self.MAX = n
        k = 1
        while k < n:
            k <<= 1
        self.N = k
        self.Log = k.bit_length() - 1
        self.Op = op
        self.E = e
        self.Mapping = mapping
        self.Composition = composition
        self.Id = id
        self.Dat = [e] * (self.N * 2)
        self.Laz = [id] * self.N

    def build(self, dat):
        l = len(dat)
        self.Dat[self.N:self.N + l] = dat
        for i in range(self.N - 1, 0, -1):
            self.Dat[i] = self.Op(self.Dat[i * 2], self.Dat[i * 2 + 1])

    def push(self, k):
        if self.Laz[k] == self.Id:
            return
        lk = k * 2
        rk = k * 2 + 1
        self.Dat[lk] = self.Mapping(self.Laz[k], self.Dat[lk])
        self.Dat[rk] = self.Mapping(self.Laz[k], self.Dat[rk])
        if lk < self.N:
            self.Laz[lk] = self.Composition(self.Laz[k], self.Laz[lk])
        if rk < self.N:
            self.Laz[rk] = self.Composition(self.Laz[k], self.Laz[rk])
        self.Laz[k] = self.Id

    def push_to(self, k):
        for i in range(self.Log, 0, -1):
            self.push(k >> i)

    def push_to_range(self, lk, rk):
        for i in range(self.Log, 0, -1):
            if (lk >> i) << i != lk:
                self.push(lk >> i)
            if (rk >> i) << i != rk:
                self.push((rk - 1) >> i)

    def update_from(self, k):
        k >>= 1
        while k > 0:
            self.Dat[k] = self.Op(self.Dat[k * 2], self.Dat[k * 2 + 1])
            k >>= 1

    def update_from_range(self, lk, rk):
        for i in range(1, self.Log + 1):
            if (lk >> i) << i != lk:
                self.Dat[lk >> i] = self.Op(self.Dat[(lk >> i) * 2], self.Dat[(lk >> i) * 2 + 1])
            if (rk >> i) << i != rk:
                self.Dat[(rk - 1) >> i] = self.Op(self.Dat[((rk - 1) >> i) * 2], self.Dat[((rk - 1) >> i) * 2 + 1])

    def set(self, p, x):
        if p < 0 or p >= self.MAX:
            raise IndexError(f"Index {p} is not in [0, {self.MAX}).")
        p += self.N
        self.push_to(p)
        self.Dat[p] = x
        self.update_from(p)

    def get(self, p):
        if p < 0 or p >= self.MAX:
            raise IndexError(f"Index {p} is not in [0, {self.MAX}).")
        p += self.N
        self.push_to(p)
        return self.Dat[p]

    def all_prod(self):
        return self.Dat[1]

    def apply(self, p, f):
        if p < 0 or p >= self.MAX:
            raise IndexError(f"Index {p} is not in [0, {self.MAX}).")
        p += self.N
        self.push_to(p)
        self.Dat[p] = self.Mapping(f, self.Dat[p])
        self.update_from(p)

    def apply_range(self, l, r, f):
        if l > r:
            raise ValueError(f"Invalid range: [{l}, {r}).")
        if l < 0 or l > self.MAX or r < 0 or r > self.MAX:
            raise IndexError(f"Range [{l}, {r}) is
