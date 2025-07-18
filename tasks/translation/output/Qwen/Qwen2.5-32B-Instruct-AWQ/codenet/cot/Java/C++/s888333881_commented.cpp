#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstdio>

using namespace std;

class Graph0n {
private:
    vector<Node0n> dt;
public:
    Graph0n(int sz) { for(int i=0; i<sz; i++) { Node0n node1; dt.push_back(node1); } }
    void add(int vn, int val) { dt[vn].add(val); }
    void add2(int vn, int val) { dt[vn].add(val); dt[val].add(vn); }
    int get(int vn, int index) { return dt[vn].get(index); }
    vector<int> get(int vn) { return dt[vn].getAll(); }
    int sizeOf(int vn) { return dt[vn].size(); }
    void clear() { for(int i=0; i<dt.size(); i++) { dt[i].clear(); } }
};

class Node0n {
private:
    vector<int> next_vs;
public:
    void add(int val) { next_vs.push_back(val); }
    int get(int ad) { return next_vs[ad]; }
    vector<int> getAll() { return next_vs; }
    int size() { return next_vs.size(); }
    void clear() { next_vs.clear(); }
};

class Edge {
public:
    int from=-1, v2=-1; long weight;
    Edge(int vn, long w) { v2 = vn; weight = w; }
    Edge(int cm, int vn, long w) { from = cm; v2 = vn; weight = w; }
};

class Edge2 {
public:
    int v2; long cost1, cost2;
    Edge2(int vn, long w1, long w2) { v2 = vn; cost1 = w1; cost2 = w2; }
};

class Comparator_Edge : public function<int(Edge, Edge)> {
public:
    int operator()(Edge a, Edge b) {
        if(a.weight > b.weight) return -1;
        else if(a.weight < b.weight) return 1;
        else return b.v2 - a.v2;
    }
};

class V2Comp : public function<int(Edge, Edge)> {
public:
    int operator()(Edge a, Edge b) {
        if(a.v2 > b.v2) return -1;
        else if(a.v2 < b.v2) return 1;
        else if(a.weight > b.weight) return -1;
        else if(a.weight < b.weight) return 1;
        else return 0;
    }
};

class antiV2 : public function<int(Edge, Edge)> {
public:
    int operator()(Edge a, Edge b) {
        if(a.v2 > b.v2) return 1;
        else if(a.v2 < b.v2) return -1;
        else if(a.weight > b.weight) return -1;
        else if(a.weight < b.weight) return 1;
        else return 0;
    }
};

class Vector {
public:
    int x, y;
    Vector(int sx, int sy) { x = sx; y = sy; }
};

class FastScanner {
private:
    FILE* in = stdin;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, 1024, in);
        return buflen > 0;
    }
    int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1; }
    bool isPrintableChar(int c) { return 33 <= c && c <= 126; }
public:
    bool hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte(); }
    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string sb;
        int b = readByte();
        while(isPrintableChar(b)) {
            sb += b;
            b = readByte();
        }
        return sb;
    }
    long long nexL() {
        if (!hasNext()) throw runtime_error("No more input");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) throw runtime_error("Invalid number format");
        while(true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if(b == -1 || !isPrintableChar(b) || b == ':') {
                return minus ? -n : n;
            } else {
                throw runtime_error("Invalid number format");
            }
            b = readByte();
        }
    }
    int nexI() {
        long long nl = nexL();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Number out of range");
        return (int) nl;
    }
};

int main() {
    FastScanner sc;
    int n = sc.nexI();
    string s = sc.next();
    vector<bool> flaged(n, false);
    
    long long pop1st = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }
    
    long long surp1 = 0;
    for(int i=0; i<n; i++) {
        surp1 *= 2;
        if(flaged[i]) surp1++;
        surp1 %= (pop1st + 1);
    }
    
    long long surp9 = 0;
    if(pop1st > 1) {
        for(int i=0; i<n; i++) {
            surp9 *= 2;
            if(flaged[i]) surp9++;
            surp9 %= (pop1st - 1);
        }
    }
    
    for(int p=0; p<n; p++) {
        if(flaged[p]) {
            if(pop1st == 1) {
                cout << 0 << endl;
                continue;
            }
            long long dw = surp9;
            long long dif = pow(2, n-p-1, pop1st-1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);
            
            int ans = 1;
            while(dw != 0) {
                if(dw < 0) cout << 1/0 << endl;
                int count = __builtin_popcountll(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        } else {
            long long dw = surp1;
            long long dif = pow(2, n-p-1, pop1st+1);
            dw += dif;
            dw %= (pop1st + 1);
            
            int ans = 1;
            while(dw != 0) {
                if(dw < 0) cout << 1/0 << endl;
                int count = __builtin_popcountll(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}

// End of Code
