#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class UnionFind {
private:
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
        int aRoot = root(A), bRoot = root(B);
        if (aRoot == bRoot) return false;
        if (size(aRoot) < size(bRoot)) {
            swap(aRoot, bRoot);
        }
        Parent[aRoot] += Parent[bRoot];
        Parent[bRoot] = aRoot;
        return true;
    }
};

class FastScanner {
private:
    static const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    int ptr = 0;
    int buflen = 0;
public:
    bool hasNextByte() {
        if (ptr < buflen) return true;
        else {
            ptr = 0;
            buflen = read();
            return buflen > 0;
        }
    }
    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }
    bool hasNext() {
        while (hasNextByte() && !isPrintable(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    string next() {
        if (!hasNext()) throw runtime_error("No input");
        string s;
        int b = readByte();
        while (isPrintable(b)) {
            s += (char)b;
            b = readByte();
        }
        return s;
    }
    long long nextLong() {
        if (!hasNext()) throw runtime_error("No input");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') throw runtime_error("Invalid number");
        while (true) {
            if ('0' <= b && b <= '9') {
                n = n * 10 + (b - '0');
            } else if (b == -1 || !isPrintable(b)) {
                return minus ? -n : n;
            } else {
                throw runtime_error("Invalid number");
            }
            b = readByte();
        }
    }
    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Out of int range");
        return static_cast<int>(nl);
    }
private:
    int read() {
        return fread(buffer, 1, BUFFER_SIZE, stdin);
    }
    static bool isPrintable(int c) {
        return 33 <= c && c <= 126;
    }
};

int main() {
    FastScanner scan;
    string str = scan.next();
    if (str[2] == str[3] && str[4] == str[5]) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
// End of Code
