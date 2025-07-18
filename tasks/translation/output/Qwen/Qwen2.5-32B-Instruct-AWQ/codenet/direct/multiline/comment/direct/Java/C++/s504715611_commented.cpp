#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

class UnionFind {
private:
    std::vector<int> parent;

public:
    UnionFind(int n) : parent(n, -1) {}

    int root(int A) {
        if (parent[A] < 0) return A;
        return parent[A] = root(parent[A]);
    }

    int size(int A) {
        return -parent[root(A)];
    }

    bool connect(int A, int B) {
        A = root(A);
        B = root(B);
        if (A == B) return false;
        if (size(A) < size(B)) std::swap(A, B);
        parent[A] += parent[B];
        parent[B] = A;
        return true;
    }
};

class FastScanner {
private:
    std::istream& in;
    std::vector<char> buffer;
    size_t ptr = 0;
    size_t buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        in.read(&buffer[0], buffer.size());
        buflen = in.gcount();
        return buflen > 0;
    }

    char readByte() {
        if (hasNextByte()) return buffer[ptr++];
        return -1;
    }

    static bool isPrintableChar(char c) {
        return 33 <= c && c <= 126;
    }

public:
    FastScanner(std::istream& in) : in(in), buffer(1024) {}

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    std::string next() {
        if (!hasNext()) throw std::runtime_error("No more input");
        std::string result;
        char b = readByte();
        while (isPrintableChar(b)) {
            result.push_back(b);
            b = readByte();
        }
        return result;
    }

    long long nextLong() {
        if (!hasNext()) throw std::runtime_error("No more input");
        long long n = 0;
        bool minus = false;
        char b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) throw std::runtime_error("Invalid number format");
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw std::runtime_error("Invalid number format");
            }
            b = readByte();
        }
    }

    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw std::runtime_error("Number out of range");
        return static_cast<int>(nl);
    }

    double nextDouble() {
        return std::stod(next());
    }

    char nextChar() {
        char c;
        in >> c;
        return c;
    }
};

int main() {
    FastScanner scan(std::cin);
    std::string str = scan.next();
    std::cout << (str[2] == str[3] && str[4] == str[5] ? "Yes" : "No") << std::endl;
    // End of Code
}
