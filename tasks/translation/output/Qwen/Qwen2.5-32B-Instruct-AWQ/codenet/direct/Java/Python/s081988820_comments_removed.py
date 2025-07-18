import sys
from typing import List, Optional

class Main:
    def solve(self):
        H, W = map(int, input().split())
        c = [list(map(int, input().split())) for _ in range(10)]
        min_cost = [c[i][1] for i in range(10)]
        
        for _ in range(10):
            for i in range(10):
                for j in range(10):
                    min_cost[i] = min(min_cost[i], c[i][j] + min_cost[j])
        
        ans = 0
        for _ in range(H):
            A = list(map(int, input().split()))
            for a in A:
                if a >= 0:
                    ans += min_cost[a]
        
        print(ans)

class Scanner:
    def __init__(self, input_stream):
        self.in_stream = input_stream
        self.buffer = bytearray(1024)
        self.index = 0
        self.length = 0

    def is_printable_char(self, c):
        return '!' <= chr(c) <= '~'

    def is_digit(self, c):
        return '0' <= chr(c) <= '9'

    def has_next_byte(self):
        if self.index < self.length:
            return True
        try:
            self.length = self.in_stream.readinto(self.buffer)
            self.index = 0
        except Exception as e:
            print(e)
        return self.length > 0

    def has_next(self):
        while self.has_next_byte() and not self.is_printable_char(self.buffer[self.index]):
            self.index += 1
        return self.has_next_byte()

    def read_byte(self):
        return self.buffer[self.index] if self.has_next_byte() else -1

    def next(self):
        if not self.has_next():
            raise RuntimeError("no input")
        sb = []
        b = self.read_byte()
        while self.is_printable_char(b):
            sb.append(chr(b))
            b = self.read_byte()
        return ''.join(sb)

    def next_long(self):
        if not self.has_next():
            raise RuntimeError("no input")
        value = 0
        minus = False
        b = self.read_byte()
        if b == ord('-'):
            minus = True
            b = self.read_byte()
        while self.is_printable_char(b):
            if self.is_digit(b):
                value = value * 10 + (b - ord('0'))
            b = self.read_byte()
        return -value if minus else value

    def next_int(self):
        return int(self.next_long())

    def next_double(self):
        return float(self.next())

class CombCalculator:
    def comb(self, n: int, m: int) -> int:
        pass

class MobiusFunction:
    def get(self, n: int) -> int:
        pass

class SieveMobiusFunction(MobiusFunction):
    def __init__(self, size: int):
        self.size = size
        self.mobius_function_values = [0] * size
        self.mobius_function_values[1] = 1
        for i in range(2, size):
            self.mobius_function_values[i] = 1
        for i in range(2, int(size ** 0.5) + 1):
            for k in range(1, (size - 1) // (i * i) + 1):
                self.mobius_function_values[i * i * k] = 0
        for i in range(2, size):
            if self.mobius_function_values[i] == 1:
                for k in range(1, (size - 1) // i + 1):
                    self.mobius_function_values[i * k] *= -1
            if self.mobius_function_values[i] > 1:
                self.mobius_function_values[i] = 1
            if self.mobius_function_values[i] < -1:
                self.mobius_function_values[i] = -1

    def get(self, n: int) -> int:
        if n > self.size:
            raise RuntimeError("n is greater than size.")
        if n < 0:
            return 0
        return self.mobius_function_values[n]

class PrimeFactorizationMobiusFunction(MobiusFunction):
    def get(self, n: int) -> int:
        if n <= 0:
            return 0
        if n == 1:
            return 1
        num = 0
        for i in range(2, n):
            if n % i == 0:
                n //= i
                num += 1
                if n % i == 0:
                    return 0
        return -1 if num % 2 else 1

class FactorialTableCombCalculator(CombCalculator):
    def __init__(self, size: int, mod: int):
        self.size = size
        self.factorial_table = [1] * (size + 1)
        self.inverse_factorial_table = [1] * (size + 1)
        self.mod = mod
        for i in range(1, size + 1):
            self.factorial_table[i] = (self.factorial_table[i - 1] * i) % mod
        self.inverse_factorial_table[size] = self.inverse(self.factorial_table[size], mod)
        for i in range(size - 1, 0, -1):
            self.inverse_factorial_table[i] = (self.inverse_factorial_table[i + 1] * (i + 1)) % mod

    def inverse(self, n: int, mod: int) -> int:
        return pow(n, mod - 2, mod)

    def comb(self, n: int, m: int) -> int:
        if n > self.size:
            raise RuntimeError("n is greater than size.")
        if n < 0 or m < 0 or n < m:
            return 0
        return (((self.factorial_table[n] * self.inverse_factorial_table[m]) % self.mod) * self.inverse_factorial_table[n - m]) % self.mod

class TableCombCalculator(CombCalculator):
    def __init__(self, size: int, mod: int):
        self.size = size
        self.table = [[1] + [0] * i for i in range(size + 1)]
        for n in range(1, size + 1):
            for m in range(1, n):
                self.table[n][m] = (self.table[n - 1][m - 1] + self.table[n - 1][m]) % mod
            self.table[n][n] = 1

    def comb(self, n: int, m: int) -> int:
        if n > self.size:
            raise RuntimeError("n is greater than size.")
        if n < 0 or m < 0 or n < m:
            return 0
        return self.table[n][m]

class Graph:
    def link(self, from_: int, to: int, cost: int):
        pass

    def get_cost(self, from_: int, to: int) -> Optional[int]:
        pass

    def get_vertex_num(self) -> int:
        pass

class FlowResolver:
    def max_flow(self, from_: int, to: int) -> int:
        pass

class ArrayGraph(Graph):
    def __init__(self, n: int):
        self.cost_array = [[None] * n for _ in range(n)]
        self.vertex_num = n

    def link(self, from_: int, to: int, cost: int):
        self.cost_array[from_][to] = cost

    def get_cost(self, from_: int, to: int) -> Optional[int]:
        return self.cost_array[from_][to]

    def get_vertex_num(self) -> int:
        return self.vertex_num

class DfsFlowResolver(FlowResolver):
    def __init__(self, graph: Graph):
        self.graph = graph

    def max_flow(self, from_: int, to: int) -> int:
        sum_ = 0
        current_flow = 0
        while True:
            current_flow = self.flow(from_, to, sys.maxsize // 3, [False] * self.graph.get_vertex_num())
            sum_ += current_flow
            if current_flow == 0:
                break
        return sum_

    def flow(self, from_: int, to: int, current_flow: int, passed: List[bool]) -> int:
        passed[from_] = True
        if from_ == to:
            return current_flow
        for id_ in range(self.graph.get_vertex_num()):
            if passed[id_]:
                continue
            cost = self.graph.get_cost(from_, id_)
            if cost and cost > 0:
                next_flow = min(current_flow, cost)
                return_flow = self.flow(id_, to, next_flow, passed)
                if return_flow > 0:
                    self.graph.link(from_, id_, cost - return_flow)
                    self.graph.link(id_, from_, self.graph.get_cost(id_, from_) or 0 + return_flow)
                    return return_flow
        return 0

class BinaryIndexedTree:
    def __init__(self, size: int):
        self.array = [0] * (size + 1)

    def add(self, index: int, value: int):
        while index < len(self.array):
            self.array[index] += value
            index += index & -index

    def get_sum(self, index: int) -> int:
        sum_ = 0
        while index > 0:
            sum_ += self.array[index]
            index -= index & -index
        return sum_

class BinaryIndexedTree2D:
    def __init__(self, size1: int, size2: int):
        self.array = [[0] * (size2 + 1) for _ in range(size1 + 1)]

    def add(self, index1: int, index2: int, value: int):
        i1 = index1
        while i1 < len(self.array):
            i2 = index2
            while i2 < len(self.array[0]):
                self.array[i1][i2] += value
                i2 += i2 & -i2
            i1 += i1 & -i1

    def get_sum(self, index1: int, index2: int) -> int:
        sum_ = 0
        i1 = index1
        while i1 > 0:
            i2 = index2
            while i2 > 0:
                sum_ += self.array[i1][i2]
                i2 -= i2 & -i2
            i1 -= i1 & -i1
        return sum_

class UnionFind:
    def union(self, A: int, B: int):
        pass

    def judge(self, A: int, B: int) -> bool:
        pass

    def get_set(self, id_: int) -> List[int]:
        pass

class SetUnionFind(UnionFind):
    def __init__(self, size: int):
        self.parent = list(range(size))
        self.rank = [0] * size
        self.map_ = {i: {i} for i in range(size)}

    def union(self, A: int, B: int):
        rootA = self.root(A)
        rootB = self.root(B)
        if rootA != rootB:
            if self.rank[rootA] < self.rank[rootB]:
                self.union_to(rootA, rootB)
            else:
                self.union_to(rootB, rootA)
                if self.rank[rootA] == self.rank[rootB]:
                    self.rank[rootA] += 1

    def union_to(self, source: int, dest: int):
        self.parent[source] = dest
        self.map_[dest].update(self.map_[source])

    def judge(self, A: int, B: int) -> bool:
        return self.root(A) == self.root(B)

    def get_set(self, id_: int) -> List[int]:
        return list(self.map_[self.root(id_)])

    def root(self, id_: int) -> int:
        if self.parent[id_] == id_:
            return id_
        self.parent[id_] = self.root(self.parent[id_])
        return self.parent[id_]

class ArrayUnionFind(UnionFind):
    def __init__(self, size: int):
        self.parent = list(range(size))
        self.rank = [0] * size
        self.size = size

    def union(self, A: int, B: int):
        rootA = self.root(A)
        rootB = self.root(B)
        if rootA != rootB:
            if self.rank[rootA] < self.rank[rootB]:
                self.union_to(rootA, rootB)
            else:
                self.union_to(rootB, rootA)
                if self.rank[rootA] == self.rank[rootB]:
                    self.rank[rootA] += 1

    def union_to(self, source: int, dest: int):
        self.parent[source] = dest

    def judge(self, A: int, B: int) -> bool:
        return self.root(A) == self.root(B)

    def get_set(self, id_: int) -> List[int]:
        return [i for i in range(self.size) if self.judge(i, id_)]

    def root(self, id_: int) -> int:
        if self.parent[id_] == id_:
            return id_
        self.parent[id_] = self.root(self.parent[id_])
        return self.parent[id_]

class PrimeNumberUtils:
    def __init__(self, limit: int):
        if limit > 10000000:
            print("上限の値が高すぎるため素数ユーティリティの初期化でTLEする可能性が大変高いです")
        self.primes = []
        self.is_prime_array = [False] * limit
        if limit > 2:
            self.primes.append(2)
            self.is_prime_array[2] = True
        for i in range(3, limit, 2):
            if self.is_prime(i, self.primes):
                self.primes.append(i)
                self.is_prime_array[i] = True

    def get_prime_number_list(self) -> List[int]:
        return self.primes

    def is_prime(self, n: int) -> bool:
        return self.is_prime_array[n]

    def is_prime(self, n: int, primes: List[int]) -> bool:
        for prime in primes:
            if n % prime == 0:
                return False
            if prime > int(n ** 0.5):
                break
        return True

class BitSet:
    def set(self, index: int, bit: bool):
        pass

    def get(self, index: int) -> bool:
        pass

    def shift_right(self, num: int):
        pass

    def shift_left(self, num: int):
        pass

    def or_(self, bitset: 'BitSet'):
        pass

    def and_(self, bitset: 'BitSet'):
        pass

class LongBit(BitSet):
    def __init__(self, size: int):
        self.bit_array = [0] * ((size + 63) // 64)

    def set(self, index: int, bit: bool):
        segment = index // 64
        in_index = index % 64
        if bit:
            self.bit_array[segment] |= 1 << in_index
        else:
            self.bit_array[segment] &= ~(1 << in_index)

    def get(self, index: int) -> bool:
        segment = index // 64
        in_index = index % 64
        return (self.bit_array[segment] & (1 << in_index)) != 0

    def shift_right(self, num: int):
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

    def shift_left(self, num: int):
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

    def get_long(self, segment: int) -> int:
        return self.bit_array[segment]

    def or_(self, bitset: 'BitSet'):
        if not isinstance(bitset, LongBit):
            return
        for segment in range(len(self.bit_array)):
            self.bit_array[segment] |= bitset.get_long(segment)

    def and_(self, bitset: 'BitSet'):
        if not isinstance(bitset, LongBit):
            return
        for segment in range(len(self.bit_array)):
            self.bit_array[segment] &= bitset.get_long(segment)

if __name__ == "__main__":
    main = Main()
    main.solve()
# End of Code
