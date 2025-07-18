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

class Scanner {
private:
    istream& in;
    string buffer;
    size_t index;

public:
    Scanner(istream& in) : in(in), index(0) {}

    bool hasNext() {
        while (index < buffer.size() && !isPrintableChar(buffer[index])) {
            index++;
        }
        return index < buffer.size();
    }

    char nextChar() {
        if (!hasNext()) {
            throw runtime_error("no input");
        }
        return buffer[index++];
    }

    string next() {
        if (!hasNext()) {
            throw runtime_error("no input");
        }
        string result;
        while (index < buffer.size() && isPrintableChar(buffer[index])) {
            result += buffer[index++];
        }
        return result;
    }

    long nextLong() {
        if (!hasNext()) {
            throw runtime_error("no input");
        }
        long value = 0;
        bool minus = false;
        char c = nextChar();
        if (c == '-') {
            minus = true;
            c = nextChar();
        }
        while (isdigit(c)) {
            value = value * 10 + (c - '0');
            c = nextChar();
        }
        return minus ? -value : value;
    }

    int nextInt() {
        return static_cast<int>(nextLong());
    }

    double nextDouble() {
        return stod(next());
    }

private:
    bool isPrintableChar(char c) {
        return '!' <= c && c <= '~';
    }

    bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }
};

class CombCalculator {
public:
    virtual long comb(int n, int m) = 0;
};

class MobiusFunction {
public:
    virtual int get(int n) = 0;
};

class SieveMobiusFunction : public MobiusFunction {
private:
    int size;
    vector<int> mobiusFunctionValues;

public:
    SieveMobiusFunction(int size) : size(size), mobiusFunctionValues(size) {
        mobiusFunctionValues[0] = 0;
        mobiusFunctionValues[1] = 1;
        for (int i = 2; i < size; ++i) {
            mobiusFunctionValues[i] = 1;
        }
        for (int i = 2; i * i < size; ++i) {
            for (int k = 1; i * i * k < size; ++k) {
                mobiusFunctionValues[i * i * k] *= 0;
            }
        }
        for (int i = 2; i < size; ++i) {
            if (mobiusFunctionValues[i] == 1) {
                for (int k = 1; i * k < size; ++k) {
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

    int get(int n) override {
        if (n > size) {
            throw runtime_error("n is greater than size.");
        }
        if (n < 0) {
            return 0;
        }
        return mobiusFunctionValues[n];
    }
};

class PrimeFactorizationMobiusFunction : public MobiusFunction {
public:
    int get(int n) override {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int num = 0;
        for (int i = 2; i < n; ++i) {
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

class FactorialTableCombCalculator : public CombCalculator {
private:
    int size;
    vector<long> factorialTable;
    vector<long> inverseFactorialTable;
    long mod;

public:
    FactorialTableCombCalculator(int size, long mod) : size(size), mod(mod) {
        factorialTable.resize(size + 1);
        inverseFactorialTable.resize(size + 1);

        factorialTable[0] = 1L;
        for (int i = 1; i <= size; ++i) {
            factorialTable[i] = (factorialTable[i - 1] * i) % mod;
        }
        inverseFactorialTable[size] = inverse(factorialTable[size], mod);
        for (int i = size - 1; i >= 0; --i) {
            inverseFactorialTable[i] = (inverseFactorialTable[i + 1] * (i + 1)) % mod;
        }
    }

    long comb(int n, int m) override {
        if (n > size) {
            throw runtime_error("n is greater than size.");
        }
        if (n < 0 || m < 0 || n < m) {
            return 0L;
        }
        return (((factorialTable[n] * inverseFactorialTable[m]) % mod) * inverseFactorialTable[n - m]) % mod;
    }

private:
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

class TableCombCalculator : public CombCalculator {
private:
    vector<vector<long>> table;
    int size;

public:
    TableCombCalculator(int size, long mod) : size(size) {
        table.resize(size + 1);
        table[0].resize(1, 1L);
        for (int n = 1; n <= size; ++n) {
            table[n].resize(n + 1);
            table[n][0] = 1L;
            for (int m = 1; m < n; ++m) {
                table[n][m] = (table[n - 1][m - 1] + table[n - 1][m]) % mod;
            }
            table[n][n] = 1L;
        }
    }

    long comb(int n, int m) override {
        if (n > size) {
            throw runtime_error("n is greater than size.");
        }
        if (n < 0 || m < 0 || n < m) {
            return 0L;
        }
        return table[n][m];
    }
};

class Graph {
public:
    virtual void link(int from, int to, long cost) = 0;
    virtual optional<long> getCost(int from, int to) = 0;
    virtual int getVertexNum() = 0;
};

class FlowResolver {
public:
    virtual long maxFlow(int from, int to) = 0;
};

class ArrayGraph : public Graph {
private:
    vector<vector<optional<long>>> costArray;
    int vertexNum;

public:
    ArrayGraph(int n) : vertexNum(n) {
        costArray.resize(n, vector<optional<long>>(n));
    }

    void link(int from, int to, long cost) override {
        costArray[from][to] = cost;
    }

    optional<long> getCost(int from, int to) override {
        return costArray[from][to];
    }

    int getVertexNum() override {
        return vertexNum;
    }
};

class DfsFlowResolver : public FlowResolver {
private:
    Graph* graph;

public:
    DfsFlowResolver(Graph* graph) : graph(graph) {}

    long maxFlow(int from, int to) override {
        long sum = 0L;
        long currentFlow;
        do {
            vector<bool> passed(graph->getVertexNum(), false);
            currentFlow = flow(from, to, numeric_limits<long>::max() / 3, passed);
            sum += currentFlow;
        } while (currentFlow > 0);
        return sum;
    }

private:
    long flow(int from, int to, long current_flow, vector<bool>& passed) {
        passed[from] = true;
        if (from == to) {
            return current_flow;
        }
        for (int id = 0; id < graph->getVertexNum(); ++id) {
            if (passed[id]) {
                continue;
            }
            auto cost = graph->getCost(from, id);
            if (cost.has_value() && cost.value() > 0) {
                long nextFlow = min(current_flow, cost.value());
                long returnFlow = flow(id, to, nextFlow, passed);
                if (returnFlow > 0) {
                    graph->link(from, id, cost.value() - returnFlow);
                    auto reverseCost = graph->getCost(id, from);
                    graph->link(id, from, reverseCost.has_value() ? reverseCost.value() + returnFlow : returnFlow);
                    return returnFlow;
                }
            }
        }
        return 0L;
    }
};

class BinaryIndexedTree {
private:
    vector<long> array;

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
};

class BinaryIndexedTree2D {
private:
    vector<vector<long>> array;

public:
    BinaryIndexedTree2D(int size1, int size2) {
        array.resize(size1 + 1, vector<long>(size2 + 1));
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
};

class UnionFind {
public:
    virtual void unite(int A, int B) = 0;
    virtual bool same(int A, int B) = 0;
    virtual unordered_set<int> getSet(int id) = 0;
};

class ArrayUnionFind : public UnionFind {
protected:
    vector<int> parent;
    vector<int> rank;
    int size;

public:
    ArrayUnionFind(int size) : size(size) {
        parent.resize(size);
        rank.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    void unite(int A, int B) override {
        int rootA = root(A);
        int rootB = root(B);
        if (rootA != rootB) {
            if (rank[rootA] < rank[rootB]) {
                uniteTo(rootA, rootB);
            } else {
                uniteTo(rootB, rootA);
                if (rank[rootA] == rank[rootB]) {
                    rank[rootA]++;
                }
            }
        }
    }

    bool same(int A, int B) override {
        return root(A) == root(B);
    }

    unordered_set<int> getSet(int id) override {
        unordered_set<int> set;
        for (int i = 0; i < size; ++i) {
            if (same(i, id)) {
                set.insert(i);
            }
        }
        return set;
    }

protected:
    void uniteTo(int source, int dest) {
        parent[source] = dest;
    }

    int root(int id) {
        if (parent[id] == id) {
            return id;
        }
        parent[id] = root(parent[id]);
        return parent[id];
    }
};

class SetUnionFind : public ArrayUnionFind {
private:
    unordered_map<int, unordered_set<int>> map;

public:
    SetUnionFind(int size) : ArrayUnionFind(size) {
        for (int i = 0; i < size; ++i) {
            map[i].insert(i);
        }
    }

    void unite(int A, int B) override {
        ArrayUnionFind::unite(A, B);
    }

    bool same(int A, int B) override {
        return ArrayUnionFind::same(A, B);
    }

    unordered_set<int> getSet(int id) override {
        return map[root(id)];
    }

protected:
    void uniteTo(int source, int dest) override {
        ArrayUnionFind::uniteTo(source, dest);
        map[dest].insert(map[source].begin(), map[source].end());
    }
};

class PrimeNumberUtils {
private:
    vector<bool> isPrimeArray;
    vector<int> primes;

public:
    PrimeNumberUtils(int limit) {
        if (limit > 10000000) {
            cerr << "上限の値が高すぎるため素数ユーティリティの初期化でTLEする可能性が大変高いです" << endl;
        }
        isPrimeArray.resize(limit);
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

    vector<int> getPrimeNumberList() {
        return primes;
    }

    bool isPrime(int n) {
        return isPrimeArray[n];
    }

private:
    bool isPrime(int n, const vector<int>& primes) {
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
    virtual void orOp(BitSet* bitset) = 0;
    virtual void andOp(BitSet* bitset) = 0;
};

class LongBit : public BitSet {
private:
    vector<long> bitArray;

public:
    LongBit(int size) {
        bitArray.resize((size + 63) / 64);
    }

    void set(int index, bool bit) override {
        int segment = index / 64;
        int inIndex = index % 64;
        if (bit) {
            bitArray[segment] |= 1L << inIndex;
        } else {
            bitArray[segment] &= ~(1L << inIndex);
        }
    }

    bool get(int index) override {
        int segment = index / 64;
        int inIndex = index % 64;
        return (bitArray[segment] & (1L << inIndex)) != 0L;
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
                bitArray[segment] = 0L;
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
                bitArray[segment] = 0L;
            }
        }
    }

    long getLong(int segment) {
        return bitArray[segment];
    }

    void orOp(BitSet* bitset) override {
        LongBit* other = dynamic_cast<LongBit*>(bitset);
        if (other != nullptr) {
            for (int segment = 0; segment < bitArray.size(); ++segment) {
                bitArray[segment] |= other->getLong(segment);
            }
        }
    }

    void andOp(BitSet* bitset) override {
        LongBit* other = dynamic_cast<LongBit*>(bitset);
        if (other != nullptr) {
            for (int segment = 0; segment < bitArray.size(); ++segment) {
                bitArray[segment] &= other->getLong(segment);
            }
        }
    }
};

int main() {
    Main main;
    main.solve();
    return 0;
}
// End of Code
