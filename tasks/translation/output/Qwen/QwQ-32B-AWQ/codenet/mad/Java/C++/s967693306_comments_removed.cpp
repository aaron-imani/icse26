#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class FastScanner {
private:
    istream& in;
    streambuf* buf;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = in.readsome(buffer, 1024);
        return buflen > 0;
    }

    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }

public:
    FastScanner() : in(cin), buf(cin.rdbuf()) {}

    bool hasNext() {
        while (hasNextByte()) {
            char c = buffer[ptr];
            if (c >= 33 && c <= 126) break;
            ptr++;
        }
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No element");
        string s;
        int b = readByte();
        while (b >= 33 && b <= 126) {
            s += static_cast<char>(b);
            b = readByte();
        }
        return s;
    }

    int nextInt() {
        long long n = nextLong();
        if (n < INT_MIN || n > INT_MAX) throw runtime_error("Overflow");
        return static_cast<int>(n);
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
        if (b < '0' || b > '9') throw invalid_argument("Not a number");
        while (true) {
            if (b >= '0' && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !(b >= 33 && b <= 126)) {
                break;
            } else {
                throw invalid_argument("Invalid number format");
            }
            b = readByte();
        }
        return minus ? -n : n;
    }
};

struct Main {
    FastScanner sc;
    const long long INF = LLONG_MAX / 2;
    const int MOD = 1e9 + 7;
    const int SIZE = 1e6;
    long long fac[SIZE];
    long long inv[SIZE];
    long long finv[SIZE];

    void solve() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        unordered_map<int, int> map;

        for (int i = 0; i < m; i++) {
            int s = sc.nextInt();
            int c = sc.nextInt();
            if (map.find(s) != map.end()) {
                if (map[s] != c) {
                    cout << -1 << endl;
                    exit(EXIT_SUCCESS);
                }
            }
            map[s] = c;
        }

        for (int i = 0; i < 1000; i++) {
            string s = to_string(i);
            if (s.length() < n) continue;

            bool flag = true;
            for (int j = 0; j < n; j++) {
                int pos = j + 1;
                int digit = s[j] - '0';
                if (map.find(pos) != map.end()) {
                    if (map[pos] != digit) {
                        flag = false;
                        break;
                    }
                } else {
                    if (digit != 梅 且 j != 0 || (digit == 1 && j == 0)) {
                        continue;
                    } else if (digit != 0) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag && s.length() == n) {
                cout << s << endl;
                exit(EXIT_SUCCESS);
            }
        }

        cout << -1 << endl;
    }

    // Other utility functions remain unchanged...
};

int main() {
    Main mainObj;
    mainObj.solve();
    return 0;
}
// End of Code
