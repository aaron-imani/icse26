Here's the Python code translation of the provided Java code:


MOD2 = 998244353
inv9 = pow(9, MOD2-2, MOD2)

class S:
    __slots__ = ['sum', 'l', 'r']
    E = None

    def __init__(self, sum_val, l, r):
        self.sum = sum_val % MOD2
        self.l = l
        self.r = r

    @staticmethod
    def op(a, b):
        new_sum = (a.sum + b.sum) % MOD2
        new_l = min(a.l, b.l)
        new_r = max(a.r, b.r)
        return S(new_sum, new_l, new_r)

    @staticmethod
    def map(f, s):
        N_val = f.N
        current_l = s.l
        current_r = s.r
        term1 = tenmod[N_val - current_l]
        term2 = tenmod[N_val - (current_r + 1)]
        c = (term1 - term2) % MOD2
        new_sum = (f.D * c * inv9) % MOD2
        return S(new_sum, current_l, current_r)

S.E = S(0, float('inf'), float('-inf'))

class F:
    __slots__ = ['D', 'N']
    I = None

    def __init__(self, D, N):
        self.D = D
        self.N = N

    @staticmethod
    def composite(f, g):
        return F(f.D, f.N)

F.I = F(0, 0)

class LazySegTree:
    def __init__(self, data, Op, E, Mapping, Composition, Id):
        self.MAX = len(data)
        self.N = 1
        while self.N < self.MAX:
            self.N <<= 1
        self.Log = self.N.bit_length() - 1
        self.Op = Op
        self.E = E
        self.Mapping = Mapping
        self.Composition = Composition
        self.Id = Id

        self.Dat = [E] * (2 * self.N)
        self.Laz = [Id] * self.N

        for i in range(self.MAX):
            self.Dat[self.N + i] = data[i]
        for i in range(self.N - 1, 0, -1):
            self.Dat[i] = Op(self.Dat[2 * i], self.Dat[2 * i + 1])

    def allProd(self):
        return self.Dat[1].sum

    def push(self, k):
        if self.Laz[k] == self.Id:
            return
        lk = k << 1
        rk = (k << 1) | 
        self.Dat[lk] = self.Mapping(self.Laz[k], self.Dat[lk])
        self.Dat[rk] = self.Mapping(self.Laz[k], self.Dat[rk])
        if lk < self.N:
            self.Laz[lk] = self.Composition(self.Laz[k], self.Laz[lk])
        if rk < self.N:
            self.Laz[rk] = self.Composition(self.Laz[k], self.Laz[rk])
        self.Laz[k] = self.Id

    def pushTo(self, l, r):
        for i in range(self.Log, 0, -1):
            node_l = l >> i
            if (node_l << i) != l:
                self.push(node_l)
            node_r = r >> i
            if (node_r << i) != r:
                self.push(node_r)

    def apply(self, l, r, f):
        if l > r:
            return
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

    def updateFrom(self, l, r):
        for i in range(1, self.Log + 1):
            node_l = l >> i
            if (node_l << i) != l:
                self.Dat[node_l] = self.Op(
                    self.Dat[node_l * 2],
                    self.Dat[node_l * 2 + 1]
                )
            node_r = (r - 1) >> i
            if (node_r << i) != (r - 1):
                self.Dat[node_r] = self.Op(
                    self.Dat[node_r * 2],
                    self.Dat[node_r * 2 + 1]
                )

def main():
    import sys
    input = sys.stdin.read().split()
    idx = 0
    N = int(input[idx]); idx +=1
    Q = int(input[idx]); idx +=1

    tenmod = [0]*(N+1)
    tenmod[0] = 1
    for j in range(1, N+1):
        tenmod[j] = (tenmod[j-1] * 10) % MOD2

    data = [S(tenmod[N-i-1], i, i) for i in range(N)]
    seg = LazySegTree(data, S.op, S.E, S.map, F.composite, F.I)

    for _ in range(Q):
        l = int(input[idx])-1; idx +=1
        r = int(input[idx])-1; idx +=1
        D = int(input[idx]); idx +=1
        f = F(D, N)
        seg.apply(l, r+1, f)
        print(seg.allProd())

if __name__ == "__main__":
    main()
End of Code.
