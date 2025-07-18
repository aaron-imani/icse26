class S:
    tenmod = None
    E = None
    def __init__(self, sum_val, l_val, r_val):
        self.sum = sum_val
        self.l = l_val
        self.r = r_val

    @staticmethod
    def op(s1, s2):
        new_sum = (s1.sum + s2.sum) % MOD2
        new_l = min(s1.l, s2.l)
        new_r = max(s1.r, s2.r)
        return S(new_sum, new_l, new_r)

    @staticmethod
    def map(f, s):
        tm = S.tenmod
        c = (tm[f.N - s.l] - tm[f.N - s.r - 1]) % MOD2
        if c < 0:
            c += MOD2
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

    @staticmethod
    def identity():
        return F(0, 0)

MOD1 = 10**9 + 7
MOD2 = 998244353

def modInv(x):
    return pow(x, MOD2-2, MOD2)

inv9 = modInv(9)

class LazySegTree:
    def __init__(self, dat, op, e, mapping, composition, identity):
        self.N = 1
        while self.N < len(dat):
            self.N <<= 1
        self.size = self.N
        self.Log = (self.N).bit_length() - 1

        self.Dat = [e] * (2 * self.N)
        self.Laz = [identity()] * self.N

        for i in range(len(dat)):
            self.Dat[self.N + i] = dat[i]
        for i in range(self.N-1, 0, -1):
            self.Dat[i] = op(self.Dat[2*i], self.Dat[2*i+1])

        self.op = op
        self.e = e
        self.mapping = mapping
        self.composition = composition
        self.identity = identity

    def apply(self, l, r, f):
        if l > r:
            return
        if l == r:
            return
        orig_l_adj = l + self.N
        orig_r_adj = r + self.N
        l += self.N
        r += self.N
        self.push_to(l, r)
        while l < r:
            if l % 2 == 1:
                self.Dat[l] = self.mapping(f, self.Dat[l])
                if l < self.N:
                    self.Laz[l] = self.composition(f, self.Laz[l])
                l += 1
            if r % 2 == 1:
                r -= 1
                self.Dat[r] = self.mapping(f, self.Dat[r])
                if r < self.N:
                    self.Laz[r] = self.composition(f, self.Laz[r])
            l >>= 1
            r >>= 1
        self.update_from(orig_l_adj, orig_r_adj)

    def allProd(self):
        return self.Dat[1].sum

    def push_to(self, l, r):
        for i in range(self.Log, 0, -1):
            if (l >> i) << i != l:
                self.push(l >> i)
            if (r >> i) << i != r:
                self.push((r - 1) >> i)

    def push(self, k):
        if self.Laz[k] == self.identity():
            return
        left = 2 * k
        right = 2 * k + 1
        self.Dat[left] = self.mapping(self.Laz[k], self.Dat[left])
        self.Dat[right] = self.mapping(self.Laz[k], self.Dat[right])
        if left < self.N:
            self.Laz[left] = self.composition(self.Laz[k], self.Laz[left])
        if right < self.N:
            self.Laz[right] = self.composition(self.Laz[k], self.Laz[right])
        self.Laz[k] = self.identity()

    def update_from(self, l, r):
        for i in range(1, self.Log + 1):
            if (l >> i) << i != l:
                lk = l >> i
                self.Dat[lk] = self.op(self.Dat[2 * lk], self.Dat[2 * lk + 1])
            if (r >> i) << i != r:
                rk = (r - 1) >> i
                self.Dat[rk] = self.op(self.Dat[2 * rk], self.Dat[2 * rk + 1])

def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    S.E = S(0, float('inf'), -float('inf'))
    F.I = F(0, 0)
    N = int(input[ptr]); ptr += 1
    Q = int(input[ptr]); ptr += 1

    S.tenmod = [0] * (N + 1)
    S.tenmod[0] = 1
    for j in range(1, N + 1):
        S.tenmod[j] = (S.tenmod[j-1] * 10) % MOD2

    dat = [None] * N
    for i in range(N):
        dat[i] = S(S.tenmod[N - i - 1], i, i)

    def op(s1, s2):
        return S.op(s1, s2)

    def mapping(f, s):
        return S.map(f, s)

    def composition(f, g):
        return F.composite(f, g)

    def identity():
        return F.identity()

    e = S.E

    segtree = LazySegTree(dat, op, e, mapping, composition, identity)

    for _ in range(Q):
        l = int(input[ptr])-1; ptr +=1
        r = int(input[ptr])-1; ptr +=1
        D = int(input[ptr]); ptr +=1
        f = F(D, N)
        segtree.apply(l, r+1, f)
        print(segtree.allProd())

if __name__ == '__main__':
    main()
# End of Code
