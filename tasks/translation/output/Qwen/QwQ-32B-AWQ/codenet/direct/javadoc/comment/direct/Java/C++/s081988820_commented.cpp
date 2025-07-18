#include <iostream>
#include <array>
using namespace std;

class Scanner {
private:
    istream& in;
    array<unsigned char, 1024> buffer;
    int index;
    int length;
public:
    Scanner(istream& in) : in(in), index(0), length(0) {}
    bool isPrintableChar(int c) { return '!' <= c && c <= '~'; }
    bool isDigit(int c) { return '0' <= c && c <= '9'; }
    bool hasNextByte() {
        if (index < length) return true;
        in.read(reinterpret_cast<char*>(buffer.data()), buffer.size());
        length = in.gcount();
        index = 0;
        return length > 0;
    }
    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[index])) {
            ++index;
        }
        return hasNextByte();
    }
    int readByte() {
        if (hasNextByte()) return buffer[index++];
        return -1;
    }
    string next() {
        if (!hasNext()) throw runtime_error("no input");
        string s;
        int b = readByte();
        while (isPrintableChar(b)) {
            s += static_cast<char>(b);
            b = readByte();
        }
        return s;
    }
    long long nextLong() {
        if (!hasNext()) throw runtime_error("no input");
        long long value = 0;
        bool minus = false;
        int b = readByte();
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
    int nextInt() { return static_cast<int>(nextLong()); }
    double nextDouble() { return stod(next()); }
};

class Main {
public:
    void solve() {
        Scanner sc(cin);
        int H = sc.nextInt();
        int W = sc.nextInt();
        array<array<int, 10>, 10> c;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                c[i][j] = sc.nextInt();
            }
        }
        int min[10];
        for (int i = 0; i < 10; ++i) {
            min[i] = c[i][1];
        }
        for (int tc = 0; tc < 10; ++tc) {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (c[i][j] + min[j] < min[i]) {
                        min[i] = c[i][j] + min[j];
                    }
                }
            }
        }
        int ans = 0;
        for (int h = 1; h <= H; ++h) {
            for (int w = 1; w <= W; ++w) {
                int A = sc.nextInt();
                if (A >= 0) ans += min[A];
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
