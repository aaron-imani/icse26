class S:
    E = None  # To be initialized

    def __init__(self, sum_val, l, r):
        self.sum = sum_val % MOD2
        self.l = l
        self.r = r

    @classmethod
    def set_E(cls):
        INF = 10**18
        cls.E = S(0, INF, -INF)

    @staticmethod
    def op(s1, s2):
        new_sum = (s1.sum + s2.sum) % MOD2
        new_l = min(s1.l, s2.l)
        new_r = max(s1.r, s2.r)
        return S(new_sum, new_l, new_r)

    @staticmethod
    def map(f, s):
        N = f.N
        term1 = tenmod[N - s.l]
        term2 = tenmod[N - s.r - 1]
        c = (term1 - term2) % MOD2
        new_sum = (f.D * c) % MOD2
        new_sum = (new_sum * inv9) % MOD2
        return S(new_sum, s.l, s.r)


class F:
    I = None

    def __init__(self, D, N):
        self.D = D
        self.N = N

    @classmethod
    def set_I(cls):
        cls.I = F(0, 0)

    @staticmethod
    def composite(f, g):
        return F(f.D, f.N)


def precompute_tenmod(N):
    tenmod = [0] * (N + 1)
    tenmod[0] = 1
    for j in range(1, N + 1):
        tenmod[j] = (tenmod[j-1] * 10) % MOD2
    return tenmod


class LazySegTree:
    def __init__(self, data, op, e, mapping, composition, identity):
        self.n = len(data)
        self.size = 1
        while self.size < self.n:
            self.size <<= 1
        self.log = self.size.bit_length() - 1
        self.data = [e for _ in range(2 * self.size)]
        self.lazy = [identity for _ in range(self.size)]
        self.op = op
        self.e = e
        self.mapping = mapping
        self.composition = composition
        self.identity = identity

        # Initialize leaves
        for i in range(self.n):
            self.data[self.size + i] = data[i]
        # Build the tree
        for i in range(self.size - 1, 0, -1):
            self.data[i] = self.op(self.data[2*i], self.data[2*i+1])

    def _push(self, k):
        if self.lazy[k] == F.I:
            return
        left = 2 * k
        right = 2 * k + 1
        self.data[left] = self.mapping(self.lazy[k], self.data[left])
        self.data[right] = self.mapping(self.lazy[k], self.data[right])
        if left < self.size:
            self.lazy[left] = self.composition(self.lazy[k], self.lazy[left])
        if right < self.size:
            self.lazy[right] = self.composition(self.lazy[k], self.lazy[right])
        self.lazy[k] = self.identity

    def apply(self, l, r, f):
        if l >= r:
            return
        l += self.size
        r += self.size
        while l < r:
            if l % 2 == 1:
                self.data[l] = self.mapping(f, self.data[l])
                if l < self.size:
                    self.lazy[l] = self.composition(f, self.lazy[l])
                l += 1
            if r % 2 == 1:
                r -= 1
                self.data[r] = self.mapping(f, self.data[r])
                if r < self.size:
                    self.lazy[r] = self.composition(f, self.lazy[r])
            l >>= 1
            r >>= 1

    def allProd(self):
        return self.data[1].sum


def main():
    import sys
    global MOD2, inv9, tenmod
    MOD2 = 998244353
    inv9 = pow(9, MOD2-2, MOD2)
    S.set_E()
    F.set_I()

    input = sys.stdin.read().split()
    ptr = 0
    N = int(input[ptr]); ptr +=1
    Q = int(input[ptr]); ptr +=1

    tenmod = precompute_tenmod(N)

    data = []
    for i in range(N):
        val = tenmod[N - i - 1]
        data.append(S(val, i, i))

    segtree = LazySegTree(data, S.op, S.E, S.map, F.composite, F.I)

    for _ in range(Q):
        l = int(input[ptr])-1; ptr +=1
        r = int(input[ptr])-1; ptr +=1
        D = int(input[ptr]); ptr +=1
        segtree.apply(l, r+1, F(D, N))
        print(segtree.allProd())


if __name__ == "__main__":
    main()
# End of Code
