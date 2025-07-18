#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>

using namespace std;

class Scanner {
private:
    istream& in;
    vector<char> buffer;
    size_t index = 0;
    size_t length = 0;

public:
    Scanner(istream& in) : in(in) {}

    bool isPrintableChar(char c) {
        return '!' <= c && c <= '~';
    }

    bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }

    bool hasNextByte() {
        if (index < length) {
            return true;
        } else {
            buffer.resize(1024);
            in.read(buffer.data(), 1024);
            length = in.gcount();
            index = 0;
            return length > 0;
        }
    }

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[index])) {
            index++;
        }
        return hasNextByte();
    }

    char readByte() {
        return hasNextByte() ? buffer[index++] : -1;
    }

    string next() {
        if (!hasNext()) {
            throw runtime_error("no input");
        }
        string sb;
        char b = readByte();
        while (isPrintableChar(b)) {
            sb += b;
            b = readByte();
        }
        return sb;
    }

    long long nextLong() {
        if (!hasNext()) {
            throw runtime_error("no input");
        }
        long long value = 0;
        bool minus = false;
        char b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        while (isPrintableChar(b)) {
            if (isDigit(b)) {
                value = value * 10 + (b - '0');
            }
            b = readByte();
        }
        return minus ? -value : value;
    }

    int nextInt() {
        return static_cast<int>(nextLong());
    }

    double nextDouble() {
        return stod(next());
    }
};

class Main {
public:
    void solve() {
        Scanner sc(cin);
        int H = sc.nextInt();
        int W = sc.nextInt();
        vector<vector<int>> c(10, vector<int>(10));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i][j] = sc.nextInt();
            }
        }
        vector<int> min(10);
        for (int i = 0; i < 10; i++) {
            min[i] = c[i][1];
        }
        for (int tc = 0; tc < 10; tc++) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    min[i] = min(min[i], c[i][j] + min[j]);
                }
            }
        }
        int ans = 0;
        for (int h = 1; h <= H; h++) {
            for (int w = 1; w <= W; w++) {
                int A = sc.nextInt();
                if (A >= 0) {
                    ans += min[A];
                }
            }
        }
        cout << ans << endl;
    }
};

int main() {
    Main main;
    main.solve();
    return 0;
}

// End of Code
