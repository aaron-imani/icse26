#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

class UnionFind {
public:
    std::vector<int> Parent;

    UnionFind(int n) { // Initialize by -1
        Parent.resize(n, -1);
    }

    int root(int A) { // In which tree is A?
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }

    int size(int A) { // Size of tree which is include A
        return -Parent[root(A)];
    }

    bool connect(int A, int B) { // Connect A and B
        A = root(A);
        B = root(B);
        if (A == B) return false;
        if (size(A) < size(B)) std::swap(A, B); // SWAP
        Parent[A] += Parent[B];
        Parent[B] = A;
        return true;
    }
};

class FastScanner {
private:
    std::istream& in;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        in.read(buffer, 1024);
        buflen = in.gcount();
        return buflen > 0;
    }

    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        return -1;
    }

    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

public:
    FastScanner(std::istream& in) : in(in) {}

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    std::string next() {
        if (!hasNext()) throw std::runtime_error("No more input");
        std::string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb += static_cast<char>(b);
            b = readByte();
        }
        return sb;
    }

    long long nextLong() {
        if (!hasNext()) throw std::runtime_error("No more input");
        long long n = 0;
        bool minus = false;
        int b = readByte();
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
        if (!hasNext()) throw std::runtime_error("No more input");
        return static_cast<char>(readByte());
    }
};

int main() {
    FastScanner scan(std::cin);
    std::string str = scan.next();
    std::cout << (str[2] == str[3] && str[4] == str[5] ? "Yes" : "No") << std::endl;
    return 0;
}
// End of Code
