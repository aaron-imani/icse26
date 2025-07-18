Here's the Python code based on the Java code provided:


import sys

class MyInput:
    def __init__(self):
        self.tokens = None
        self.f = sys.stdin

    def get_token(self):
        while self.tokens is None or len(self.tokens) == 0:
            line = self.f.readline()
            if not line:
                return None
            self.tokens = line.strip().split()
        return self.tokens.pop(0)

    def nextInt(self):
        return int(self.get_token())

    def nextLong(self):
        return int(self.get_token())

    def nextString(self):
        return self.get_token()

    def nextDouble(self):
        return float(self.get_token())

class PP:
    def __init__(self, key, val):
        self.key = key
        self.val = val

class PPP:
    def __init__(self, key, val1, val2):
        self.key = key
        self.val1 = val1
        self.val2 = val2

class PPL:
    def __init__(self, key, val):
        self.key = key
        self.val = val

class PPDL:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def dump(self, out):
        out.write(f"key = {self.key}  val ")
        for v in self.val:
            out.write(f"[{v}] ")
        out.write("\n")

class PPKEY:
    def __init__(self, key, val):
        self.key = key
        self.val = val

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

    def __eq__(self, other):
        if isinstance(other, PPLKEY):
            return self.key == other.key and self.val == other.val
        return False

    def __hash__(self):
        return hash((self.key, self.val))

class MapCounter:
    def __init__(self, reverse=False):
        self.map = {}
        self.reverse = reverse
        self.sorted_keys = []

    def add(self, key, cnt=1):
        if key in self.map:
            self.map[key] += cnt
        else:
            self.map[key] = cnt
        if not self.sorted_keys or (self.reverse and key < self.sorted_keys[-1]) or (not self.reverse and key > self.sorted_keys[-1]):
            self.sorted_keys.append(key)
        else:
            for i in range(len(self.sorted_keys)):
                if (self.reverse and key < self.sorted_keys[i]) or (not self.reverse and key > self.sorted_keys[i]):
                    self.sorted_keys.insert(i, key)
                    break
            else:
                self.sorted_keys.append(key)

    def remove(self, key):
        self.sub(key, 1, False)

    def sub(self, key, cnt=1, minus=True):
        if key in self.map:
            new_val = self.map[key] - cnt
            if new_val == 0 or (not minus and new_val < 0):
                del self.map[key]
                self.sorted_keys.remove(key)
            else:
                self.map[key] = new_val

    def getCount(self, key):
        return self.map.get(key, 0)

    def getKeyCount(self):
        return len(self.map)

    def getFirstKey(self):
        return self.sorted_keys[0] if self.sorted_keys else None

    def getLastKey(self):
        return self.sorted_keys[-1] if self.sorted_keys else None

    def clear(self):
        self.map.clear()
        self.sorted_keys.clear()

def isRightMin(a, f, index, key):
    if f and a[index] >= key:
        return True
    elif not f and a[index] > key:
        return True
    else:
        return False

def binarySearchRightMin(a, f, key):
    ng = -1
    ok = len(a)
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if isRightMin(a, f, mid, key):
            ok = mid
        else:
            ng = mid
    return ok

def isLeftMax(a, f, index, key):
    if f and a[index] <= key:
        return True
    elif not f and a[index] < key:
        return True
    else:
        return False

def binarySearchLeftMax(a, f, key):
    ng = -1
    ok = len(a)
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if isLeftMax(a, f, mid, key):
            ng = mid
        else:
            ok = mid
    return ng

class EulerTour:
    def __init__(self):
        self.g = None
        self.euler_tour = []
        self.begin = None
        self.end = None
        self.k = 0
        self.root = 0

    def dfs(self, v, p, out):
        out.write(f"v = {v}  p = {p}\n")
        self.begin[v] = self.k
        self.euler_tour.append(v)
        self.k += 1
        if v not in self.g.data:
            return
        for i in self.g.data[v]:
            if i != p:
                self.dfs(i, v, out)
                self.euler_tour.append(v)
                self.k += 1
        self.end[v] = self.k

    def init(self, p_cnt, root, g, out):
        self.begin = [0] * (p_cnt + 1)
        self.end = [0] * (p_cnt + 1)
        self.root = root
        self.g = g
        self.k = 0
        self.euler_tour = []
        self.dfs(root, -1, out)

    def getPartTour(self, v):
        return self.euler_tour[self.begin[v]: self.end[v]]

    def getPartList(self, v):
        s = set(self.getPartTour(v))
        return list(s)

class Graph:
    def __init__(self):
        self.data = {}
        self.mapCnt = {}
        self.mapLow = {}
        self.mark = set()
        self.number = 0

    def add(self, from_node, to_node):
        if from_node not in self.data:
            self.data[from_node] = []
        self.data[from_node].append(to_node)

    def del_edge(self, from_node, to_node):
        if from_node in self.data:
            if to_node in self.data[from_node]:
                self.data[from_node].remove(to_node)

    def get(self, key):
        return self.data.get(key, [])

    def contains(self, key):
        return key in self.data

    def keySet(self):
        return list(self.data.keys())

    def isConnect(self, key1, key2):
        return key2 in self.data.get(key1, [])

    def distList(self, key):
        dist = []
        mark = set()
        stack = []
        stack.append((key, 0))
        while stack:
            (pp, dd) = stack.pop()
            if pp in mark:
                continue
            mark.add(pp)
            dist.append(PP(pp, dd))
            for next_node in self.data.get(pp, []):
                if next_node not in mark:
                    stack.append((next_node, dd + 1))
        return dist

    def distV(self, key):
        dist = {}
        for k in self.data.keys():
            dist[k] = -1
        stack = []
        stack.append((key, 0))
        dist[key] = 0
        while stack:
            (pp, dd) = stack.pop()
            for next_node in self.data.get(pp, []):
                if dist[next_node] == -1:
                    dist[next_node] = dd + 1
                    stack.append((next_node, dd + 1))
        return dist

    def bridgeDfs(self, now, pre):
        self.mark.add(now)
        self.mapCnt[now] = self.number
        self.mapLow[now] = self.number
        self.number += 1
        low = self.mapLow[now]
        for next_node in self.data.get(now, []):
            if next_node == pre:
                continue
            if next_node in self.mark:
                if self.mapLow[now] > self.mapLow[next_node]:
                    self.mapLow[now] = self.mapLow[next_node]
                continue
            current_low = self.bridgeDfs(next_node, now)
            if self.mapLow[now] > current_low:
                self.mapLow[now] = current_low
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

    def dump(self, out):
        for key in self.data:
            out.write(f"{key} : ")
            for val in self.data[key]:
                out.write(f"{val} ")
            out.write("\n")

class GraphWith:
    def __init__(self):
        self.data = {}

    def add(self, key, pp):
        if key not in self.data:
            self.data[key] = []
        self.data[key].append(pp)

    def get(self, key):
        return self.data.get(key, [])

    def contains(self, key):
        return key in self.data

    def keySet(self):
        return list(self.data.keys())

    def isConnect(self, key1, key2):
        if key1 not in self.data:
            return False
        for p in self.data[key1]:
            if p.key == key2:
                return True
        return False

class GraphLong:
    def __init__(self):
        self.G = {}

    def add(self, key, value):
        if key not in self.G:
            self.G[key] = []
        self.G[key].append(value)

    def get(self, key):
        return self.G.get(key, [])

class GraphLongWith:
    def __init__(self):
        self.G = {}

    def add(self, key, ppl):
        if key not in self.G:
            self.G[key] = []
        self.G[key].append(ppl)

    def get(self, key):
        return self.G.get(key, [])

class Solver:
    def __init__(self, in_reader, out):
        self.in_reader = in_reader
        self.out = out

    def solve(self):
        H = self.in_reader.nextInt()
        W = self.in_reader.nextInt()
        C = [['.' for _ in range(W + 2)] for _ in range(H + 2)]
        for i in range(1, H + 1):
            line = self.in_reader.nextString().strip()
            for j in range(1, W + 1):
                C[i][j] = line[j - 1]
        if H == 1 and W == 1:
            self.out.write("No\n")
            self.out.flush()
            return
        for i in range(1, H + 1):
            for j in range(1, W + 1):
                if C[i][j] == '#' and C[i-1][j] != '#' and C[i+1][j] != '#' and C[i][j-1] != '#' and C[i][j+1] != '#':
                    self.out.write("No\n")
                    self.out.flush()
                    return
        self.out.write("Yes\n")
        self.out.flush()

def main():
    in_reader = MyInput()
    out = sys.stdout
    solver = Solver(in_reader, out)
    solver.solve()
    out.flush()

if __name__ == "__main__":
    main()
# End of Code
