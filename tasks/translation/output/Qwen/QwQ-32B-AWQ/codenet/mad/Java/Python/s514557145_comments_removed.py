class S:
    __slots__ = ['sum', 'l', 'r']
    def __init__(self, sum_val, l, r):
        self.sum = sum_val % MOD2
        self.l = l
        self.r = r

    @classmethod
    def combine(cls, a, b, mod):
        new_sum = (a.sum + b.sum) % mod
        new_l = min(a.l, b.l)
        new_r = max(a.r, b.r)
        return S(new_sum, new_l, new_r)

    @classmethod
    def map_f(cls, s, f, tenmod, N, inv9, mod):
        c = (tenmod[N - s.l] - tenmod[N - s.r - 1]) % mod
        new_sum = (f.D * c % mod) * inv9 % mod
        return S(new_sum, s.l, s.r)

class F:
    __slots__ = ['D', 'N']
    def __init__(self, D, N):
        self.D = D
        self.N = N

class LazySegTree:
    def __init__(self, data, tenmod, N, inv9, MOD):
        self.MOD = MOD
        self.n = len(data)
        self.size = 1
        while self.size < self.n:
            self.size <<= 1
        self.log = self.size.bit_length() - 1
        self.dat = [S(0, 0, 0) for _ in range(2 * self.size)]
        self.laz = [None for _ in range(self.size)]
        for i in range(self.n):
            self.dat[self.size + i] = data[i]
        for i in range(self.size - 1, 0, -1):
            self.dat[i] = S.combine(self.dat[i << 1], self.dat[i << 1 | 1], self.MOD)
        self.tenmod = tenmod
        self.N = N
        self.inv9 = inv9

    def _apply(self, node, f):
        s = self.dat[node]
        new_s = S.map_f(s, f, self.tenmod, self.N, self.inv9, self.MOD)
        self.dat[node] = new_s
        if node < self.size:
            self.laz[node] = f

    def _push(self, node):
        if self.laz[node]:
            f = self.laz[node]
            self._apply(node << 1, f)
            self._apply(node << 1 | 1, f)
            self.laz[node] = None

    def _push_all_ancestors(self, node):
        current = node
        while current > 0:
            self._push(current)
            current >>= 1

    def apply_range(self, l, r, f):
        l += self.size
        r += self.size
        self._push_all_ancestors(l)
        self._push_all_ancestors(r - 1)
        l0, r0 = l, r
        while l0 < r0:
            if l0 & 1:
                self._apply(l0, f)
                l0 += 迷 1
            if r0 & 1:
                r0 -= 1
                self._apply(r0, f)
            l0 >>= 1
            r0 >>= 1

    def get_total_sum(self):
        return self.dat[1].sum % self.MOD

def main():
    import sys
    MOD2 = 998244353
    inv9 = pow(9, MOD2-2, MOD2)
    input = sys.stdin.read().split()
    ptr = 0
    N = int(input[ptr]); ptr +=1
    Q = int(input[ptr]); ptr +=1
    tenmod = [1]*(N+1)
    for j in range(1, N+1):
        tenmod[j] = (tenmod[j-1] * 10) % MOD2
    data = []
    for i in range(N):
        coeff = tenmod[N - i -1]
        data.append(S(coeff, i, i))
    seg_tree = LazySegTree(data, tenmod, N, inv9, MOD2)
    for _ in range(Q):
        l = int(input[ptr])-1; ptr +=1
        r = int(input[ptr])-1; ptr +=1
        D = int(input[ptr]); ptr +=1
        f = F(D, N)
        seg_tree.apply_range(l, r+1, f)
        print(seg_tree.get_total_sum())

if __name__ == "__main__":
    main()  # End of Code
