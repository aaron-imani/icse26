MOD1 = 1000000007
MOD2 = 998244353
tenmod = [1]

def mod_inv(x):
    return pow(x, MOD2 - 2, MOD2)

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
        return S((f.D * c * mod_inv(9)) % MOD2, s.l, s.r)

class F:
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
        if l >= r:
            return
        l += self.N
        r += self.N
        h = 0
        while (1 << h) < self.N:
            if (l >> h) & 1:
                self.push(l >> h)
                l += 1 << h
            if (r >> h) & 1:
                r -= 1 << h
                self.push((r - 1) >> h)
            h += 1
        l0, r0 = l, r
        while l < r:
            if l & 1:
                self.all_apply(l, f)
                l += 1
            if r & 1:
                r -= 1
                self.all_apply(r, f)
            l >>= 1
            r >>= 1
        l, r = l0, r0
        while h > 0:
            h -= 1
            if (l >> h) & 1:
                self.update(l >> h)
                l += 1 << h
            if (r >> h) & 1:
                r -= 1 << h
                self.update((r - 1) >> h)

    def all_apply(self, k, f):
        self.Dat[k] = self.Mapping(f, self.Dat[k])
        if k < self.N:
            self.Laz[k] = self.Composition(f, self.Laz[k])

    def update(self, k):
        self.Dat[k] = self.Op(self.Dat[k << 1], self.Dat[k << 1 | 1])

    def push(self, k):
        if self.Laz[k] == self.Id:
            return
        self.all_apply(k << 1, self.Laz[k])
        self.all_apply(k << 1 | 1, self.Laz[k])
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
        return self.buffer[self.ptr]

    def next_int(self):
        return int(self.next_line())

    def next_long(self):
        return int(self.next_line())

if __name__ == "__main__":
    import sys
    input_reader = InputReader(sys.stdin)
    N = input_reader.next_int()
    Q = input_reader.next_int()
    tenmod.extend([0] * (N))
    for j in range(1, N + 1):
        tenmod[j] = (tenmod[j - 1] * 10) % MOD2
    dat = [S(tenmod[N - i - 1], i, i) for i in range(N)]
    lazy_seg_tree = LazySegTree(dat, S.op, S(0, float('inf') // 2, -float('inf') // 2), S.map, F.composite, F(0, 0))
    for _ in range(Q):
        l = input_reader.next_int() - 1
        r = input_reader.next_int() - 1
        D = input_reader.next_long()
        lazy_seg_tree.apply(l, r + 1, F(D, N))
        print(lazy_seg_tree.all_prod().sum)
# End of Code
