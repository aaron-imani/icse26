#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class FastScanner {
private:
    istream& in;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;
    static bool isPrintableChar(int c) {
        return c >= 33 && c <= 126;
    }
public:
    FastScanner(istream& in_ = cin) : in(in_) {}
    bool hasNextByte() {
        if (ptr < buflen) return true;
        else {
            ptr = 0;
            buflen = in.read(buffer, 1024).gcount();
            return buflen > 0;
        }
    }
    int readByte() {
        if (hasNextByte()) {
            int b = buffer[ptr++];
            return b;
        }
        else return -1;
    }
    bool hasNext() {
        while (hasNextByte()) {
            int c = buffer[ptr];
            if (isPrintableChar(c)) return true;
            ptr++;
        }
        return false;
    }
    string next() {
        if (!hasNext()) throw runtime_error("No next element");
        string s;
        int b = readByte();
        while (isPrintableChar(b)) {
            s.push_back(static_cast<char>(b));
            b = readByte();
        }
        return s;
    }
    long long nextLong() {
        if (!hasNext()) throw runtime_error("No next element");
        long long n = 越 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') throw invalid_argument("Invalid number");
        while (true) {
            if ('0' <= b && b <= '9') {
                n = n * 10 + (b - '0');
            }
            else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            }
            else {
                throw invalid_argument("Invalid number");
            }
            b = readByte();
        }
    }
    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw out_of_range("Integer overflow");
        return static_cast<int>(nl);
    }
};

class Main {
public:
    FastScanner sc;
    void solve() {
        int n = sc.nextInt();
        int m = sc.nextInt();
        unordered_map<int, int> map;
        for (int i = 0; i < m; ++i) {
            int s = sc.nextInt();
            int c = sc.nextInt();
            if (map.find(s) != map.end() && map[s] != c) {
                cout << "-1\n";
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
                if (map.find(pos) != map.end()) {
                    if (digit != map[pos]) {
                        flag = false;
                        break;
                    }
                }
                else {
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
                cout << s << '\n';
                exit(0);
            }
        }
        cout << "-1\n";
    }
};

int main() {
    Main mainObj;
    mainObj.solve();
    return 0;
}
// End of Code
