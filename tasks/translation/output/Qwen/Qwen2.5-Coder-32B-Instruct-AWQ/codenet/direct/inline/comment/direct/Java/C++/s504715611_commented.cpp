#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <random>
#include <cstdio>

using namespace std;

class UnionFind {
    vector<int> Parent;
public:
    UnionFind(int n) : Parent(n, -1) {}
    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }
    int size(int A) {
        return -Parent[root(A)];
    }
    bool connect(int A, int B) {
        A = root(A);
        B = root(B);
        if (A == B) return false;
        if (size(A) < size(B)) swap(A, B);
        Parent[A] += Parent[B];
        Parent[B] = A;
        return true;
    }
};

class FastScanner {
private:
    FILE *fp;
    char buffer[1024];
    int ptr, buflen;
public:
    FastScanner() : fp(stdin), ptr(0), buflen(0) {}
    ~FastScanner() { fclose(fp); }
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, sizeof(buffer), fp);
        return buflen > 0;
    }
    int readByte() { return hasNextByte() ? buffer[ptr++] : -1; }
    bool hasNext() {
        while (hasNextByte() && !isprint(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string s;
        int b = readByte();
        while (isprint(b)) {
            s.push_back(b);
            b = readByte();
        }
        return s;
    }
    long long nextLong() {
        if (!hasNext()) throw runtime_error("No more input");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) throw runtime_error("Invalid number format");
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isprint(b)) {
                return minus ? -n : n;
            } else {
                throw runtime_error("Invalid number format");
            }
            b = readByte();
        }
    }
    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Number out of int range");
        return static_cast<int>(nl);
    }
    double nextDouble() {
        return stod(next());
    }
};

int main() {
    FastScanner scan;
    string str = scan.next();
    cout << (str[2] == str[3] && str[4] == str[5] ? "Yes" : "No") << endl;
    return 0;
}
// End of Code
