class UnionFind:
    def __init__(self, n):
        self.Parent = [-1]*n
    def root(self, A):
        if self.Parent[A] <0:
            return A
        else:
            root_val = self.root(self.Parent[A])
            self.Parent[A] = root_val
            return root_val
    def size(self, A):
        return -self.Parent[self.root(A)]
    def connect(self, A, B):
        A_root = self.root(A)
        B_root = self.root(B)
        if A_root == B_root:
            return False
        if self.size(A_root) < self.size(B_root):
            A_root, B_root = B_root, A_root
        self.Parent[A_root] += self.Parent[B_root]
        self.Parent[B_root] = A_root
        return True

class FastScanner:
    def __init__(self):
        import sys
        self.tokens = iter(sys.stdin.read().split())
    def next(self):
        return next(self.tokens)
    def nextInt(self):
        return int(self.next())
    def nextLong(self):
        return int(self.next())
    def nextDouble(self):
        return float(self.next())

def lower_bound(a, key):
    left, right = 0, len(a)
    while right - left > 1:
        mid = (left + right) // 2
        if a[mid] < key:
            left = mid
        else:
            right = mid
    return left

def upper_bound(a, key):
    left, right = 0, len(a)
    while right - left > 1:
        mid = (left + right) // 2
        if a[mid] <= key:
            left = mid
        else:
            right = mid
    return left

def isPrime(n):
    if n == 2:
        return True
    if n <2 or n%2 ==0:
        return False
    d = int(n**0.5)+1
    for i in range(3, d, 2):
        if n%i ==0:
            return False
    return True

def upper_division(a, b):
    return a//b + (1 if a%b !=0 else 0)

def lupper_division(a, b):
    return a//b + (1 if a%b !=0 else 0)

def setArray(a):
    global scan
    return [scan.nextInt() for _ in range(a)]

def lsetArray(a):
    global scan
    return [scan.nextLong() for _ in range(a)]

def reverse(s):
    ch = list(s)
    n = len(ch)
    for i in range(upper_division(n,2)):
        ch[i], ch[n-1 -i] = ch[n-1 -i], ch[i]
    return ''.join(ch)

def printArray(que):
    print(' '.join(map(str, que)))

def doublesort(a):
    a.sort(key=lambda x: x[0])
    return a

def ldoublesort(a):
    a.sort(key=lambda x: x[0])
    return a

def modpow(x, n, mo):
    res =1
    while n>0:
        if n &1:
            res = res *x % mo
        x = x*x % mo
        n >>=1
    return res

def revch(ch):
    return ch[::-1]

def revint(ch):
    return ch[::-1]

def warshall_floyd(v, n):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                v[i][j] = min(v[i][j], v[i][k] + v[k][j])

def modint(a, m):
    b = m
    u, v = 1, 0
    while b !=0:
        t = a // b
        a, b = b, a % b
        temp_u = u - t * v
        temp_v = v
        u, v = temp_u, temp_v
    u %= m
    if u <0:
        u += m
    return u

def main():
    global scan
    scan = FastScanner()
    str = scan.next()
    if str[2] == str[3] and str[4] == str[5]:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
# End of Code
