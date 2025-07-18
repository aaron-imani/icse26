#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdio>

using namespace std;

class FastScanner {
private:
    static const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    int ptr = 0;
    int buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, BUFFER_SIZE, stdin);
        return buflen > 0;
    }

    int readByte() {
        if (!hasNextByte()) return -1;
        return buffer[ptr++];
    }

public:
    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No element");
        string s;
        int b = readByte();
        while (isPrintableChar(b)) {
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
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw runtime_error("Invalid number");
            }
            b = readByte();
        }
    }

    int nextInt() {
        long long n = nextLong();
        if (n < INT_MIN || n > INT_MAX) throw runtime_error("Overflow");
        return (int)n;
    }

    double nextDouble() {
        return stod(next());
    }

private:
    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
};

void solve(FastScanner& sc) {
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
        if (s.size() < n) continue;
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            int pos = j + 1;
            int digit = s[j] - '0';
            if (map.count(pos)) {
                if (map[pos] != digit) {
                    flag = false;
                    break;
                }
            } else {
                if (digit != 0) {
                    if (j == 0 && digit == 1) continue;
                    else {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag && s.size() == n) {
            cout << s << endl;
            exit(0);
        }
    }

    cout << -1 << endl;
}

int main() {
    FastScanner sc;
    solve(sc);
    return 0;
}
// End of Code
