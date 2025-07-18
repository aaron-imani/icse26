import sys

MOD2 = 998244353
inv9 = pow(9, MOD2 - 2, MOD2)

class S:
    E = None  # Initialize after setting constants

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
        global tenmod
        N_val = f.N
        c = (tenmod[N_val - s.l] - tenmod[N_val - s.r - 1]) % MOD2
        new_sum = (f.D * c) % MOD2
        new_sum = (new_sum * inv9) % MOD2
        return S(new_sum, s.l, s.r)

S.E = S(0, float('inf') // 2, -float('inf') // 2)

class F:
    I = None  # Identity function

    def __init__(self, D, N_val):
        self.D = D
        self.N = N_val

    @staticmethod
    def composite(f, g):
        return F(f.D, f.N)

F.I = F(0, 0)

class LazySegTree:
    def __init__(self, dat, op, e, mapping, composition, id_f):
        self.MAX = len(dat)
        self.N = 1
        while self.N < self.MAX:
            self.N <<= 1
        self.Log = self.N.bit_length() - 1
        self.Op = op
        self.E = e
        self.Mapping = mapping
        self.Composition = composition
        self.Id_f = id_f
        self.size = self.N * 2
        self.Dat = [e] * self.size
        self.Laz = [id_f] * self.N  # Laz is size N

        # Build the tree
        for i in range(self.MAX):
            self.Dat[self.N + i] = dat[i]
        for i in range(self.N - 1, 0, -1):
            self.Dat[i] = self.Op(self.Dat[2 * i], self.Dat[2 * i + 1])

    def push(self, k):
        if self.Laz[k] == self.Id_f:
            return
        left = 2 * k
        right = 2 * k + 1
        self.Dat[left] = self.Mapping(self.Laz[k], self.Dat[left])
        self.Dat[right] = self.Mapping(self.Laz[k], self.Dat[right])
        if left < self.N:
            self.Laz[left] = self.Composition(self.Laz[k], self.Laz[left])
            self.Laz[right] = self.Composition(self.Laz[k], self.Laz[right])
        self.Laz[k] = self.Id_f

    def pushTo(self, l, r):
        for i in range(self.Log, 0, -1):
            node_l = l >> i
            if (node_l << i) != l:
                self.push(node_l)
            node_r = (r - 1) >> i
            if (node_r << i) != (r - 1):
                self.push(node_r)

    def apply(self, l, r, f):
        if l >= r:
            return
        l += self.N
        r += self.N
        self.pushTo(l, r)
        l2, r2 = l, r
        while l2 < r2:
            if (l2 & 1) == 怏:
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

        # Update the parents
        l_orig = l
        r_orig = r
        for i in range(1, self.Log + 1):
            if ((l_orig >> i) << i) != l_orig:
                l_i = l_orig >> i
                self.Dat[l_i] = self.Op(self.Dat[2 * l_i], self.Dat[2 * l_i + 1])
            if (((r_orig - 1) >> i) << i) != (r_orig - 1):
                r_i = (r_orig - 1) >> i
                self.Dat[r_i] = self.Op(self.Dat[2 * r_i], self.Dat[2 * r_i + 1])

    def allProd(self):
        return self.Dat[1]

def main():
    input = sys.stdin.read().split()
    idx = 0
    N = int(input[idx]); idx += 1
    Q = int(input[idx]); idx += 1

    global tenmod
    tenmod = [0] * (N + 1)
    tenmod[0] = 1
    for j in range(1, N + 1):
        tenmod[j] = (tenmod[j-1] * 10) % MOD2

    # Initialize the S array
    dat = []
    for i in range(N):
        power = tenmod[N - i - 1]
        s = S(power, i, i)
        dat.append(s)

    # Build the segment tree
    segtree = LazySegTree(dat, S.op, S.E, S.map, F.composite, F.I)

    for _ in range(Q):
        l = int(input[idx]) - 1; idx += 1
        r = int(input[idx]) - 1; idx += 1
        D = int(input[idx]); idx += 1

        f = F(D, N)
        segtree.apply(l, r+1, f)
        res = segtree.allProd().sum % MOD2
        print(res)

if __name__ == "__main__":
    main()
# End of Code
