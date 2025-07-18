#include <iostream>
#include <vector>
#include <optional>
#include <cmath>
#include <unordered_map>
#include <set>
#include <algorithm>

class Main {
public:
    void main() {
        Main main;
        main.solve();
    }

private:
    void solve() {
        std::cin >> H >> W;
        std::vector<std::vector<int>> c(10, std::vector<int>(10));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                std::cin >> c[i][j];
            }
        }
        std::vector<int> min(10);
        for (int i = 0; i < 10; i++) {
            min[i] = c[i][1];
        }
        for (int tc = 0; tc < 10; tc++) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    min[i] = std::min(min[i], c[i][j] + min[j]);
                }
            }
        }
        int ans = 0;
        for (int h = 1; h <= H; h++) {
            for (int w = 1; w <= W; w++) {
                int A;
                std::cin >> A;
                if (A >= 0) {
                    ans += min[A];
                }
            }
        }
        std::cout << ans << std::endl;
    }

    int H, W;
};

class SieveMobiusFunction {
public:
    SieveMobiusFunction(int size) : size(size), mobiusFunctionValues(size) {
        mobiusFunctionValues[0] = 0;
        mobiusFunctionValues[1] = 1;
        for (int i = 2; i < size; i++) {
            mobiusFunctionValues[i] = 1;
        }
        for (int i = 2; i * i < size; i++) {
            for (int k = 1; i * i * k < size; k++) {
                mobiusFunctionValues[i * i * k] *= 0;
            }
        }

        for (int i = 2; i < size; i++) {
            if (mobiusFunctionValues[i] == 1) {
                for (int k = 1; i * k < size; k++) {
                    mobiusFunctionValues[i * k] *= -2;
                }
            }
            if (mobiusFunctionValues[i] > 1) {
                mobiusFunctionValues[i] = 1;
            }
            if (mobiusFunctionValues[i] < -1) {
                mobiusFunctionValues[i] = -1;
            }
        }
    }

    int get(int n) {
        if (n > size) {
            throw std::runtime_error("n is greater than size.");
        }
        if (n < 0) {
            return 0;
        }
        return mobiusFunctionValues[n];
    }

private:
    int size;
    std::vector<int> mobiusFunctionValues;
};

class PrimeFactorizationMobiusFunction {
public:
    int get(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int num = 0;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                n /= i;
                num++;
                if (n % i == 0) {
                    return 0;
                }
            }
        }
        return num % 2 == 0 ? -1 : 1;
    }
};

class FactorialTableCombCalculator {
public:
    FactorialTableCombCalculator(int size, long mod) : size(size), mod(mod), factorialTable(size + 1), inverseFactorialTable(size + 1) {
        factorialTable[0] = 1L;
        for (int i = 1; i <= size; i++) {
            factorialTable[i] = (factorialTable[i - 1] * i) % mod;
        }
        inverseFactorialTable[size] = inverse(factorialTable[size], mod);
        for (int i = size - 1; i >= 0; i--) {
            inverseFactorialTable[i] = (inverseFactorialTable[i + 1] * (i + 1)) % mod;
        }
    }

    long comb(int n, int m) {
        if (n > size) {
            throw std::runtime_error("n is greater than size.");
        }
        if (n < 0 || m < 0 || n < m) {
            return 0L;
        }
        return (((factorialTable[n] * inverseFactorialTable[m]) % mod) * inverseFactorialTable[n - m]) % mod;
    }

private:
    int size;
    long mod;
    std::vector<long> factorialTable;
    std::vector<long> inverseFactorialTable;

    long inverse(long n, long mod) {
        return pow(n, mod - 2, mod);
    }

    long pow(long n, long p, long mod) {
        if (p == 0) {
            return 1L;
        }
        long half = pow(n, p / 2, mod);
        long ret = (half * half) % mod;
        if (p % 2 == 1) {
            ret = (ret * n) % mod;
        }
        return ret;
    }
};

class TableCombCalculator {
public:
    TableCombCalculator(int size, long mod) : size(size), table(size + 1) {
        table[0] = std::vector<long>(1, 1L);
        for (int n = 1; n <= size; n++) {
            table[n] = std::vector<long>(n + 1);
            table[n][0] = 1L;
            for (int m = 1; m < n; m++) {
                table[n][m] = (table[n - 1][m - 1] + table[n - 1][m]) % mod;
            }
            table[n][n] = 1L;
        }
    }

    long comb(int n, int m) {
        if (n > size) {
            throw std::runtime_error("n is greater than size.");
        }
        if (n < 0 || m < 0 || n < m) {
            return 0L;
        }
        return table[n][m];
    }

private:
    int size;
    std::vector<std::vector<long>> table;
};

class ArrayGraph {
public:
    ArrayGraph(int n) : costArray(n, std::vector<std::optional<long>>(n)), vertexNum(n) {}

    void link(int from, int to, long cost) {
        costArray[from][to] = cost;
    }

    std::optional<long> getCost(int from, int to) {
        return costArray[from][to];
    }

    int getVertexNum() {
        return vertexNum;
    }

private:
    std::vector<std::vector<std::optional<long>>> costArray;
    int vertexNum;
};

class DfsFlowResolver {
public:
    DfsFlowResolver(ArrayGraph graph) : graph(graph) {}

    long maxFlow(int from, int to) {
        long sum = 0L;
        long currentFlow;
        do {
            currentFlow = flow(from, to, LONG_MAX / 3, std::vector<bool>(graph.getVertexNum()));
            sum += currentFlow;
        } while (currentFlow > 0);
        return sum;
    }

private:
    ArrayGraph graph;

    long flow(int from, int to, long current_flow, std::vector<bool>& passed) {
        passed[from] = true;
        if (from == to) {
            return current_flow;
        }
        for (int id = 0; id < graph.getVertexNum(); id++) {
            if (passed[id]) {
                continue;
            }
            std::optional<long> cost = graph.getCost(from, id);
            if (cost.value_or(0L) > 0) {
                long nextFlow = current_flow < cost.value() ? current_flow : cost.value();
                long returnFlow = flow(id, to, nextFlow, passed);
                if (returnFlow > 0) {
                    graph.link(from, id, cost.value() - returnFlow);
                    graph.link(id, from, graph.getCost(id, from).value_or(0L) + returnFlow);
                    return returnFlow;
                }
            }
        }
        return 0L;
    }
};

class BinaryIndexedTree {
public:
    BinaryIndexedTree(int size) : array(size + 1) {}

    void add(int index, long value) {
        for (int i = index; i < array.size(); i += (i & -i)) {
            array[i] += value;
        }
    }

    long getSum(int index) {
        long sum = 0L;
        for (int i = index; i > 0; i -= (i & -i)) {
            sum += array[i];
        }
        return sum;
    }

private:
    std::vector<long> array;
};

class BinaryIndexedTree2D {
public:
    BinaryIndexedTree2D(int size1, int size2) : array(size1 + 1) {
        for (int i = 1; i <= size1; i++) {
            array[i] = std::vector<long>(size2 + 1);
        }
    }

    void add(int index1, int index2, long value) {
        for (int i1 = index1; i1 < array.size(); i1 += (i1 & -i1)) {
            for (int i2 = index2; i2 < array[i1].size(); i2 += (i2 & -i2)) {
                array[i1][i2] += value;
            }
        }
    }

    long getSum(int index1, int index2) {
        long sum = 0L;
        for (int i1 = index1; i1 > 0; i1 -= (i1 & -i1)) {
            for (int i2 = index2; i2 > 0; i2 -= (i2 & -i2)) {
                sum += array[i1][i2];
            }
        }
        return sum;
    }

private:
    std::vector<std::vector<long>> array;
};

class ArrayUnionFind {
public:
    ArrayUnionFind(int size) : parent(size), rank(size), size(size) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    void union(int A, int B) {
        int rootA = root(A);
        int rootB = root(B);
        if (rootA != rootB) {
            if (rank[rootA] < rank[rootB]) {
                unionTo(rootA, rootB);
            } else {
                unionTo(rootB, rootA);
                if (rank[rootA] == rank[rootB]) {
                    rank[rootA]++;
                }
            }
        }
    }

    bool judge(int A, int B) {
        return root(A) == root(B);
    }

    std::set<int> getSet(int id) {
        std::set<int> set;
        for (int i = 0; i < size; i++) {
            if (judge(i, id)) {
                set.insert(i);
            }
        }
        return set;
    }

protected:
    void unionTo(int source, int dest) {
        parent[source] = dest;
    }

    int root(int id) {
        if (parent[id] == id) {
            return id;
        }
        parent[id] = root(parent[id]);
        return parent[id];
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
    int size;
};

class SetUnionFind : public ArrayUnionFind {
public:
    SetUnionFind(int size) : ArrayUnionFind(size) {
        for (int i = 0; i < size; i++) {
            map[i].insert(i);
        }
    }

    std::set<int> getSet(int id) {
        return map[root(id)];
    }

protected:
    void unionTo(int source, int dest) {
        ArrayUnionFind::unionTo(source, dest);
        map[dest].insert(map[source].begin(), map[source].end());
    }

private:
    std::unordered_map<int, std::set<int>> map;
};

class PrimeNumberUtils {
public:
    PrimeNumberUtils(int limit) : limit(limit), isPrimeArray(limit), primes() {
        if (limit > 10000000) {
            std::cerr << "上限の値が高すぎるため素数ユーティリティの初期化でTLEする可能性が大変高いです";
        }
        if (limit > 2) {
            primes.push_back(2);
            isPrimeArray[2] = true;
        }

        for (int i = 3; i < limit; i += 2) {
            if (isPrime(i, primes)) {
                primes.push_back(i);
                isPrimeArray[i] = true;
            }
        }
    }

    std::vector<int> getPrimeNumberList() {
        return primes;
    }

    bool isPrime(int n) {
        return isPrimeArray[n];
    }

private:
    int limit;
    std::vector<bool> isPrimeArray;
    std::vector<int> primes;

    bool isPrime(int n, std::vector<int>& primes) {
        for (int prime : primes) {
            if (n % prime == 0) {
                return false;
            }
            if (prime > std::sqrt(n)) {
                break;
            }
        }
        return true;
    }
};

class LongBit {
public:
    LongBit(int size) : bitArray((size + 63) / 64) {}

    void set(int index, bool bit) {
        int segment = index / 64;
        int inIndex = index % 64;
        if (bit) {
            bitArray[segment] |= 1L << inIndex;
        } else {
            bitArray[segment] &= ~(1L << inIndex);
        }
    }

    bool get(int index) {
        int segment = index / 64;
        int inIndex = index % 64;
        return (bitArray[segment] & (1L << inIndex)) != 0L;
    }

    void shiftRight(int num) {
        int shiftSeg = num / 64;
        int shiftInI = num % 64;
        for (int segment = 0; segment < bitArray.size(); segment++) {
            int sourceSeg = segment + shiftSeg;
            if (sourceSeg < bitArray.size()) {
                bitArray[segment] = bitArray[sourceSeg] >> shiftInI;
                if (shiftInI > 0 && sourceSeg + 1 < bitArray.size()) {
                    bitArray[segment] |= bitArray[sourceSeg + 1] << (64 - shiftInI);
                }
            } else {
                bitArray[segment] = 0L;
            }
        }
    }

    void shiftLeft(int num) {
        int shiftSeg = num / 64;
        int shiftInI = num % 64;
        for (int segment = bitArray.size() - 1; segment >= 0; segment--) {
            int sourceSeg = segment - shiftSeg;
            if (sourceSeg >= 0) {
                bitArray[segment] = bitArray[sourceSeg] << shiftInI;
                if (shiftInI > 0 && sourceSeg > 0) {
                    bitArray[segment] |= bitArray[sourceSeg - 1] >> (64 - shiftInI);
                }
            } else {
                bitArray[segment] = 0L;
            }
        }
    }

    long getLong(int segment) {
        return bitArray[segment];
    }

    void or(LongBit& bitset) {
        for (int segment = 0; segment < bitArray.size(); segment++) {
            bitArray[segment] |= bitset.getLong(segment);
        }
    }

    void and(LongBit& bitset) {
        for (int segment = 0; segment < bitArray.size(); segment++) {
            bitArray[segment] &= bitset.getLong(segment);
        }
    }

private:
    std::vector<long> bitArray;
};

// End of Code
