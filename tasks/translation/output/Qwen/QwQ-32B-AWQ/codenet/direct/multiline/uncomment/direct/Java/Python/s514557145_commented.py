MOD2 = 998244353
inv9 = pow(9, MOD2 - 2, MOD2)

class S:
    __slots__ = ['sum', 'l', 'r']
    E = None

    def __init__(self, sum_val, l_val, r_val):
        self.sum = sum_val % MOD2
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
        N = f.N
        c = (tenmod[N - s.l] - tenmod[N - s.r - 1]) % MOD2
        new_sum = (f.D * c) % MOD2
        new_sum = (new_sum * inv9) % MOD2
        return S(new_sum, s.l, s.r)

class F:
    __slots__ = ['D', 'N']
    I = None

    def __init__(self, D, N):
        self.D = D
        self.N = N

    @staticmethod
    def composite(f, g):
        return F(f.D, f.N)

class LazySegTree:
    def __init__(self, dat, op_func, e, mapping_func, composition_func, id_f):
        self.MAX = len(dat)
        self.N = 1
        while self.N < self.MAX:
            self.N <<= 1
        self.Log = self.N.bit_length() - 1
        self.op_func = op_func
        self.e = e
        self.mapping_func = mapping_func
        self.composition_func = composition_func
        self.id_f = id_f
        self.size = self.N * 2
        self.Dat = [self.e] * self.size
        for i in range(self.MAX):
            self.Dat[self.N + i] = dat[i]
        for i in range(self.N - 1, 0, -1):
            self.Dat[i] = self.op_func(self.Dat[2 * i], self.Dat[2 * i + 1])
        self.Laz = [self.id_f] * (self.N + 1)

    def push_to(self, k):
        for i in range(self.Log, 0, -1):
            self.push(k >> i)

    def push_to_range(self, l, r):
        for i in range(self.Log, 0, -1):
            if ((l >> i) << i) != l:
                self.push(l >> i)
            if (((r - 1) >> i) << i) != (r - 1):
                self.push((r - 1) >> i)

    def push(self, k):
        if self.Laz[k] == self.id_f:
            return
        lk = 2 * k
        rk = 2 * k + 1
        self.Dat[lk] = self.mapping_func(self.Laz[k], self.Dat[lk])
        self.Dat[rk] = self.mapping_func(self.Laz[k], self.Dat[rk])
        if lk < self.N:
            self.Laz[lk] = self.composition_func(self.Laz[k], self.Laz[lk])
        if rk < self.N:
            self.Laz[rk] = self.composition_func(self.Laz[k], self.Laz[rk])
        self.Laz[k] = self.id_f

    def apply(self, l, r, f):
        if l > r:
            return
        if l == r:
            return
        l += self.N
        r += self.N
        self.push_to_range(l, r)
        l2, r2 = l, r
        while l2 < r2:
            if (l2 & 1) == 1:
                self.Dat[l2] = self.mapping_func(f, self.Dat[l2])
                if l2 < self.N:
                    self.Laz[l2] = self.composition_func(f, self.Laz[l2])
                l2 += 1
            if (r2 & 1) == 1:
                r2 -= 1
                self.Dat[r2] = self.mapping_func(f, self.Dat[r2])
                if r2 < self.N:
                    self.Laz[r2] = self.composition_func(f, self.Laz[r2])
            l2 >>= 1
            r2 >>= 1
        self.update_from(l, r)

    def update_from(self, l, r):
        for i in range(1, self.Log + 1):
            if ((l >> i) << i) != l:
                lki = l >> i
                self.Dat[lki] = self.op_func(self.Dat[2 * lki], self.Dat[2 * lki + 1])
            if (((r - 1) >> i) << i) != (r - 1):
                rki = (r - 1) >> i
                self.Dat[rki] = self.op_func(self.Dat[2 * rki], self.Dat[2 * rki + 1])

    def allProd(self):
        return self.Dat[1]

def main():
    import sys
    input = sys.stdin.read().split()
    idx = 0
    N = int(input[idx]); idx += 1
    Q = int(input[idx]); idx += 1

    global tenmod
    tenmod = [0] * (N + 1)
    tenmod[0] = 1
    for j in range(1, N + 1):
        tenmod[j] = (tenmod[j - 1] * 10) % MOD2

    S.E = S(0, (1 << 63), -(1 << 63))
    F.I = F(0, 0)

    dat = []
    for i in range(N):
        val = tenmod[N - i - 1]
        dat.append(S(val, i, i))

    seg_tree = LazySegTree(
        dat,
        S.op,
        S.E,
        S.map,
        F.composite,
        F.I
    )

    out = []
    for _ in range(Q):
        l = int(input[idx])-1; idx +=1
        r = int(input[idx])-1; idx +=1
        D = int(input[idx]); idx +=1
        seg_tree.apply(l, r+1, F(D, N))
        out.append(seg_tree.allProd().sum)
    print('\n'.join(map(str, out)))

if __name__ == "__main__":
    main()
# End of Code
