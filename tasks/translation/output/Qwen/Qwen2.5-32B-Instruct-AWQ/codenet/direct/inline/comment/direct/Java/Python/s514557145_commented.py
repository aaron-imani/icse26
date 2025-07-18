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
        self.Log = (self.N - 1).bit_length()
        self.Op = op
        self.E = E
        self.Mapping = mapping
        self.Composition = composition
        self.Id = Id
        self.Dat = [E] * (self.N * 2)
        self.Laz = [Id] * self.N
        self.build(dat)

    def build(self, dat):
        for i in range(self.MAX):
            self.Dat[self.N + i] = dat[i]
        for i in range(self.N - 1, 0, -1):
            self.Dat[i] = self.Op(self.Dat[i << 1], self.Dat[i << 1 | 1])

    def push_to(self, k):
        for i in range(self.Log, 0, -1):
            self.push(k >> i)

    def push(self, k):
        if self.Laz[k] == self.Id:
            return
        self.Dat[k << 1] = self.Mapping(self.Laz[k], self.Dat[k << 1])
        self.Dat[k << 1 | 1] = self.Mapping(self.Laz[k], self.Dat[k << 1 | 1])
        if k < self.N:
            self.Laz[k << 1] = self.Composition(self.Laz[k], self.Laz[k << 1])
            self.Laz[k << 1 | 1] = self.Composition(self.Laz[k], self.Laz[k << 1 | 1])
        self.Laz[k] = self.Id

    def update_from(self, k):
        while k > 1:
            k >>= 1
            self.Dat[k] = self.Op(self.Dat[k << 1], self.Dat[k << 1 | 1])

    def apply(self, l, r, f):
        if l > r:
            raise ValueError("Invalid range")
        l += self.N
        r += self.N
        self.push_to(l)
        self.push_to(r - 1)
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
        self.update_from(l0)
        self.update_from(r0 - 1)

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
    tenmod.extend([0] * (N + 1))
    for j in range(1, N + 1):
        tenmod[j] = (tenmod[j - 1] * 10) % MOD2

    dat = [S(tenmod[N - i - 1], i, i) for i in range(N)]
    lazy_seg_tree = LazySegTree(dat, S.op, S(0, float('inf'), -float('inf')), S.map, F.composite, F(0, 0))

    for _ in range(Q):
        l = input_reader.next_int() - 1
        r = input_reader.next_int() - 1
        D = input_reader.next_long()
        lazy_seg_tree.apply(l, r + 1, F(D, N))
        print(lazy_seg_tree.all_prod().sum)

# End of Code
