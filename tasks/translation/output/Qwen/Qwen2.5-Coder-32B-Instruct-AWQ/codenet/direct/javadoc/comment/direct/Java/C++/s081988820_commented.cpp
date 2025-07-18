#include <iostream>
#include <vector>
#include <optional>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Main {
public:
    void solve() {
        int H, W;
        cin >> H >> W;
        vector<vector<int>> c(10, vector<int>(10));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cin >> c[i][j];
            }
        }
        vector<int> min_cost(10);
        for (int i = 0; i < 10; ++i) {
            min_cost[i] = c[i][1];
        }
        for (int k = 0; k < 10; ++k) {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    min_cost[i] = min(min_cost[i], c[i][k] + min_cost[k]);
                }
            }
        }
        int ans = 0;
        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                int A;
                cin >> A;
                if (A >= 0) {
                    ans += min_cost[A];
                }
            }
        }
        cout << ans << endl;
    }
};

class SieveMobiusFunction {
public:
    SieveMobiusFunction(int size) : size(size), mobiusFunctionValues(size) {
        mobiusFunctionValues[0] = 0;
        mobiusFunctionValues[1] = 1;
        for (int i = 2; i < size; ++i) {
            mobiusFunctionValues[i] = 1;
        }
        for (int i = 2; i * i < size; ++i) {
            for (int k = 1; i * i * k < size; ++k) {
                mobiusFunctionValues[i * i * k] = 0;
            }
        }
        for (int i = 2; i < size; ++i) {
            if (mobiusFunctionValues[i] == 1) {
                for (int k = 1; i * k < size; ++k) {
                    mobiusFunctionValues[i * k] *= -1;
                }
            }
        }
    }

    int get(int n) {
        if (n >= size) {
            throw runtime_error("n is greater than size.");
        }
        if (n < 0) {
            return 0;
        }
        return mobiusFunctionValues[n];
    }

private:
    int size;
    vector<int> mobiusFunctionValues;
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
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                n /= i;
                num++;
                if (n % i == 0) {
                    return 0;
                }
            }
        }
        return (num % 2 == 0) ? -1 : 1;
    }
};

class FactorialTableCombCalculator {
public:
    FactorialTableCombCalculator(int size, long long mod) : size(size), mod(mod) {
        factorialTable.resize(size + 1);
        inverseFactorialTable.resize(size + 1);

        factorialTable[0] = 1LL;
        for (int i = 1; i <= size; ++i) {
            factorialTable[i] = (factorialTable[i - 1] * i) % mod;
        }
        inverseFactorialTable[size] = inverse(factorialTable[size], mod);
        for (int i = size - 1; i >= 0; --i) {
            inverseFactorialTable[i] = (inverseFactorialTable[i + 1] * (i + 1)) % mod;
        }
    }

    long long comb(int n, int m) {
        if (n > size) {
            throw runtime_error("n is greater than size.");
        }
        if (n < 0 || m < 0 || n < m) {
            return 0LL;
        }
        return (((factorialTable[n] * inverseFactorialTable[m]) % mod) * inverseFactorialTable[n - m]) % mod;
    }

private:
    int size;
    long long mod;
    vector<long long> factorialTable;
    vector<long long> inverseFactorialTable;

    long long inverse(long long n, long long mod) {
        return pow(n, mod - 2, mod);
    }

    long long pow(long long n, long long p, long long mod) {
        if (p == 0) {
            return 1LL;
        }
        long long half = pow(n, p / 2, mod);
        long long ret = (half * half) % mod;
        if (p % 2 == 1) {
            ret = (ret * n) % mod;
        }
        return ret;
    }
};

class TableCombCalculator {
public:
    TableCombCalculator(int size, long long mod) : size(size), mod(mod) {
        table.resize(size + 1);
        table[0].resize(1, 1LL);
        for (int n = 1; n <= size; ++n) {
            table[n].resize(n + 1);
            table[n][0] = 1LL;
            for (int m = 1; m < n; ++m) {
                table[n][m] = (table[n - 1][m - 1] + table[n - 1][m]) % mod;
            }
            table[n][n] = 1LL;
        }
    }

    long long comb(int n, int m) {
        if (n > size) {
            throw runtime_error("n is greater than size.");
        }
        if (n < 0 || m < 0 || n < m) {
            return 0LL;
        }
        return table[n][m];
    }

private:
    int size;
    long long mod;
    vector<vector<long long>> table;
};

class ArrayGraph {
public:
    ArrayGraph(int n) : vertexNum(n), costArray(n, vector<optional<long long>>(n)) {}

    void link(int from, int to, long long cost) {
        costArray[from][to] = cost;
    }

    optional<long long> getCost(int from, int to) {
        return costArray[from][to];
    }

    int getVertexNum() {
        return vertexNum;
    }

private:
    int vertexNum;
    vector<vector<optional<long long>>> costArray;
};

class DfsFlowResolver {
public:
    DfsFlowResolver(ArrayGraph& graph) : graph(graph) {}

    long long maxFlow(int from, int to) {
        long long sum = 0LL;
        long long currentFlow;
        do {
            vector<bool> passed(graph.getVertexNum(), false);
            currentFlow = flow(from, to, LLONG_MAX / 3, passed);
            sum += currentFlow;
        } while (currentFlow > 0);
        return sum;
    }

private:
    ArrayGraph& graph;

    long long flow(int from, int to, long long current_flow, vector<bool>& passed) {
        passed[from] = true;
        if (from == to) {
            return current_flow;
        }
        for (int id = 0; id < graph.getVertexNum(); ++id) {
            if (passed[id]) {
                continue;
            }
            auto cost = graph.getCost(from, id);
            if (cost.has_value() && cost.value() > 0) {
                long long nextFlow = min(current_flow, cost.value());
                long long returnFlow = flow(id, to, nextFlow, passed);
                if (returnFlow > 0) {
                    graph.link(from, id, cost.value() - returnFlow);
                    graph.link(id, from, graph.getCost(id, from).value_or(0LL) + returnFlow);
                    return returnFlow;
                }
            }
        }
        return 0LL;
    }
};

class BinaryIndexedTree {
public:
    BinaryIndexedTree(int size) : array(size + 1) {}

    void add(int index, long long value) {
        for (int i = index; i < array.size(); i += (i & -i)) {
            array[i] += value;
        }
    }

    long long getSum(int index) {
        long long sum = 0LL;
        for (int i = index; i > 0; i -= (i & -i)) {
            sum += array[i];
        }
        return sum;
    }

private:
    vector<long long> array;
};

class BinaryIndexedTree2D {
public:
    BinaryIndexedTree2D(int size1, int size2) : array(size1 + 1, vector<long long>(size2 + 1)) {}

    void add(int index1, int index2, long long value) {
        for (int i1 = index1; i1 < array.size(); i1 += (i1 & -i1)) {
            for (int i2 = index2; i2 < array[i1].size(); i2 += (i2 & -i2)) {
                array[i1][i2] += value;
            }
        }
    }

    long long getSum(int index1, int index2) {
        long long sum = 0LL;
        for (int i1 = index1; i1 > 0; i1 -= (i1 & -i1)) {
            for (int i2 = index2; i2 > 0; i2 -= (i2 & -i2)) {
                sum += array[i1][i2];
            }
        }
        return sum;
    }

private:
    vector<vector<long long>> array;
};

class UnionFind {
public:
    virtual void unionSet(int A, int B) = 0;
    virtual bool judge(int A, int B) = 0;
    virtual unordered_set<int> getSet(int id) = 0;
};

class ArrayUnionFind : public UnionFind {
public:
    ArrayUnionFind(int size) : size(size), parent(size), rank(size) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    void unionSet(int A, int B) override {
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

    bool judge(int A, int B) override {
        return root(A) == root(B);
    }

    unordered_set<int> getSet(int id) override {
        unordered_set<int> set;
        for (int i = 0; i < size; ++i) {
            if (judge(i, id)) {
                set.insert(i);
            }
        }
        return set;
    }

protected:
    int root(int id) {
        if (parent[id] == id) {
            return id;
        }
        parent[id] = root(parent[id]);
        return parent[id];
    }

    void unionTo(int source, int dest) {
        parent[source] = dest;
    }

private:
    int size;
    vector<int> parent;
    vector<int> rank;
};

class SetUnionFind : public ArrayUnionFind {
public:
    SetUnionFind(int size) : ArrayUnionFind(size) {
        for (int i = 0; i < size; ++i) {
            map[i].insert(i);
        }
    }

    void unionSet(int A, int B) override {
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

    unordered_set<int> getSet(int id) override {
        return map[root(id)];
    }

protected:
    void unionTo(int source, int dest) override {
        ArrayUnionFind::unionTo(source, dest);
        map[dest].insert(map[source].begin(), map[source].end());
    }

private:
    unordered_map<int, unordered_set<int>> map;
};

class PrimeNumberUtils {
public:
    PrimeNumberUtils(int limit) : limit(limit) {
        if (limit > 10000000) {
            cerr << "上限の値が高すぎるため素数ユーティリティの初期化でTLEする可能性が大変高いです" << endl;
        }
        isPrimeArray.resize(limit, false);
        if (limit > 2) {
            primes.push_back(2);
            isPrimeArray[2] = true;
        }

        for (int i = 3; i < limit; i += 2) {
            if (isPrime(i)) {
                primes.push_back(i);
                isPrimeArray[i] = true;
            }
        }
    }

    vector<int> getPrimeNumberList() {
        return primes;
    }

    bool isPrime(int n) {
        return isPrimeArray[n];
    }

private:
    int limit;
    vector<int> primes;
    vector<bool> isPrimeArray;

    bool isPrime(int n) {
        for (int prime : primes) {
            if (n % prime == 0) {
                return false;
            }
            if (prime > sqrt(n)) {
                break;
            }
        }
        return true;
    }
};

class BitSet {
public:
    virtual void set(int index, bool bit) = 0;
    virtual bool get(int index) = 0;
    virtual void shiftRight(int num) = 0;
    virtual void shiftLeft(int num) = 0;
    virtual void orOp(BitSet& bitset) = 0;
    virtual void andOp(BitSet& bitset) = 0;
};

class LongBit : public BitSet {
public:
    LongBit(int size) : bitArray((size + 63) / 64) {}

    void set(int index, bool bit) override {
        int segment = index / 64;
        int inIndex = index % 64;
        if (bit) {
            bitArray[segment] |= 1LL << inIndex;
        } else {
            bitArray[segment] &= ~(1LL << inIndex);
        }
    }

    bool get(int index) override {
        int segment = index / 64;
        int inIndex = index % 64;
        return (bitArray[segment] & (1LL << inIndex)) != 0LL;
    }

    void shiftRight(int num) override {
        int shiftSeg = num / 64;
        int shiftInI = num % 64;
        for (int segment = 0; segment < bitArray.size(); ++segment) {
            int sourceSeg = segment + shiftSeg;
            if (sourceSeg < bitArray.size()) {
                bitArray[segment] = bitArray[sourceSeg] >> shiftInI;
                if (shiftInI > 0 && sourceSeg + 1 < bitArray.size()) {
                    bitArray[segment] |= bitArray[sourceSeg + 1] << (64 - shiftInI);
                }
            } else {
                bitArray[segment] = 0LL;
            }
        }
    }

    void shiftLeft(int num) override {
        int shiftSeg = num / 64;
        int shiftInI = num % 64;
        for (int segment = bitArray.size() - 1; segment >= 0; --segment) {
            int sourceSeg = segment - shiftSeg;
            if (sourceSeg >= 0) {
                bitArray[segment] = bitArray[sourceSeg] << shiftInI;
                if (shiftInI > 0 && sourceSeg > 0) {
                    bitArray[segment] |= bitArray[sourceSeg - 1] >> (64 - shiftInI);
                }
            } else {
                bitArray[segment] = 0LL;
            }
        }
    }

    void orOp(BitSet& bitset) override {
        LongBit* other = dynamic_cast<LongBit*>(&bitset);
        if (other) {
            for (int segment = 0; segment < bitArray.size(); ++segment) {
                bitArray[segment] |= other->bitArray[segment];
            }
        }
    }

    void andOp(BitSet& bitset) override {
        LongBit* other = dynamic_cast<LongBit*>(&bitset);
        if (other) {
            for (int segment = 0; segment < bitArray.size(); ++segment) {
                bitArray[segment] &= other->bitArray[segment];
            }
        }
    }

private:
    vector<long long> bitArray;
};

int main() {
    Main main;
    main.solve();
    return 0;
}
// End of Code
