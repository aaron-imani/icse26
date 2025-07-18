import sys
from collections import defaultdict, deque

class Solver:
    def __init__(self, input_stream, output_stream):
        self.input = input_stream
        self.output = output_stream

    def solve(self):
        H = int(self.input.readline())
        W = int(self.input.readline())
        C = [['.' for _ in range(W + 2)] for _ in range(H + 2)]
        
        for i in range(1, H + 1):
            line = self.input.readline().strip()
            for j in range(1, W + 1):
                C[i][j] = line[j - 1]
                
        if H == 1 and W == 1:
            self.output.write("No\n")
            return
        
        for i in range(1, H + 1):
            for j in range(1, W + 1):
                if C[i][j] == '#' and C[i-1][j] != '#' and C[i+1][j] != '#' and C[i][j-1] != '#' and C[i][j+1] != '#':
                    self.output.write("No\n")
                    return
                    
        self.output.write("Yes\n")

class MapCounter:
    def __init__(self, reverse=False):
        self.map = defaultdict(int)
        if reverse:
            self.map = defaultdict(int, sorted(self.map.items(), reverse=True))

    def add(self, key, cnt=1):
        self.map[key] += cnt

    def remove(self, key):
        self.sub(key, 1)

    def sub(self, key, cnt=1, minus=False):
        if key in self.map:
            if self.map[key] > cnt or minus:
                self.map[key] -= cnt
            else:
                del self.map[key]

    def set(self, key, cnt):
        self.map[key] = cnt

    def get_count_with_null(self, key):
        return self.map.get(key)

    def get_count(self, key):
        return self.map.get(key, 0)

    def get_keys(self):
        return set(self.map.keys())

    def get_key_count(self):
        return len(self.map)

    def get_first_key(self):
        return min(self.map.keys())

    def get_last_key(self):
        return max(self.map.keys())

    def clear(self):
        self.map.clear()

def binary_search_right_min(arr, f, key):
    ng, ok = -1, len(arr)
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if (f and arr[mid] >= key) or (not f and arr[mid] > key):
            ok = mid
        else:
            ng = mid
    return ok

def binary_search_left_max(arr, f, key):
    ng, ok = -1, len(arr)
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if (f and arr[mid] <= key) or (not f and arr[mid] < key):
            ng = mid
        else:
            ok = mid
    return ng

class Graph:
    def __init__(self):
        self.data = defaultdict(list)

    def add(self, from_node, to_node):
        self.data[from_node].append(to_node)

    def delete(self, from_node, to_node):
        if from_node in self.data:
            self.data[from_node].remove(to_node)

    def get(self, key):
        return self.data.get(key, [])

    def contains(self, key):
        return key in self.data

    def key_set(self):
        return set(self.data.keys())

    def is_connected(self, key_1, key_2):
        return key_2 in self.data.get(key_1, [])

    def dist_list(self, key):
        dist = []
        mark = set()
        stack = [(key, 0)]
        while stack:
            pp, dd = stack.pop()
            if pp not in mark:
                mark.add(pp)
                dist.append((pp, dd))
                for next_node in self.data.get(pp, []):
                    if next_node not in mark:
                        stack.append((next_node, dd + 1))
        return dist

    def dist_v(self, key):
        dist = [-1] * (len(self.data) + 1)
        mark = set()
        stack = [(key, 0)]
        while stack:
            pp, dd = stack.pop()
            if pp not in mark:
                mark.add(pp)
                dist[pp] = dd
                for next_node in self.data.get(pp, []):
                    if next_node not in mark:
                        stack.append((next_node, dd + 1))
        return dist

    def bridge_dfs(self, now, pre):
        self.mark.add(now)
        self.map_cnt[now] = self.number
        self.map_low[now] = self.number
        for next_node in self.data.get(now, []):
            if next_node == pre:
                continue
            if next_node in self.mark:
                if self.map_low[now] > self.map_low[next_node]:
                    self.map_low[now] = self.map_low[next_node]
                continue
            self.number += 1
            low = self.bridge_dfs(next_node, now)
            if self.map_low[now] > low:
                self.map_low[now] = low
        return self.map_low[now]

    def bridge_cnt(self, start):
        self.map_cnt.clear()
        self.map_low.clear()
        self.mark.clear()
        self.number = 0
        self.bridge_dfs(start, start)
        ans = sum(1 for key in self.map_cnt if self.map_cnt[key] == self.map_low[key])
        return ans - 1

    def dump(self, output):
        for key in self.data:
            output.write(f"{key}: {' '.join(map(str, self.data[key]))}\n")

class GraphWith(Graph):
    def __init__(self):
        super().__init__()
        self.data = defaultdict(list)

    def add(self, key, pair):
        self.data[key].append(pair)

    def get(self, key):
        return self.data.get(key, [])

    def distance(self, key_1, key_2):
        mark = set()
        stack = deque([(key_1, 0)])
        while stack:
            key, val = stack.popleft()
            if key == key_2:
                return val
            for next_pair in self.data.get(key, []):
                if next_pair[0] not in mark:
                    stack.append((next_pair[0], val + next_pair[1]))
                    mark.add(next_pair[0])
        return float('inf')

class GraphLong(Graph):
    def __init__(self):
        super().__init__()
        self.data = defaultdict(list)

class GraphLongWith(GraphWith):
    def __init__(self):
        super().__init__()
        self.data = defaultdict(list)

class PP:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def get_key(self):
        return self.key

    def set_key(self, key):
        self.key = key

    def get_val(self):
        return self.val

    def set_val(self, val):
        self.val = val

class PPP:
    def __init__(self, key, val1, val2):
        self.key = key
        self.val1 = val1
        self.val2 = val2

    def get_key(self):
        return self.key

    def set_key(self, key):
        self.key = key

    def get_val1(self):
        return self.val1

    def set_val1(self, val1):
        self.val1 = val1

    def get_val2(self):
        return self.val2

    def set_val2(self, val2):
        self.val2 = val2

class PPL:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def get_key(self):
        return self.key

    def set_key(self, key):
        self.key = key

    def get_val(self):
        return self.val

    def set_val(self, val):
        self.val = val

class PPDL:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def dump(self, output):
        output.write(f"key = {self.key}  val = {' '.join(map(str, self.val))}\n")

class PPKEY:
    def __init__(self, key, val):
        self.key = key
        self.val = val

    def get_key(self):
        return self.key

    def get_val(self):
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

    def get_key(self):
        return self.key

    def get_val(self):
        return self.val

    def __eq__(self, other):
        if isinstance(other, PPLKEY):
            return self.key == other.key and self.val == other.val
        return False

    def __hash__(self):
        return hash((self.key, self.val))

if __name__ == "__main__":
    solver = Solver(sys.stdin, sys.stdout)
    solver.solve()
# End of Code
