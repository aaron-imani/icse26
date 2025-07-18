MOD2 = 998244353
MOD1 = 1000000007
inv9 = pow(9, MOD2 - 2, MOD2)
tenmod = []

class S:
    def __init__(self, sum_val, l, r):
        self.sum = sum_val
        self.l = l
        self.r = r
S.E = S(0, float('inf'), float('-inf'))

class F:
    def __init__(self, D, N):
        self.D = D
        self.N = N

def op(s1, s2):
    new_sum = (s1.sum + s2.sum) % MOD2
    new_l = min(s1.l, s2.l)
    new_r = max(s1.r, s2.r)
    return S(new_sum, new_l, new_r)

def map_f(f, s):
    global tenmod
    N_f = f.N
    c = (tenmod[N_f - s.l] - tenmod[N_f - s.r - 1]) % MOD2
    if c < 0:
        c += MOD2
    new_sum = (f.D * c * inv9) % MOD2
    return S(new_sum, s.l, s.r)

def composite(f, g):
    return F(f.D, f.N)

class LazySegTree:
    def __init__(self, dat, op_func, e, mapping_func, composition_func, id_f):
        self.N = 1
        self.MAX = len(dat)
        while self.N < self.MAX:
            self.N <<= 1
        self.Log = self.N.bit_length() - 1
        self.op = op_func
        self.e = e
        self.mapping = mapping_func
        self.composition = composition_func
        self.id_f = id_f
        self.size = self.N * 2
        self.Dat = [self.e] * (self.N * 2)
        self.Laz = [self.id_f] * self.N
        for i in range(self.MAX):
            self.Dat[self.N + i] = dat[i]
        for i in range(self.N - 1, 0, -1):
            self.Dat[i] = self.op(self.Dat[2 * i], self.Dat[2 * i + 1])

    def push(self, k):
        if self.Laz[k] == self.id_f:
            return
        left = 2 * k
        right = 2 * k + 1
        self.Dat[left] = self.mapping(self.Laz[k], self.Dat[left])
        self.Dat[right]_ = self.mapping(self.Laz[k], self.Dat[right])
        if left < self.N:
            self.Laz[left] = self.composition(self.Laz[k], self.Laz[left])
        if right < self.N:
            self.Laz[right] = self.composition(self.Laz[k], self.Laz[right])
        self.Laz[k] = self.id_f

    def pushTo(self, l, r):
        for i in range(self.Log, 0, -1):
            if (l >> i) << i != l:
                self.push(l >> i)
            if (r >> i) << i != r:
                self.push((r - 1) >> i)

    def apply(self, l, r, f):
        if l > r:
            raise ValueError("Invalid range")
        l += self.N
        r += self.N
        self.pushTo(l, r)
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
        self.updateFrom(l, r)

    def updateFrom(self, l, r):
        for i in range(1, self.Log + 1):
            if (l >> i) << i != l:
                node = l >> i
                self.Dat[node] = self.op(self.Dat[2 * node], self.Dat[2 * node + 1])
            if (r >> i) << i != r:
                node = (r - 1) >> i
                self.Dat[node] = self.op(self.Dat[2 * node], self.Dat[2 * node + 1])
            l >>= 1
            r >>= 1

    def allProd(self):
        return self.Dat[1].sum

def main():
    global tenmod
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    N = int(input[ptr])
    ptr += 1
    Q = int(input[ptr])
    ptr += 1

    # Precompute tenmod
    tenmod = [0] * (N + 1)
    tenmod[0] = 1
    for j in range(1, N + 1):
        tenmod[j] = (tenmod[j - 1] * 10) % MOD2

    # Initialize data array
    dat = []
    for i in range(N):
        l = i
        r = i
        sum_val = tenmod[N - i - 1]
        s = S(sum_val, l, r)
        dat.append(s)

    # Create the segment tree
    seg_tree = LazySegTree(dat, op, S.E, map_f, composite, F(0, 0))

    for _ in range(Q):
        l = int(input[ptr]) - 1
        ptr += 1
        r = int(input[ptr]) - 1
        ptr += 1
        D = int(input[ptr])
        ptr += 1
        seg_tree.apply(l, r + 1, F(D, N))
        print(seg_tree.allProd())

if __name__ == "__main__":
    main()
#End of Code
