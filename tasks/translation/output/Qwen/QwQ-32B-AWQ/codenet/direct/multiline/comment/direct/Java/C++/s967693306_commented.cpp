#include <iostream>
#include <string>
#include <map>
#include <array>
using namespace std;

const long INF = LONG_MAX / 2;
const int MOD = 1000000007;
const int SIZE = 1000000;

long fac[SIZE];
long inv[SIZE];
long finv[SIZE];

class FastScanner {
private:
    static const int BUFFER_SIZE = 1024;
    array<char, BUFFER_SIZE> buffer;
    int ptr = 0;
    int buflen = 0;

public:
    bool hasNextByte() {
        if (ptr < buflen) return true;
        else {
            ptr = 0;
            buflen = fread(buffer.data(), sizeof(char), BUFFER_SIZE, stdin);
            return buflen > 0;
        }
    }

    int readByte() {
        if (hasNextByte()) return static_cast<unsigned char>(buffer[ptr++]);
        else return -1;
    }

    bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string s;
        int b = readByte();
        while (isPrintableChar(b)) {
            s += static_cast<char>(b);
            b = readByte();
        }
        return s;
    }

    long long nextLong() {
        if (!hasNext()) throw runtime_error("No more input");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') throw invalid_argument("Invalid number");
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw invalid_argument("Invalid number");
            }
            b = readByte();
        }
    }

    int nextInt() {
        long long n = nextLong();
        if (n < INT_MIN || n > INT_MAX) throw out_of_range("Integer overflow");
        return static_cast<int>(n);
    }

    double nextDouble() {
        return stod(next());
    }
};

void solve() {
    FastScanner sc;
    int n = sc.nextInt();
    int m = sc.nextInt();
    map<int, int> digit_constraints;

    for (int i = 0; i < m; ++i) {
        int s = sc.nextInt();
        int c = sc.nextInt();
        if (digit_constraints.count(s)) {
            if (digit_constraints[s] != c) {
                cout << -1 << endl;
                return;
            }
        }
        digit_constraints[s] = c;
    }

    for (int i = 0; i < 1000; ++i) {
        string s = to_string(i);
        if (s.length() != n) continue;

        bool flag = true;
        for (size_t j = 0; j < n; ++j) {
            int pos = j + 1;
            int digit_val = s[j] - '0';
            if (digit_constraints.count(pos)) {
                if (digit_val != digit_constraints[pos]) {
                    flag = false;
                    break;
                }
            } else {
                if (j == 0) {
                    if (digit_val != 0 && digit_val != 1) {
                        flag = false;
                        break;
                    }
                } else {
                    if (digit_val != 0) {
                        flag = false;
                        break;
                    }
                }
            }
        }

        if (flag) {
            cout << s << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    solve();
    return 0;
}
// End of Code
