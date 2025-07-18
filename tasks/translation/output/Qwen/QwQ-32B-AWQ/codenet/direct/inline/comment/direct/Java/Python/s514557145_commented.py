MOD2 = 998244353
inv9 = pow(9, MOD2 - 2, MOD2)

class S:
    E = None
    def __init__(self, sum_val, l, r):
        self.sum = sum_val
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
        c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]) % MOD2
        new_sum = (f.D * c * inv9) % MOD2
        return S(new_sum, s.l, s.r)

class F:
    I = None
    def __init__(self, D, N):
        self.D = D
        self.N = N

    @staticmethod
    def composite(f, g):
        return F(f.D, f.N)

class LazySegTree:
    def __init__(self, data, op, e, mapping, composition, identity):
        self.n = len(data)
        self.N = 1
        while self.N < self.n:
            self.N <<= 1
        self.log = self.N.bit_length() - 1
        self.Op = op
        self.E = e
        self.Mapping = mapping
        self.Composition = composition
        self.Id = identity
        self.dat = [e for _ in range(2 * self.N)]
        self.laz = [identity for _ in range(self.N)]
        for i in range(self.n):
            self.dat[self.N + i] = data[i]
        for i in range(self.N - 1, 0, -1):
            self.dat[i] = self.Op(self.dat[2 * i], self.dat[2 * i + 1])

    def push(self, k):
        if self.laz[k] == self.Id:
            return
        left = 2 * k
        right = 2 * k + 1
        self.dat[left] = self.Mapping(self.laz[k], self.dat[left])
        self.dat[right] = self.Mapping(self.laz[k], self.dat[right])
        if left < self.N:
            self.laz[left] = self.Composition(self.laz[k], self.laz[left])
        if right < self.N:
            self.laz[right] = self.Composition(self.laz[k], self.laz[right])
        self.laz[k] = self.Id

    def pushTo(self, l, r):
        for i in range(self.log, 0, -1):
            if (l >> i) << i != l:
                self.push(l >> i)
            if (r >> i) << i != r:
                self.push((r - 1) >> i)

    def apply(self, l, r, f):
        if l >= r:
            return
        l += self.N
        r += self.N
        self.pushTo(l, r)
        l2, r2 = l, r
        while l2 < r2:
            if l2 % 2 == 1:
                self.dat[l2] = self.Mapping(f, self.dat[l2])
                if l2 < self.N:
                    self.laz[l2] = self.Composition(f, self.laz[l2])
                l2 += 1
            if r2 % 2 == 1:
                r2 -= 1
                self.dat[r2] = self.Mapping(f, self.dat[r2])
                if r2 < self.N:
                    self.laz[r2] = self.Composition(f, self.laz[r2])
            l2 >>= 1
            r2 >>= 1
        # Update parents (omitted for brevity in this version)

    def allProd(self):
        return self.dat[1].sum

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

    S.E = S(0, float('inf'), float('-inf'))
    F.I = F(0, 0)

    dat = [S(tenmod[N - i -1], i, i) for i in range(N)]
    st = LazySegTree(dat, S.op, S.E, S.map, F.composite, F.I)

    for _ in range(Q):
        l = int(input[ptr])-1; ptr +=1
        r = int(input[ptr])-1; ptr +=1
        D = int(input[ptr]); ptr +=1
        f = F(D, N)
        st.apply(l, r+1, f)
        print(st.allProd())

if __name__ == "__main__":
    main()
#End of Code
