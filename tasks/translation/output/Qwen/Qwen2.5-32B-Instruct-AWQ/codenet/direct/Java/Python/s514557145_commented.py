MOD1 = 1000000007
MOD2 = 998244353

def mod_inv(x):
    return mod_pow(x, MOD2 - 2)

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
        c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1])
        if c < 0:
            c += MOD2
        return S(((f.D * c) % MOD2 * mod_inv(9)) % MOD2, s.l, s.r)

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
        self.Dat = [e] * (n * 2)
        self.Laz = [id] * n

    def __init__(self, dat, op, e, mapping, composition, id):
        self.MAX = len(dat)
        k = 1
        while k < len(dat):
            k <<= 1
        self.N = k
        self.Log = k.bit_length() - 1
        self.Op = op
        self.E = e
        self.Mapping = mapping
        self.Composition = composition
        self.Id = id
        self.Dat = [e] * (k * 2)
        self.Laz = [id] * k
        self.build(dat)

    def build(self, dat):
        l = len(dat)
        self.Dat[self.N:self.N + l] = dat
        for i in range(self.N - 1, 0, -1):
            self.Dat[i] = self.Op(self.Dat[i << 1 | 0], self.Dat[i << 1 | 1])

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

    def push_to(self, k):
        for i in range(self.Log, 0, -1):
            self.push(k >> i)

    def push_to_range(self, lk, rk):
        for i in range(self.Log, 0, -1):
            if ((lk >> i) << i) != lk:
                self.push(lk >> i)
            if ((rk >> i) << i) != rk:
                self.push(rk >> i)

    def update_from(self, k):
        k >>= 1
        while k > 0:
            self.Dat[k] = self.Op(self.Dat[k << 1 | 0], self.Dat[k << 1 | 1])
            k >>= 1

    def update_from_range(self, lk, rk):
        for i in range(1, self.Log + 1):
            if ((lk >> i) << i) != lk:
                lki = lk >> i
                self.Dat[lki] = self.Op(self.Dat[lki << 1 | 0], self.Dat[lki << 1 | 1])
            if ((rk >> i) << i) != rk:
                rki = (rk - 1) >> i
                self.Dat[rki] = self.Op(self.Dat[rki << 1 | 0], self.Dat[rki << 1 | 1])

    def set(self, p, x):
        self.exclusive_range_check(p)
        p += self.N
        self.push_to(p)
        self.Dat[p] = x
        self.update_from(p)

    def get(self, p):
        self.exclusive_range_check(p)
        p += self.N
        self.push_to(p)
        return self.Dat[p]

    def all_prod(self):
        return self.Dat[1]

    def apply(self, p, f):
        self.exclusive_range_check(p)
        p += self.N
        self.push_to(p)
        self.Dat[p] = self.Mapping(f, self.Dat[p])
        self.update_from(p)

    def apply_range(self, l, r, f):
        if l > r:
            raise ValueError(f"Invalid range: [{l}, {r})")
        self.inclusive_range_check(l)
        self.inclusive_range_check(r)
        if l == r:
            return
        l += self.N
        r += self.N
        self.push_to_range(l, r)
        while l < r:
            if (l & 1) == 1:
                self.Dat[l] = self.Mapping(f, self.Dat[l])
                if l < self.N:
                    self.Laz[l] = self.Composition(f, self.Laz[l])
                l += 1
            if (r & 1) == 1:
                r -= 1
                self.Dat[r] = self.Mapping(f, self.Dat[r])
                if r < self.N:
                    self.Laz[r] = self.Composition(f, self.Laz[r])
            l >>= 1
            r >>= 1
        self.update_from_range(l, r)

    def max_right(self, l, g):
        self.inclusive_range_check(l)
        if not g(self.E):
            raise ValueError("Identity element must satisfy the condition.")
        if l == self.MAX:
            return self.MAX
        l += self.N
        self.push_to(l)
        sum = self.E
        while True:
            l >>= l.bit_length() - 1
            if not g(self.Op(sum, self.Dat[l])):
                while l < self.N:
                    self.push(l)
                    l <<= 1
                    if g(self.Op(sum, self.Dat[l])):
                        sum = self.Op(sum, self.Dat[l])
                        l += 1
                return l - self.N
            sum = self.Op(sum, self.Dat[l])
            l += 1
            if (l & -l) != l:
                break
        return self.MAX

    def min_left(self, r, g):
        self.inclusive_range_check(r)
        if not g(self.E):
            raise ValueError("Identity element must satisfy the condition.")
        if r == 0:
            return 0
        r += self.N
        self.push_to(r - 1)
        sum = self.E
        while True:
            r -= 1
            while r > 1 and (r & 1) == 1:
                r >>= 1
            if not g(self.Op(self.Dat[r], sum)):
                while r < self.N:
                    self.push(r)
                    r = r << 1 | 1
                    if g(self.Op(self.Dat[r], sum)):
                        sum = self.Op(self.Dat[r], sum)
                        r -= 1
                return r + 1 - self.N
            sum = self.Op(self.Dat[r], sum)
            if (r & -r) == r:
                break
        return 0

    def exclusive_range_check(self, p):
        if p < 0 or p >= self.MAX:
            raise IndexError(f"Index {p} is not in [{0}, {self.MAX}).")

    def inclusive_range_check(self, p):
        if p < 0 or p > self.MAX:
            raise IndexError(f"Index {p} is not in [{0}, {self.MAX}].")

class InputReader:
    def __init__(self, in_stream):
        self.in_stream = in_stream
        self.buffer = bytearray(1024)
        self.curbuf = self.lenbuf = 0

    def has_next_byte(self):
        if self.curbuf >= self.lenbuf:
            self.curbuf = 0
            try:
                self.lenbuf = self.in_stream.readinto(self.buffer)
            except Exception:
                raise EOFError("Input stream has ended unexpectedly.")
            if self.lenbuf <= 0:
                return False
        return True

    def read_byte(self):
        if self.has_next_byte():
            b = self.buffer[self.curbuf]
            self.curbuf += 1
            return b
        else:
            return -1

    def is_space_char(self, c):
        return not (33 <= c <= 126)

    def skip(self):
        while self.has_next_byte() and self.is_space_char(self.buffer[self.curbuf]):
            self.curbuf += 1

    def has_next(self):
        self.skip()
        return self.has_next_byte()

    def next(self):
        if not self.has_next():
            raise EOFError("No more input available.")
        sb = bytearray()
        b = self.read_byte()
        while not self.is_space_char(b):
            sb.append(b)
            b = self.read_byte()
        return sb.decode()

    def next_int(self):
        if not self.has_next():
            raise EOFError("No more input available.")
        c = self.read_byte()
        while self.is_space_char(c):
            c = self.read_byte()
        minus = False
        if c == ord('-'):
            minus = True
            c = self.read_byte()
        res = 0
        while True:
            if not (ord('0') <= c <= ord('9')):
                raise ValueError("Invalid input character.")
            res = res * 10 + c - ord('0')
            c = self.read_byte()
            if self.is_space_char(c):
                break
        return -res if minus else res

    def next_long(self):
        if not self.has_next():
            raise EOFError("No more input available.")
        c = self.read_byte()
        while self.is_space_char(c):
            c = self.read_byte()
        minus = False
        if c == ord('-'):
            minus = True
            c = self.read_byte()
        res = 0
        while True:
            if not (ord('0') <= c <= ord('9')):
                raise ValueError("Invalid input character.")
            res = res * 10 + c - ord('0')
            c = self.read_byte()
            if self.is_space_char(c):
                break
        return -res if minus else res

    def next_double(self):
        return float(self.next())

    def next_int_array(self, n):
        return [self.next_int() for _ in range(n)]

    def next_long_array(self, n):
        return [self.next_long() for _ in range(n)]

    def next_char_map(self, n, m):
        return [self.next().encode() for _ in range(n)]

# Main function
if __name__ == "__main__":
    import sys
    input_reader = InputReader(sys.stdin.buffer)
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
        lazy_seg_tree.apply_range(l, r + 1, F(D, N))
        print(lazy_seg_tree.all_prod().sum)
# End of Code
