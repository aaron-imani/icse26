import sys
import math
from collections import defaultdict, deque, Counter
from bisect import bisect_left, bisect_right
from sortedcontainers import SortedDict

class Solver:
    def __init__(self, in_stream, out_stream):
        self.in_stream = in_stream
        self.out_stream = out_stream

    def solve(self):
        H = self.ni()
        W = self.ni()
        C = [['.' for _ in range(W + 2)] for _ in range(H + 2)]
        for i in range(H):
            line = self.ns()
            for j in range(W):
                C[i + 1][j + 1] = line[j]
        if H == 1 and W == 1:
            self.prn("No")
            return
        for i in range(1, H + 1):
            for j in range(1, W + 1):
                if C[i][j] == '#' and C[i - 1][j] != '#' and C[i + 1][j] != '#' and C[i][j - 1] != '#' and C[i][j + 1] != '#':
                    self.prn("No")
                    return
        self.prn("Yes")

    def prn(self, s):
        self.out_stream.write(f"{s}\n")

    def prr(self, s):
        self.out_stream.write(s)

    def ni(self):
        return int(self.ns())

    def nl(self):
        return int(self.ns())

    def nd(self):
        return float(self.ns())

    def ns(self):
        return self.in_stream.readline().strip()

    def ndi(self, n):
        return [self.ni() for _ in range(n)]

    def ndl(self, n):
        return [self.nl() for _ in range(n)]

    def ndd(self, n):
        return [self.nd() for _ in range(n)]

    def nds(self, n):
        return [self.ns() for _ in range(n)]

    def nddi(self, n, m):
        return [self.ndi(m) for _ in range(n)]

    def nddl(self, n, m):
        return [self.ndl(m) for _ in range(n)]

    def isRightMin(self, a, f, index, key):
        if f and a[index] >= key:
            return True
        elif not f and a[index] > key:
            return True
        else:
            return False

    def binarySearchRightMin(self, a, f, key):
        ng = -1
        ok = len(a)
        while abs(ok - ng) > 1:
            mid = (ok + ng) // 2
            if self.isRightMin(a, f, mid, key):
                ok = mid
            else:
                ng = mid
        return ok

    def isLeftMax(self, a, f, index, key):
        if f and a[index] <= key:
            return True
        elif not f and a[index] < key:
            return True
        else:
            return False

    def binarySearchLeftMax(self, a, f, key):
        ng = -1
        ok = len(a)
        while abs(ok - ng) > 1:
            mid = (ok + ng) // 2
            if self.isLeftMax(a, f, mid, key):
                ng = mid
            else:
                ok = mid
        return ng

class PP:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def getKey(self):
        return self.key

    def getVal(self):
        return self.val

class PPP:
    def __init__(self, key, val1, val2):
        self.key = key
        self.val1 = val1
        self.val2 = val2

    def getKey(self):
        return self.key

    def getVal1(self):
        return self.val1

    def getVal2(self):
        return self.val2

class PPL:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def getKey(self):
        return self.key

    def getVal(self):
        return self.val

class PPDL:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def getKey(self):
        return self.key

    def getVal(self):
        return self.val

    def dump(self, out_stream):
        out_stream.write(f"key = {self.key}  val ")
        for v in self.val:
            out_stream.write(f"[{v}] ")
        out_stream.write("\n")

class PPKEY:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def getKey(self):
        return self.key

    def getVal(self):
        return self.val

    def __eq__(self, other):
        if isinstance(other, PPKEY):
            return self.key == other.key and self.val == other.val
        return False

    def __hash__(self):
        return hash((self.key, self.val))

class PPLKEY:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def getKey(self):
        return self.key

    def getVal(self):
        return self.val

    def __eq__(self, other):
        if isinstance(other, PPLKEY):
            return self.key == other.key and self.val == other.val
        return False

    def __hash__(self):
        return hash((self.key, self.val))

class MapCounter:
    def __init__(self, reverse=False):
        self.map = SortedDict()
        if reverse:
            self.map = SortedDict(reverse=True)

    def add(self, key, cnt=1):
        if key in self.map:
            self.map[key] += cnt
        else:
            self.map[key] = cnt

    def remove(self, key):
        self.sub(key, 1, False)

    def sub(self, key, cnt=1, minus=False):
        if key in self.map:
            if self.map[key] > cnt or minus:
                self.map[key] -= cnt
            else:
                del self.map[key]
        elif minus:
            self.map[key] = -cnt

    def set(self, key, cnt):
        self.map[key] = cnt

    def getCountwithNull(self, key):
        return self.map.get(key)

    def getCount(self, key):
        return self.map.get(key, 0)

    def getKey(self):
        return self.map.keys()

    def getKeyCount(self):
        return len(self.map)

    def getFirstKey(self):
        return self.map.peekitem(0)[0]

    def getLastKey(self):
        return self.map.peekitem(-1)[0]

    def clear(self):
        self.map.clear()

class Graph:
    def __init__(self):
        self.data = defaultdict(list)
        self.mapCnt = {}
        self.mapLow = {}
        self.mark = set()
        self.number = 0

    def add(self, from_node, to_node):
        self.data[from_node].append(to_node)

    def del(self, from_node, to_node):
        if from_node in self.data and to_node in self.data[from_node]:
            self.data[from_node].remove(to_node)

    def get(self, key):
        return self.data.get(key, [])

    def contains(self, key):
        return key in self.data

    def keySet(self):
        return self.data.keys()

    def isConnect(self, key_1, key_2):
        return key_2 in self.data.get(key_1, [])

    def distList(self, key):
        dist = []
        mark = set()
        stack = [(key, 0)]
        while stack:
            pp, dd = stack.pop()
            if pp in mark:
                continue
            mark.add(pp)
            dist.append(PP(pp, dd))
            for next_node in self.get(pp):
                if next_node not in mark:
                    stack.append((next_node, dd + 1))
        return dist

    def distV(self, key):
        dist = [-1] * (len(self.data) + 1)
        mark = set()
        stack = [(key, 0)]
        while stack:
            pp, dd = stack.pop()
            if pp in mark:
                continue
            mark.add(pp)
            dist[pp] = dd
            for next_node in self.get(pp):
                if next_node not in mark:
                    stack.append((next_node, dd + 1))
        return dist

    def bridgeDfs(self, now, pre):
        self.mark.add(now)
        self.mapCnt[now] = self.number
        self.mapLow[now] = self.number
        low = None
        for next_node in self.get(now):
            if next_node == pre:
                continue
            if next_node in self.mark:
                if self.mapLow[now] > self.mapLow[next_node]:
                    self.mapLow[now] = self.mapLow[next_node]
                continue
            self.number += 1
            low = self.bridgeDfs(next_node, now)
            if self.mapLow[now] > low:
                self.mapLow[now] = low
        return self.mapLow[now]

    def bridgeCnt(self, start):
        self.mapCnt.clear()
        self.mapLow.clear()
        self.mark.clear()
        self.number = 0
        self.bridgeDfs(start, start)
        ans = 0
        for key in self.mapCnt:
            if self.mapCnt[key] == self.mapLow[key]:
                ans += 1
        return ans - 1

    def dump(self, out_stream):
        for key in self.data:
            out_stream.write(f"{key} : ")
            for val in self.data[key]:
                out_stream.write(f"{val} ")
            out_stream.write("\n")

class GraphWith:
    def __init__(self):
        self.data = defaultdict(list)

    def add(self, key, p):
        self.data[key].append(p)

    def get(self, key):
        return self.data.get(key, [])

    def contains(self, key):
        return key in self.data

    def keySet(self):
        return self.data.keys()

    def isConnect(self, key_1, key_2):
        for p in self.get(key_1):
            if p.getKey() == key_2:
                return True
        return False

    def distance(self, key_1, key_2):
        mark = set()
        stack = [(key_1, 0)]
        while stack:
            key, val = stack.pop()
            if key in mark:
                continue
            mark.add(key)
            if key == key_2:
                return val
            for pp in self.get(key):
                if pp.getKey() not in mark:
                    stack.append((pp.getKey(), val + pp.getVal()))
        return math.inf
class GraphLong:
    def __init__(self):
        self.G = defaultdict(list)

    def add(self, key, value):
        self.G[key].append(value)

    def get(self, key):
        return self.G.get(key, [])
class GraphLongWith:
    def __init__(self):
        self.G = defaultdict(list)

    def add(self, key, p):
        self.G[key].append(p)

    def get(self, key):
        return self.G.get(key, [])
class MyInput:
    def __init__(self, in_stream):
        self.in_stream = in_stream
        self.buffer = []
        self.buffer_pointer = 0

    def read(self):
        if self.buffer_pointer >= len(self.buffer):
            self.buffer = self.in_stream.readline().split()
            self.buffer_pointer = 0
        result = self.buffer[self.buffer_pointer]
        self.buffer_pointer += 1
        return result

    def nextInt(self):
        return int(self.read())

    def nextLong(self):
        return int(self.read())

    def nextDouble(self):
        return float(self.read())

    def nextString(self):
        return self.read()

    def nextDChar(self):
        return list(self.read())

    def nextChar(self):
        return self.read()[0]

    def reads(self, len, accept):
        result = []
        while True:
            c = self.read()
            if accept(c):
                break
            result.append(c)
        return result
def main():
    solver = Solver(sys.stdin, sys.stdout)
    solver.solve()

if __name__ == "__main__":
    main()
# End of Code
