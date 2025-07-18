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
#include <functional>

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
    istream &in;
    string buffer;
    vector<string> tokens;
    size_t tokenIndex;

public:
    FastScanner(istream &in) : in(in), tokenIndex(0) {}

    bool hasNext() {
        while (tokenIndex == tokens.size()) {
            if (!getline(in, buffer)) return false;
            tokens.clear();
            stringstream ss(buffer);
            string token;
            while (ss >> token) tokens.push_back(token);
            tokenIndex = 0;
        }
        return true;
    }

    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        return tokens[tokenIndex++];
    }

    int nextInt() {
        return stoi(next());
    }

    long long nextLong() {
        return stoll(next());
    }

    double nextDouble() {
        return stod(next());
    }
};

int main() {
    FastScanner scan(cin);
    string str = scan.next();
    cout << (str[2] == str[3] && str[4] == str[5] ? "Yes" : "No") << endl;
    return 0;
}

// End of Code
