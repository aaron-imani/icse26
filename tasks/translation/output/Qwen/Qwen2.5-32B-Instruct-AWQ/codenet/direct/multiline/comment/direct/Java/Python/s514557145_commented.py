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
        c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1])
        if c < 0:
            c += MOD2
        return S(((f.D * c) % MOD2 * mod_inv(9)) % MOD2, s.l, s.r)

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

    def apply(self, l, r, f):
        if l > r:
            raise ValueError(f"Invalid range: [{l}, {r})")
        l += self.N
        r += self.N
        for i in range(self.Log, -1, -1):
            if (l >> i) << i != l:
                self.push(l >> i)
            if (r >> i) << i != r:
                self.push((r - 1) >> i)
        l0, r0 = l, r
        while l < r:
            if l & 1:
                self.Dat[l] = self.Mapping(f, self.Dat[l])
                if l < self.N:
                    self.Laz[l] = self.Composition(f, self.Laz[l])
                l += 1
            if r & 1:
                r -= 1
                self.Dat[r] = self.Mapping(f, self.Dat[r])
                if r < self.N:
                    self.Laz[r] = self.Composition(f, self.Laz[r])
            l >>= 1
            r >>= 1
        self.update_from(l0, r0)

    def update_from(self, l, r):
        for i in range(1, self.Log + 1):
            if (l >> i) << i != l:
                self.Dat[l >> i] = self.Op(self.Dat[l >> i << 1], self.Dat[l >> i << 1 | 1])
            if (r >> i) << i != r:
                self.Dat[(r - 1) >> i] = self.Op(self.Dat[(r - 1) >> i << 1], self.Dat[(r - 1) >> i << 1 | 1])

    def push(self, k):
        if self.Laz[k] == self.Id:
            return
        self.Dat[k << 1] = self.Mapping(self.Laz[k], self.Dat[k << 1])
        self.Dat[k << 1 | 1] = self.Mapping(self.Laz[k], self.Dat[k << 1 | 1])
        if k < self.N:
            self.Laz[k << 1] = self.Composition(self.Laz[k], self.Laz[k << 1])
            self.Laz[k << 1 | 1] = self.Composition(self.Laz[k], self.Laz[k << 1 | 1])
        self.Laz[k] = self.Id

    def all_prod(self):
        return self.Dat[1]

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = []
        self.ptr = 0

    def next_line(self):
        if self.ptr == len(self.buffer):
            self.buffer = self.stream.readline().split()
            self.ptr = 0
        result = self.buffer[self.ptr]
        self.ptr += 1
        return result

    def next_int(self):
        return int(self.next_line())

    def next_long(self):
        return int(self.next_line())

if __name__ == "__main__":
    import sys
    input_reader = InputReader(sys.stdin)
    N = input_reader.next_int()
    Q = input_reader.next_int()
    tenmod = [1] * (N + 1)
    for j in range(1, N + 1):
        tenmod[j] = (tenmod[j - 1] * 10) % MOD2
    dat = [S(tenmod[N - i - 1], i, i) for i in range(N)]
    lazy_seg_tree = LazySegTree(dat, S.op, S.E, S.map, F.composite, F.I)
    for _ in range(Q):
        l = input_reader.next_int() - 1
        r = input_reader.next_int() - 1
        D = input_reader.next_long()
        lazy_seg_tree.apply(l, r + 1, F(D, N))
        print(lazy_seg_tree.all_prod().sum)
# End of Code
