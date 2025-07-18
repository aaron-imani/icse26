#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <random>
#include <numeric>

using namespace std;

class UnionFind {
public:
    vector<int> Parent;
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
    istream& in;
    string buffer;
    size_t pos;

public:
    FastScanner(istream& in) : in(in), pos(0) {}

    bool hasNextByte() {
        if (pos < buffer.size()) return true;
        getline(in, buffer);
        pos = 0;
        return !buffer.empty();
    }

    int readByte() {
        if (!hasNextByte()) return -1;
        return buffer[pos++];
    }

    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[pos])) pos++;
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No more elements in input");
        string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb += b;
            b = readByte();
        }
        return sb;
    }

    long long nextLong() {
        if (!hasNext()) throw runtime_error("No more elements in input");
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
            } else if (b == -1 || !isPrintableChar(b)) {
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

    char nextchar() {
        if (!hasNextByte()) throw runtime_error("No more elements in input");
        return buffer[pos++];
    }
};

int main() {
    FastScanner scan(cin);
    string str = scan.next();
    cout << (str[2] == str[3] && str[4] == str[5] ? "Yes" : "No") << endl;
    return 0;
}

// End of Code
