import sys

MOD2 = 998244353
inv9 = pow(9, MOD2 - 2, MOD2)

def op_S(a, b):
    new_sum = (a[0] + b[0]) % MOD2
    new_l = min(a[1], b[1])
    new_r = max(a[2], b[2])
    return (new_sum, new_l, new_r)

def map_S(f, s):
    global tenmod
    N_val = f[1]
    c = (tenmod[N_val - s[1]] - tenmod[N_val - s[2] - 1]) % MOD2
    new_sum = (f[0] * c * inv9) % MOD2
    return (new_sum, s[1], s[2])

def composite_F(f, g):
    return (f[0], f[1])

class LazySegTree:
    def __init__(self, data, op, E, map_f, composite_f, F_id):
        self.N = 1
        while self.N < len(data):
            self.N <<= 1
        self.Log = self.N.bit_length() - 1
        self.op = op
        self.E = E
        self.map_f = map_f
        self.composite_f = composite_f
        self.F_id = F_id

        self.size = self.N
        self.Dat = [E for _ in range(2 * self.N)]
        self.Laz = [F_id for _ in range(self.N)]

        for i in range(len(data)):
            self.Dat[self.N + i] = data[i]
        for i in range(self.N - 1, 0, -1):
            self.Dat[i] = self.op(self.Dat[2 * i], self.Dat[2 * i + 1])

    def push(self, k):
        if self.Laz[k] == self.F_id:
            return
        left = 2 * k
        right = 2 * k + 1
        self.Dat[left] = self.map_f(self.Laz[k], self.Dat[left])
        self.Dat[right] = self.map_f(self.Laz[k], self.Dat[right])
        if left < self.N:
            self.Laz[left] = self.composite_f(self.Laz[k], self.Laz[left])
            self.Laz[right] = self.composite_f(self.Laz[k], self.Laz[right])
        self.Laz[k] = self.F_id

    def pushTo(self, l, r):
        for i in range(self.Log, 0, -1):
            self.push(l >> i)
            if ((r >> i) << i) != r:
                self.push((r >> i))

    def apply(self, l, r, f):
        if l >= r:
            return
        l += self.N
        r += self.N
        self.pushTo(l, r)
        l2, r2 = l, r
        while l2 < r2:
            if (l2 & 1) == 1:
                self.Dat[l2] = self.map_f(f, self.Dat[l2])
                if l2 < self.N:
                    self.Laz[l2] = self.composite_f(f, self.Laz[l2])
                l2 += 1
            if (r2 & 1) == 1:
                r2 -= 1
                self.Dat[r2] = self.map_f(f, self.Dat[r2])
                if r2 < self.N:
                    self.Laz[r2] = self.composite_f(f, self.Laz[r2])
            l2 >>= 1
            r2 >>= 1

    def allProd(self):
        return self.Dat[1][0]

def main():
    global tenmod
    input = sys.stdin.read().split()
    idx = 0
    N = int(input[idx]); idx +=1
    Q = int(input[idx]); idx +=1
    tenmod = [1]*(N+1)
    for j in range(1, N+1):
        tenmod[j] = (tenmod[j-1] * 10) % MOD2

    data = []
    for i in range(N):
        s_val = tenmod[N - i -1]
        l = i
        r = i
        data.append( (s_val, l, r) )

    E_S = (0, float('inf'), float('-inf'))
    F_id = (0, 0)

    seg_tree = LazySegTree(data, op_S, E_S, map_S, composite_F, F_id)

    for _ in range(Q):
        l = int(input[idx])-1; idx +=1
        r = int(input[idx])-1; idx +=1
        D = int(input[idx]); idx +=1
        seg_tree.apply(l, r+1, (D, N))
        print(seg_tree.allProd())

if __name__ == "__main__":
    main()
#End of Code
