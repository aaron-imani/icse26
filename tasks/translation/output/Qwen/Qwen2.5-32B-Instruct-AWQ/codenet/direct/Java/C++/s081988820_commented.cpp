#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstdint>

using namespace std;

class Main {
public:
    void solve() {
        int H, W;
        cin >> H >> W;
        vector<vector<int>> c(10, vector<int>(10));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cin >> c[i][j];
            }
        }
        vector<int> min(10);
        for (int i = 0; i < 10; i++) {
            min[i] = c[i][1];
        }
        for (int tc = 0; tc < 10; tc++) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    min[i] = min(min[i], c[i][j] + min[j]);
                }
            }
        }
        int ans = 0;
        for (int h = 1; h <= H; h++) {
            for (int w = 1; w <= W; w++) {
                int A;
                cin >> A;
                if (A >= 0) {
                    ans += min[A];
                }
            }
        }
        cout << ans << endl;
    }
};

class Scanner {
private:
    istream& in;
    vector<char> buffer;
    int index;
    int length;

public:
    Scanner(istream& in) : in(in), buffer(1024), index(0), length(0) {}

    bool isPrintableChar(int c) {
        return '!' <= c && c <= '~';
    }

    bool isDigit(int c) {
        return '0' <= c && c <= '9';
    }

    bool hasNextByte() {
        if (index < length) {
            return true;
        } else {
            in.read(buffer.data(), buffer.size());
            length = in.gcount();
            index = 0;
            return length > 0;
        }
    }

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[index])) {
            index++;
        }
        return hasNextByte();
    }

    int readByte() {
        return hasNextByte() ? buffer[index++] : -1;
    }

    string next() {
        if (!hasNext()) {
            throw runtime_error("no input");
        }
        string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.push_back(b);
            b = readByte();
        }
        return sb;
    }

    long long nextLong() {
        if (!hasNext()) {
            throw runtime_error("no input");
        }
        long long value = 0LL;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        while (isPrintableChar(b)) {
            if (isDigit(b)) {
                value = value * 10 + (b - '0');
            }
            b = readByte();
        }
        return minus ? -value : value;
    }

    int nextInt() {
        return static_cast<int>(nextLong());
    }

    double nextDouble() {
        return stod(next());
    }
};

interface CombCalculator {
    long comb(int n, int m);
};

interface MobiusFunction {
    int get(int n);
};

class SieveMobiusFunction : public MobiusFunction {
private:
    int size;
    vector<int> mobiusFunctionValues;

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

class FactorialTableCombCalculator : public CombCalculator {
private:
    int size;
    vector<long long> factorialTable;
    vector<long long> inverseFactorialTable;
    long long mod;

public:
    FactorialTableCombCalculator(int size, long long mod) : size(size), factorialTable(size + 1), inverseFactorialTable(size + 1), mod(mod) {
        factorialTable[0] = 1LL;
        for (int i = 1; i <= size; i++) {
            factorialTable[i] = (factorialTable[i - 1] * i) % mod;
        }
        inverseFactorialTable[size] = inverse(factorialTable[size], mod);
        for (int i = size - 1; i >= 0; i--) {
            inverseFactorialTable[i] = (inverseFactorialTable[i + 1] * (i + 1)) % mod;
        }
    }

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

    long long comb(int n, int m) override {
        if (n > size) {
            throw runtime_error("n is greater than size.");
        }
        if (n < 0 || m < 0 || n < m) {
            return 0LL;
        }
        return (((factorialTable[n] * inverseFactorialTable[m]) % mod) * inverseFactorialTable[n - m]) % mod;
    }
};

class TableCombCalculator : public CombCalculator {
private:
    vector<vector<long long>> table;
    int size;

public:
    TableCombCalculator(int size, long long mod) : size(size), table(size + 1) {
        table[0] = vector<long long>(1, 1LL);
        for (int n = 1; n <= size; n++) {
            table[n] = vector<long long>(n + 1);
            table[n][0] = 1LL;
            for (int m = 1; m < n; m++) {
                table[n][m] = (table[n - 1][m - 1] + table[n - 1][m]) % mod;
            }
            table[n][n] = 1LL;
        }
    }

    long long comb(int n, int m) override {
        if (n > size) {
            throw runtime_error("n is greater than size.");
        }
        if (n < 0 || m < 0 || n < m) {
            return 0LL;
        }
        return table[n][m];
    }
};

interface Graph {
    void link(int from, int to, long cost);
    optional<long> getCost(int from, int to);
    int getVertexNum();
};

interface FlowResolver {
    long maxFlow(int from, int to);
};

class ArrayGraph : public Graph {
private:
    vector<vector<optional<long>>> costArray;
    int vertexNum;

public:
    ArrayGraph(int n) : costArray(n, vector<optional<long>>(n)), vertexNum(n) {}

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
            currentFlow = flow(from, to, numeric_limits<long>::max() / 3, vector<bool>(graph->getVertexNum()));
            sum += currentFlow;
        } while (currentFlow > 0);
        return sum;
    }

private:
    long flow(int from, int to, long currentFlow, vector<bool>& passed) {
        passed[from] = true;
        if (from == to) {
            return currentFlow;
        }
        for (int id = 0; id < graph->getVertexNum(); id++) {
            if (passed[id]) {
                continue;
            }
            optional<long> cost = graph->getCost(from, id);
            if (cost.has_value() && cost.value() > 0) {
                long nextFlow = currentFlow < cost.value() ? currentFlow : cost.value();
                long returnFlow = flow(id, to, nextFlow, passed);
                if (returnFlow > 0) {
                    graph->link(from, id, cost.value() - returnFlow);
                    graph->link(id, from, graph->getCost(id, from).value_or(0L) + returnFlow);
                    return returnFlow;
                }
            }
        }
        return 0L;
    }
};

class BinaryIndexedTree {
private:
    vector<long long> array;

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
};

class BinaryIndexedTree2D {
private:
    vector<vector<long long>> array;

public:
    BinaryIndexedTree2D(int size1, int size2) : array(size1 + 1, vector<long long>(size2 + 1)) {}

    void add(int index1, int index2, long long value) {
        for (int i1 = index1; i1 < array.size(); i1 += (i1 & -i1)) {
            for (int i2 = index2; i2 < array[0].size(); i2 += (i2 & -i2)) {
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
};

interface UnionFind {
    void union(int A, int B);
    bool judge(int A, int B);
    set<int> getSet(int id);
};

class SetUnionFind : public ArrayUnionFind {
private:
    unordered_map<int, set<int>> map;

public:
    SetUnionFind(int size) : ArrayUnionFind(size) {
        for (int i = 0; i < size; i++) {
            map[i].insert(i);
        }
    }

    void unionTo(int source, int dest) override {
        ArrayUnionFind::unionTo(source, dest);
        map[dest].insert(map[source].begin(), map[source].end());
    }

    set<int> getSet(int id) override {
        return map[root(id)];
    }
};

class ArrayUnionFind : public UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int size;

public:
    ArrayUnionFind(int size) : size(size), parent(size), rank(size) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    void union(int A, int B) override {
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

    set<int> getSet(int id) override {
        set<int> set;
        for (int i = 0; i < size; i++) {
            if (judge(i, id)) {
                set.insert(i);
            }
        }
        return set;
    }

    int root(int id) {
        if (parent[id] == id) {
            return id;
        }
        parent[id] = root(parent[id]);
        return parent[id];
    }

protected:
    void unionTo(int source, int dest) {
        parent[source] = dest;
    }
};

class PrimeNumberUtils {
private:
    vector<bool> isPrimeArray;
    vector<int> primes;

public:
    PrimeNumberUtils(int limit) : isPrimeArray(limit, false), primes() {
        if (limit > 10000000) {
            cerr << "上限の値が高すぎるため素数ユーティリティの初期化でTLEする可能性が大変高いです" << endl;
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

interface BitSet {
    void set(int index, bool bit);
    bool get(int index);
    void shiftRight(int num);
    void shiftLeft(int num);
    void or(BitSet* bitset);
    void and(BitSet* bitset);
};

class LongBit : public BitSet {
private:
    vector<long long> bitArray;

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
        for (int segment = 0; segment < bitArray.size(); segment++) {
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
        for (int segment = bitArray.size() - 1; segment >= 0; segment--) {
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

    long long getLong(int segment) {
        return bitArray[segment];
    }

    void or(BitSet* bitset) override {
        if (dynamic_cast<LongBit*>(bitset) == nullptr) {
            return;
        }
        LongBit* longBit = dynamic_cast<LongBit*>(bitset);
        for (int segment = 0; segment < bitArray.size(); segment++) {
            bitArray[segment] |= longBit->getLong(segment);
        }
    }

    void and(BitSet* bitset) override {
        if (dynamic_cast<LongBit*>(bitset) == nullptr) {
            return;
        }
        LongBit* longBit = dynamic_cast<LongBit*>(bitset);
        for (int segment = 0; segment < bitArray.size(); segment++) {
            bitArray[segment] &= longBit->getLong(segment);
        }
    }
};

int main() {
    Main main;
    main.solve();
    return 0;
}

// End of Code
