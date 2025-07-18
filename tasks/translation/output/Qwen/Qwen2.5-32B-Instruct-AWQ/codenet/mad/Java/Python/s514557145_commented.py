MOD1 = 1000000007
MOD2 = 998244353

def modInv(x):
    return modPow(x, MOD2 - 2)

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

class LazySegTree:
    def __init__(self, n, op, e, mapping, composition, id):
        self.MAX = n
        k = 1
        while k < n:
            k <<= 1
        self.N = k
        self.Log = self.N.bit_length() - 1
        self.Op = op
        self.E = e
        self.Mapping = mapping
        self.Composition = composition
        self.Id = id
        self.Dat = [self.E] * (self.N << 1)
        self.Laz = [self.Id] * self.N

    def __init__(self, dat, op, e, mapping, composition, id):
        self.__init__(len(dat), op, e, mapping, composition, id)
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

    def pushTo(self, k):
        for i in range(self.Log, 0, -1):
            self.push(k >> i)

    def pushTo(self, lk, rk):
        for i in range(self.Log, 0, -1):
            if ((lk >> i) << i) != lk:
                self.push(lk >> i)
            if ((rk >> i) << i) != rk:
                self.push(rk >> i)

    def updateFrom(self, k):
        k >>= 1
        while k > 0:
            self.Dat[k] = self.Op(self.Dat[k << 1 | 0], self.Dat[k << 1 | 1])
            k >>= 1

    def updateFrom(self, lk, rk):
        for i in range(1, self.Log + 1):
            if ((lk >> i) << i) != lk:
                lki = lk >> i
                self.Dat[lki] = self.Op(self.Dat[lki << 1 | 0], self.Dat[lki << 1 | 1])
            if ((rk >> i) << i) != rk:
                rki = (rk - 1) >> i
                self.Dat[rki] = self.Op(self.Dat[rki << 1 | 0], self.Dat[rki << 1 | 1])

    def set(self, p, x):
        self.exclusiveRangeCheck(p)
        p += self.N
        self.pushTo(p)
        self.Dat[p] = x
        self.updateFrom(p)

    def get(self, p):
        self.exclusiveRangeCheck(p)
        p += self.N
        self.pushTo(p)
        return self.Dat[p]

    def allProd(self):
        return self.Dat[1]

    def apply(self, p, f):
        self.exclusiveRangeCheck(p)
        p += self.N
        self.pushTo(p)
        self.Dat[p] = self.Mapping(f, self.Dat[p])
        self.updateFrom(p)

    def apply(self, l, r, f):
        if l > r:
            raise ValueError(f"Invalid range: [{l}, {r})")
        self.inclusiveRangeCheck(l)
        self.inclusiveRangeCheck(r)
        if l == r:
            return
        l += self.N
        r += self.N
        self.pushTo(l, r)
        l2, r2 = l, r
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
        self.updateFrom(l, r)

    def maxRight(self, l, g):
        self.inclusiveRangeCheck(l)
        if not g(self.E):
            raise ValueError("Identity element must satisfy the condition.")
        if l == self.MAX:
            return self.MAX
        l += self.N
        self.pushTo(l)
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
            if (l & -l) == l:
                break
        return self.MAX

    def minLeft(self, r, g):
        self.inclusiveRangeCheck(r)
        if not g(self.E):
            raise ValueError("Identity element must satisfy the condition.")
        if r == 0:
            return 0
        r += self.N
        self.pushTo(r - 1)
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

    def exclusiveRangeCheck(self, p):
        if p < 0 or p >= self.MAX:
            raise IndexError(f"Index {p} is not in [{0}, {self.MAX}).")

    def inclusiveRangeCheck(self, p):
        if p < 0 or p > self.MAX:
            raise IndexError(f"Index {p} is not in [{0}, {self.MAX}].")

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = bytearray(1024)
        self.curbuf = 0
        self.lenbuf = 0

    def hasNextByte(self):
        if self.curbuf >= self.lenbuf:
            self.curbuf = 0
            try:
                self.lenbuf = self.stream.readinto(self.buffer)
            except Exception as e:
                raise ValueError("Input mismatch") from e
            if self.lenbuf <= 0:
                return False
        return True

    def readByte(self):
        if self.hasNextByte():
            byte = self.buffer[self.curbuf]
            self.curbuf += 1
            return byte
        return -1

    def isSpaceChar(self, c):
        return not (33 <= c <= 126)

    def skip(self):
        while self.hasNextByte() and self.isSpaceChar(self.buffer[self.curbuf]):
            self.curbuf += 1

    def hasNext(self):
        self.skip()
        return self.hasNextByte()

    def next(self):
        if not self.hasNext():
            raise StopIteration("No more elements")
        sb = bytearray()
        b = self.readByte()
        while not self.isSpaceChar(b):
            sb.append(b)
            b = self.readByte()
        return sb.decode()

    def nextInt(self):
        if not self.hasNext():
            raise StopIteration("No more elements")
        c = self.readByte()
        while self.isSpaceChar(c):
            c = self.readByte()
        minus = False
        if c == ord('-'):
            minus = True
            c = self.readByte()
        res = 0
        while True:
            if c < ord('0') or c > ord('9'):
                raise ValueError("Input mismatch")
            res = res * 10 + c - ord('0')
            c = self.readByte()
            if self.isSpaceChar(c):
                break
        return -res if minus else res

    def nextLong(self):
        if not self.hasNext():
            raise StopIteration("No more elements")
        c = self.readByte()
        while self.isSpaceChar(c):
            c = self.readByte()
        minus = False
        if c == ord('-'):
            minus = True
            c = self.readByte()
        res = 0
        while True:
            if c < ord('0') or c > ord('9'):
                raise ValueError("Input mismatch")
            res = res * 10 + c - ord('0')
            c = self.readByte()
            if self.isSpaceChar(c):
                break
        return -res if minus else res

    def nextDouble(self):
        return float(self.next())

    def nextIntArray(self, n):
        return [self.nextInt() for _ in range(n)]

    def nextLongArray(self, n):
        return [self.nextLong() for _ in range(n)]

    def nextCharMap(self, n, m):
        return [self.next().encode() for _ in range(n)]

if __name__ == "__main__":
    inv9 = modInv(9)
    tenmod = [1]
    sc = InputReader(sys.stdin.buffer)
    N = sc.nextInt()
    Q = sc.nextInt()
    for j in range(1, N + 1):
        tenmod.append((tenmod[-1] * 10) % MOD2)
    dat = [S(tenmod[N - i - 1], i, i) for i in range(N)]
    lazySegTree = LazySegTree(dat, S.op, S.E, S.map, F.composite, F.I)
    for _ in range(Q):
        l = sc.nextInt() - 1
        r = sc.nextInt() - 1
        D = sc.nextLong()
        lazySegTree.apply(l, r + 1, F(D, N))
        print(lazySegTree.allProd().sum)
# End of Code
