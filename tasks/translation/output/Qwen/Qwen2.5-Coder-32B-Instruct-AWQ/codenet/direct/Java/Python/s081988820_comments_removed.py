import sys
import math
from collections import defaultdict, deque, Counter
from typing import List, Optional, Set

class Main:
    def __init__(self):
        pass

    def solve(self):
        import sys
        input = sys.stdin.read
        data = input().split()
        index = 0

        def next_int():
            nonlocal index
            result = int(data[index])
            index += 1
            return result

        H = next_int()
        W = next_int()
        c = [[0] * 10 for _ in range(10)]
        for i in range(10):
            for j in range(10):
                c[i][j] = next_int()
        min_cost = [c[i][1] for i in range(10)]
        for _ in range(10):
            for i in range(10):
                for j in range(10):
                    min_cost[i] = min(min_cost[i], c[i][j] + min_cost[j])
        ans = 0
        for _ in range(H * W):
            A = next_int()
            if A >= 0:
                ans += min_cost[A]
        print(ans)

class Scanner:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = []
        self.pointer = 0

    def _load_buffer(self):
        line = self.stream.readline().strip()
        if line:
            self.buffer.extend(line.split())
        else:
            self.buffer = []

    def next(self):
        if self.pointer >= len(self.buffer):
            self._load_buffer()
        if self.pointer < len(self.buffer):
            result = self.buffer[self.pointer]
            self.pointer += 1
            return result
        else:
            raise StopIteration

    def next_int(self):
        return int(self.next())

    def next_float(self):
        return float(self.next())

    def next_str(self):
        return self.next()

class CombCalculator:
    def comb(self, n, m):
        raise NotImplementedError

class MobiusFunction:
    def get(self, n):
        raise NotImplementedError

class SieveMobiusFunction(MobiusFunction):
    def __init__(self, size):
        self.size = size
        self.mobius_function_values = [0] * size
        self.mobius_function_values[1] = 1
        for i in range(2, size):
            self.mobius_function_values[i] = 1
        for i in range(2, int(math.sqrt(size)) + 1):
            if self.mobius_function_values[i] == 1:
                for j in range(i * i, size, i):
                    self.mobius_function_values[j] *= -1
                for j in range(i * i * i, size, i * i):
                    self.mobius_function_values[j] = 0

    def get(self, n):
        if n > self.size:
            raise ValueError("n is greater than size.")
        if n < 0:
            return 0
        return self.mobius_function_values[n]

class PrimeFactorizationMobiusFunction(MobiusFunction):
    def get(self, n):
        if n <= 0:
            return 0
        if n == 1:
            return 1
        num = 0
        for i in range(2, int(math.sqrt(n)) + 1):
            if n % i == 0:
                num += 1
                while n % i == 0:
                    n //= i
            if num > 1:
                return 0
        if n > 1:
            num += 1
        return -1 if num % 2 == 1 else 1

class FactorialTableCombCalculator(CombCalculator):
    def __init__(self, size, mod):
        self.size = size
        self.factorial_table = [1] * (size + 1)
        self.inverse_factorial_table = [1] * (size + 1)
        self.mod = mod
        for i in range(1, size + 1):
            self.factorial_table[i] = self.factorial_table[i - 1] * i % mod
        self.inverse_factorial_table[size] = self.inverse(self.factorial_table[size], mod)
        for i in range(size - 1, 0, -1):
            self.inverse_factorial_table[i] = self.inverse_factorial_table[i + 1] * (i + 1) % mod

    def inverse(self, n, mod):
        return pow(n, mod - 2, mod)

    def comb(self, n, m):
        if n > self.size:
            raise ValueError("n is greater than size.")
        if n < 0 or m < 0 or n < m:
            return 0
        return self.factorial_table[n] * self.inverse_factorial_table[m] % self.mod * self.inverse_factorial_table[n - m] % self.mod

class TableCombCalculator(CombCalculator):
    def __init__(self, size, mod):
        self.size = size
        self.table = [[0] * (n + 1) for n in range(size + 1)]
        for n in range(size + 1):
            self.table[n][0] = 1
            for m in range(1, n):
                self.table[n][m] = (self.table[n - 1][m - 1] + self.table[n - 1][m]) % mod
            self.table[n][n] = 1

    def comb(self, n, m):
        if n > self.size:
            raise ValueError("n is greater than size.")
        if n < 0 or m < 0 or n < m:
            return 0
        return self.table[n][m]

class Graph:
    def link(self, from_node, to_node, cost):
        raise NotImplementedError

    def get_cost(self, from_node, to_node):
        raise NotImplementedError

    def get_vertex_num(self):
        raise NotImplementedError

class FlowResolver:
    def max_flow(self, from_node, to_node):
        raise NotImplementedError

class ArrayGraph(Graph):
    def __init__(self, n):
        self.cost_array = [[0] * n for _ in range(n)]
        self.vertex_num = n

    def link(self, from_node, to_node, cost):
        self.cost_array[from_node][to_node] = cost

    def get_cost(self, from_node, to_node):
        return self.cost_array[from_node][to_node]

    def get_vertex_num(self):
        return self.vertex_num

class DfsFlowResolver(FlowResolver):
    def __init__(self, graph):
        self.graph = graph

    def max_flow(self, from_node, to_node):
        def flow(current_node, to_node, current_flow, passed):
            passed[current_node] = True
            if current_node == to_node:
                return current_flow
            for next_node in range(self.graph.get_vertex_num()):
                if passed[next_node]:
                    continue
                cost = self.graph.get_cost(current_node, next_node)
                if cost > 0:
                    next_flow = min(current_flow, cost)
                    return_flow = flow(next_node, to_node, next_flow, passed)
                    if return_flow > 0:
                        self.graph.link(current_node, next_node, cost - return_flow)
                        self.graph.link(next_node, current_node, self.graph.get_cost(next_node, current_node) + return_flow)
                        return return_flow
            return 0

        sum_flow = 0
        while True:
            current_flow = flow(from_node, to_node, float('inf'), [False] * self.graph.get_vertex_num())
            if current_flow == 0:
                break
            sum_flow += current_flow
        return sum_flow

class BinaryIndexedTree:
    def __init__(self, size):
        self.array = [0] * (size + 1)

    def add(self, index, value):
        while index < len(self.array):
            self.array[index] += value
            index += index & -index

    def get_sum(self, index):
        sum_value = 0
        while index > 0:
            sum_value += self.array[index]
            index -= index & -index
        return sum_value

class BinaryIndexedTree2D:
    def __init__(self, size1, size2):
        self.array = [[0] * (size2 + 1) for _ in range(size1 + 1)]

    def add(self, index1, index2, value):
        i1 = index1
        while i1 < len(self.array):
            i2 = index2
            while i2 < len(self.array[0]):
                self.array[i1][i2] += value
                i2 += i2 & -i2
            i1 += i1 & -i1

    def get_sum(self, index1, index2):
        sum_value = 0
        i1 = index1
        while i1 > 0:
            i2 = index2
            while i2 > 0:
                sum_value += self.array[i1][i2]
                i2 -= i2 & -i2
            i1 -= i1 & -i1
        return sum_value

class UnionFind:
    def union(self, A, B):
        raise NotImplementedError

    def judge(self, A, B):
        raise NotImplementedError

    def get_set(self, id):
        raise NotImplementedError

class SetUnionFind(UnionFind):
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size
        self.map = {i: {i} for i in range(size)}

    def union(self, A, B):
        root_A = self.root(A)
        root_B = self.root(B)
        if root_A != root_B:
            if self.rank[root_A] < self.rank[root_B]:
                self.union_to(root_A, root_B)
            else:
                self.union_to(root_B, root_A)
                if self.rank[root_A] == self.rank[root_B]:
                    self.rank[root_A] += 1

    def union_to(self, source, dest):
        self.parent[source] = dest
        self.map[dest].update(self.map[source])
        del self.map[source]

    def judge(self, A, B):
        return self.root(A) == self.root(B)

    def get_set(self, id):
        return self.map[self.root(id)]

    def root(self, id):
        if self.parent[id] == id:
            return id
        self.parent[id] = self.root(self.parent[id])
        return self.parent[id]

class ArrayUnionFind(UnionFind):
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size
        self.size = size

    def union(self, A, B):
        root_A = self.root(A)
        root_B = self.root(B)
        if root_A != root_B:
            if self.rank[root_A] < self.rank[root_B]:
                self.union_to(root_A, root_B)
            else:
                self.union_to(root_B, root_A)
                if self.rank[root_A] == self.rank[root_B]:
                    self.rank[root_A] += 1

    def union_to(self, source, dest):
        self.parent[source] = dest

    def judge(self, A, B):
        return self.root(A) == self.root(B)

    def get_set(self, id):
        return {i for i in range(self.size) if self.judge(i, id)}

    def root(self, id):
        if self.parent[id] == id:
            return id
        self.parent[id] = self.root(self.parent[id])
        return self.parent[id]

class PrimeNumberUtils:
    def __init__(self, limit):
        if limit > 10000000:
            print("上限の値が高すぎるため素数ユーティリティの初期化でTLEする可能性が大変高いです", file=sys.stderr)
        self.primes = []
        self.is_prime_array = [False] * limit
        if limit > 2:
            self.primes.append(2)
            self.is_prime_array[2] = True

        for i in range(3, limit, 2):
            if self.is_prime(i):
                self.primes.append(i)
                self.is_prime_array[i] = True

    def get_prime_number_list(self):
        return self.primes

    def is_prime(self, n):
        return self.is_prime_array[n]

    def is_prime(self, n, primes=None):
        if primes is None:
            primes = self.primes
        for prime in primes:
            if n % prime == 0:
                return False
            if prime > math.sqrt(n):
                break
        return True

class BitSet:
    def set(self, index, bit):
        raise NotImplementedError

    def get(self, index):
        raise NotImplementedError

    def shift_right(self, num):
        raise NotImplementedError

    def shift_left(self, num):
        raise NotImplementedError

    def or_(self, bitset):
        raise NotImplementedError

    def and_(self, bitset):
        raise NotImplementedError

class LongBit(BitSet):
    def __init__(self, size):
        self.bit_array = [0] * ((size + 63) // 64)

    def set(self, index, bit):
        segment = index // 64
        in_index = index % 64
        if bit:
            self.bit_array[segment] |= 1 << in_index
        else:
            self.bit_array[segment] &= ~(1 << in_index)

    def get(self, index):
        segment = index // 64
        in_index = index % 64
        return (self.bit_array[segment] & (1 << in_index)) != 0

    def shift_right(self, num):
        shift_seg = num // 64
        shift_in_i = num % 64
        for segment in range(len(self.bit_array)):
            source_seg = segment + shift_seg
            if source_seg < len(self.bit_array):
                self.bit_array[segment] = self.bit_array[source_seg] >> shift_in_i
                if shift_in_i > 0 and source_seg + 1 < len(self.bit_array):
                    self.bit_array[segment] |= self.bit_array[source_seg + 1] << (64 - shift_in_i)
            else:
                self.bit_array[segment] = 0

    def shift_left(self, num):
        shift_seg = num // 64
        shift_in_i = num % 64
        for segment in range(len(self.bit_array) - 1, -1, -1):
            source_seg = segment - shift_seg
            if source_seg >= 0:
                self.bit_array[segment] = self.bit_array[source_seg] << shift_in_i
                if shift_in_i > 0 and source_seg > 0:
                    self.bit_array[segment] |= self.bit_array[source_seg - 1] >> (64 - shift_in_i)
            else:
                self.bit_array[segment] = 0

    def get_long(self, segment):
        return self.bit_array[segment]

    def or_(self, bitset):
        if not isinstance(bitset, LongBit):
            return
        for segment in range(len(self.bit_array)):
            self.bit_array[segment] |= bitset.get_long(segment)

    def and_(self, bitset):
        if not isinstance(bitset, LongBit):
            return
        for segment in range(len(self.bit_array)):
            self.bit_array[segment] &= bitset.get_long(segment)

if __name__ == "__main__":
    main = Main()
    main.solve()
# End of Code
