#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <climits>
#include <cctype>
#include <fstream>

using namespace std;

class FastScanner {
private:
    ifstream in;
    char buffer[1024];
    int ptr, buflen;
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, 1024, stdin);
        if (buflen <= 0) return false;
        return true;
    }
    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }
public:
    FastScanner() : ptr(0), buflen(0) {}

    bool hasNext() {
        while (hasNextByte()) {
            int c = buffer[ptr];
            if (c == '\n') ptr++;
            else if (33 <= c && c <= 126) break;
            else ptr++;
        }
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No element");
        string s;
        int b = readByte();
        while (33 <= b && b <= 126) {
            s += (char)b;
            b = readByte();
        }
        return s;
    }

    long long nextLong() {
        if (!hasNext()) throw runtime_error("No element");
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
            } else if (b == -1 || !(33 <= b && b <= 126)) {
                break;
            } else {
                throw runtime_error("Invalid number");
            }
            b = readByte();
        }
        return minus ? -n : n;
    }

    int nextInt() {
        long long n = nextLong();
        if (n < INT_MIN || n > INT_MAX) throw runtime_error("Overflow");
        return static_cast<int>(n);
    }

    double nextDouble() {
        return stod(next());
    }
};

class Main {
public:
    static const long long INF;
    static const int MOD;
    static const int SIZE;
    static long long fac[SIZE];
    static long long inv[SIZE];
    static long long finv[SIZE];
    FastScanner sc;

    Main() {}

    void solve() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        unordered_map<int, int> map;

        for (int i = 0; i < m; ++i) {
            int s = sc.nextInt();
            int c = sc.nextInt();
            if (map.find(s) != map.end() && map[s] != c) {
                cout << -1 << endl;
                exit(0);
            }
            map[s] = c;
        }

        for (int i = 0; i < 1000; ++i) {
            string s = to_string(i);
            if (s.length() != n) continue;
            bool flag = true;
            for (int j = 0; j < n; ++j) {
                int pos = j + 1;
                int digit = s[j] - '0';
                if (map.find(pos) != map.end()) {
                    if (digit != map[pos]) {
                        flag = false;
                        break;
                    }
                } else {
                    if (digit != ess code truncated for brevity... // End of Code
