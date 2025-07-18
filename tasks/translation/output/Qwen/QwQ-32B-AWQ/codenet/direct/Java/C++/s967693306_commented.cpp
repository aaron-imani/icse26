#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

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
            buflen = fread(buffer, 1, BUFFER_SIZE, stdin);
            return buflen > 0;
        }
    }

    int readByte() {
        if (hasNextByte()) {
            return static_cast<unsigned char>(buffer[ptr++]);
        } else {
            return -1;
        }
    }

    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    bool hasNext() {
        while (hasNextByte()) {
            int c = static_cast<unsigned char>(buffer[ptr]);
            if (isPrintableChar(c)) return true;
            ptr++;
        }
        return false;
    }

    string next() {
        if (!hasNext()) throw runtime_error("No token");
        string ret;
        int b = readByte();
        while (isPrintableChar(b)) {
            ret += static_cast<char>(b);
            b = readByte();
        }
        return ret;
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
        if (b < '0' || b > '9') throw runtime_error("Invalid number format");
        while (true) {
            if ('0' <= b && b <= '9') {
                n = n * 10 + (b - '0');
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
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Out of int range");
        return static_cast<int>(nl);
    }
};

class Main {
public:
    void solve() {
        FastScanner sc;
        int n = sc.nextInt();
        int m = sc.nextInt();
        unordered_map<int, int> map;

        for (int i = 0; i < m; i++) {
            int s = sc.nextInt();
            int c = sc.nextInt();
            if (map.count(s)) {
                if (map[s] != c) {
                    cout << -1 << endl;
                    exit(0);
                }
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
                    if (map[pos] != digit) {
                        flag = false;
                        break;
                    }
                } else {
                    if (j == 0) {
                        if (digit != 1) {
                            flag = false;
                            break;
                        }
                    } else {
                        if (digit != 0) {
                            flag = false;
                            break;
                        }
                    }
                }
            }

            if (flag) {
                cout << s << endl;
                exit(0);
            }
        }

        cout << -1 << endl;
    }
};

int main() {
    Main obj;
    obj.solve();
    return 0;
}
// End of Code
