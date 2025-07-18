MOD1 = 1000000007
MOD2 = 998244353
tenmod = []
inv9 = pow(9, -1, MOD2)

class S:
    E = None
    def __init__(self, sum, l, r):
        self.sum = sum
        self.l = l
        self.r = r

    @staticmethod
    def op(s1, s2):
        sum = (s1.sum + s2.sum) % MOD2
        return S(sum, min(s1.l, s2.l), max(s1.r, s2.r))

    @staticmethod
    def map(f, s):
        c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]) % MOD2
        return S((f.D * c % MOD2 * inv9) % MOD2, s.l, s.r)

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

def modPow(x, y, mod):
    z = 1
    while y > 0:
        if y % 2 == 0:
            x = x * x % mod
            y //= 2
        else:
            z = z * x % mod
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
        self.Dat = [e] * (2 * self.N)
        self.Laz = [id] * self.N

    def build(self, dat):
        l = len(dat)
        for i in range(l):
            self.Dat[self.N + i] = dat[i]
        for i in range(self.N - 1, 0, -1):
            self.Dat[i] = self.Op(self.Dat[2 * i], self.Dat[2 * i + 1])

    def push(self, k):
        if self.Laz[k] == self.Id:
            return
        self.Dat[2 * k] = self.Mapping(self.Laz[k], self.Dat[2 * k])
        self.Dat[2 * k + 1] = self.Mapping(self.Laz[k], self.Dat[2 * k + 1])
        if 2 * k < self.N:
            self.Laz[2 * k] = self.Composition(self.Laz[k], self.Laz[2 * k])
            self.Laz[2 * k + 1] = self.Composition(self.Laz[k], self.Laz[2 * k + 1])
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
            self.Dat[k] = self.Op(self.Dat[2 * k], self.Dat[2 * k + 1])
            k >>= 1

    def update_from_range(self, lk, rk):
        for i in range(1, self.Log + 1):
            if (lk >> i) << i != lk:
                self.Dat[lk >> i] = self.Op(self.Dat[2 * (lk >> i)], self.Dat[2 * (lk >> i) + 1])
            if (rk >> i) << i != rk:
                self.Dat[(rk - 1) >> i] = self.Op(self.Dat[2 * ((rk - 1) >> i)], self.Dat[2 * ((rk - 1) >> i) + 1])

    def set(self, p, x):
        if p < 0 or p >= self.MAX:
            raise IndexError(f"Index {p} is not in [{0}, {self.MAX}).")
        p += self.N
        self.push_to(p)
        self.Dat[p] = x
        self.update_from(p)

    def get(self, p):
        if p < 0 or p >= self.MAX:
            raise IndexError(f"Index {p} is not in [{0}, {self.MAX}).")
        p += self.N
        self.push_to(p)
        return self.Dat[p]

    def all_prod(self):
        return self.Dat[1]

    def apply(self, p, f):
        if p < 0 or p >= self.MAX:
            raise IndexError(f"Index {p} is not in [{0}, {self.MAX}).")
        p += self.N
        self.push_to(p)
        self.Dat[p] = self.Mapping(f, self.Dat[p])
        self.update_from(p)

    def apply_range(self, l, r, f):
        if l > r:
            raise ValueError(f"Invalid range: [{l}, {r})")
        if l < 0 or l > self.MAX or r < 0 or r > self.MAX:
            raise IndexError(f"Range [{l}, {r}) is not in [{0}, {self.MAX}].")
        if l == r:
            return
        l += self.N
        r += self.N
        self.push_to_range(l, r)
        lk, rk = l, r
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
        self.update_from_range(lk, rk)

    def max_right(self, l, g):
        if l < 0 or l > self.MAX:
            raise IndexError(f"Index {l} is not in [{0}, {self.MAX}].")
        if not g(self.E):
            raise ValueError("Identity element must satisfy the condition.")
        if l == self.MAX:
            return self.MAX
        l += self.N
        self.push_to(l)
        sm = self.E
        while True:
            l >>= (l & -l).bit_length() - 1
            if not g(self.Op(sm, self.Dat[l])):
                while l < self.N:
                    self.push(l)
                    l <<= 1
                    if g(self.Op(sm, self.Dat[l])):
                        sm = self.Op(sm, self.Dat[l])
                        l += 1
                return l - self.N
            sm = self.Op(sm, self.Dat[l])
            if (l & -l) == l:
                break
        return self.MAX

    def min_left(self, r, g):
        if r < 0 or r > self.MAX:
            raise IndexError(f"Index {r} is not in [{0}, {self.MAX}].")
        if not g(self.E):
            raise ValueError("Identity element must satisfy the condition.")
        if r == 0:
            return 0
        r += self.N
        self.push_to(r - 1)
        sm = self.E
        while True:
            r -= 1
            while r > 1 and r & 1:
                r >>= 1
            if not g(self.Op(self.Dat[r], sm)):
                while r < self.N:
                    self.push(r)
                    r = r << 1 | 1
                    if g(self.Op(self.Dat[r], sm)):
                        sm = self.Op(self.Dat[r], sm)
                        r -= 1
                return r + 1 - self.N
            sm = self.Op(self.Dat[r], sm)
            if (r & -r) == r:
                break
        return 0

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = []
        self.pre_buf = []

    def next(self):
        while not self.buffer:
            line = self.stream.readline()
            if not line:
                break
            self.buffer = line.split()
        return self.buffer.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_float(self):
        return float(self.next())

    def next_str(self):
        return self.next()

    def next_line(self):
        if self.pre_buf:
            ret = ' '.join(self.pre_buf)
            self.pre_buf = []
            return ret
        ret = self.stream.readline().rstrip('\r\n')
        return ret

    def next_int_list(self, n):
        return [self.next_int() for _ in range(n)]

    def next_long_list(self, n):
        return [self.next_long() for _ in range(n)]

    def next_float_list(self, n):
        return [self.next_float() for _ in range(n)]

    def next_str_list(self, n):
        return [self.next_str() for _ in range(n)]

    def next_char_matrix(self, n):
        return [list(self.next()) for _ in range(n)]

    def next_int_matrix(self, n, m):
        return [self.next_int_list(m) for _ in range(n)]

    def next_long_matrix(self, n, m):
        return [self.next_long_list(m) for _ in range(n)]

    def next_float_matrix(self, n, m):
        return [self.next_float_list(m) for _ in range(n)]

    def next_str_matrix(self, n, m):
        return [self.next_str_list(m) for _ in range(n)]

import sys
input = sys.stdin.read
data = input().split()

N = int(data[0])
Q = int(data[1])
tenmod = [1] * (N + 1)
for j in range(1, N + 1):
    tenmod[j] = (tenmod[j - 1] * 10) % MOD2

dat = [S(tenmod[N - i - 1], i, i) for i in range(N)]
lazy_seg_tree = LazySegTree(N, S.op, S.E, S.map, F.composite, F.I)

idx = 2
for _ in range(Q):
    l = int(data[idx]) - 1
    r = int(data[idx + 1]) - 1
    D = int(data[idx + 2])
    idx += 3
    lazy_seg_tree.apply_range(l, r + 1, F(D, N))
    print(lazy_seg_tree.all_prod().sum)

# End of Code
