MOD2 = 998244353
inv9 = pow(9, MOD2 - 2, MOD2)

class S:
    __slots__ = ['sum', 'l', 'r']
    def __init__(self, sum_val, l, r):
        self.sum = sum_val
        self.l = l
        self.r = r
S.E = S(0, (1 << 60), -(1 << 60))

def op(s1, s2):
    new_sum = (s1.sum + s2.sum) % MOD2
    new_l = min(s1.l, s2.l)
    new_r = max(s1.r, s2.r)
    return S(new_sum, new_l, new_r)

def map_f(f, s):
    c = (tenmod[f.N - s.l] - tenmod[f.N - s.r - 1]) % MOD2
    new_sum = (f.D * c * inv9) % MOD2
    return S(new_sum, s.l, s.r)

class F:
    __slots__ = ['D', 'N']
    def __init__(self, D, N):
        self.D = D
        self.N = N
    @staticmethod
    def composite(f, g):
        return F(f.D, f.N)
F.I = F(0, 0)

class LazySegTree:
    def __init__(self, data, op, e, mapping, composition, id_f):
        self.N = 1
        while self.N < len(data):
            self.N <<= 1
        self.log = self.N.bit_length() - 1
        self.size = self.N
        self.dat = [e] * (2 * self.N)
        self.laz = [id_f] * self.N

        for i in range(len(data)):
            self.dat[self.N + i] = data[i]
        for i in range(self.N - 1, 0, -1):
            self.dat[i] = op(self.dat[2*i], self.dat[2*i+1])

        self.op = op
        self.e = e
        self.mapping = mapping
        self.composition = composition
        self.id_f = id_f

    def push(self, k):
        if self.laz[k] == self.id_f:
            return
        left = 2 * k
        right = 2 * k + 1
        self.dat[left] = self.mapping(self.laz[k], self.dat[left])
        self.dat[right] = self.mapping(self.laz[k], self.dat[right])
        if left < self.N:
            self.laz[left] = self.composition(self.laz[k], self.laz[left])
            self.laz[right] = self.composition(self.laz[k], self.laz[right])
        self.laz[k] = self.id_f

    def push_to_range(self, l, r):
        for i in range(self.log, 0, -1):
            if (l >> i) << i != l:
                self.push(l >> i)
            if (r >> i) << i != r:
                self.push((r - 1) >> i)

    def apply_range(self, l, r, f):
        if l >= r:
            return
        original_l, original_r = l, r
        l += self.N
        r += self.N
        self.push_to_range(l, r)
        while l < r:
            if l % 2 == 1:
                self.dat[l] = self.mapping(f, self.dat[l])
                if l < self.N:
                    self.laz[l] = self.composition(f, self.laz[l])
                l += 1
            if r % 2 == 1:
                r -= 1
                self.dat[r] = self.mapping(f, self.dat[r])
                if r < self.N:
                    self.laz[r] = self.composition(f, self.laz[r])
            l >>= 1
            r >>= 1
        self._update_range(original_l, original_r)

    def _update_range(self, l, r):
        for i in range(1, self.log + 1):
            if (l >> i) << i != l:
                node = l >> i
                self.dat[node] = self.op(self.dat[2*node], self.dat[2*node+1])
            if (r >> i) << i != r:
                node = (r - 1) >> i
                self.dat[node] = self.op(self.dat[2*node], self.dat[2*node+1])

    def all_prod(self):
        return self.dat[1]

def main():
    import sys
    input = sys.stdin.read().split()
    idx = 0
    N = int(input[idx]); idx += 1
    Q = int(input[idx]); idx += 1

    global tenmod
    tenmod = [1] * (N + 1)
    for j in range(1, N+1):
        tenmod[j] = (tenmod[j-1] * 10) % MOD2

    data = [S(tenmod[N - i -1], i, i) for i in range(N)]

    seg_tree = LazySegTree(
        data,
        op=op,
        e=S.E,
        mapping=map_f,
        composition=F.composite,
        id_f=F.I
    )

    for _ in range(Q):
        l = int(input[idx])-1; idx +=1
        r = int(input[idx])-1; idx +=1
        D = int(input[idx]); idx +=1
        seg_tree.apply_range(l, r+1, F(D, N))
        print(seg_tree.all_prod().sum)

if __name__ == "__main__":
    main()
#End of Code
