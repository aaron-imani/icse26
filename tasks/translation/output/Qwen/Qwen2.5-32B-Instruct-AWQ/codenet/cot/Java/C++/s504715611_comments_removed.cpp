#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>

class UnionFind {
private:
    std::vector<int> Parent;
public:
    UnionFind(int n) {
        Parent.resize(n, -1);
    }
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
        if (size(A) < size(B)) std::swap(A, B);
        Parent[A] += Parent[B];
        Parent[B] = A;
        return true;
    }
};

class FastScanner {
private:
    FILE *in = stdin;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, 1024, in);
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
    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }
    std::string next() {
        if (!hasNext()) throw std::runtime_error("No more input");
        std::string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb += b;
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
                throw std
