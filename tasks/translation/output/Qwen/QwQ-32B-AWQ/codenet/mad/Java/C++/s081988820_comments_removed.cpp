#include <iostream>
#include <vector>
using namespace std;

struct Main {
    void solve();
    class Scanner {
    private:
        istream& in;
        char buffer[1024];
        int index;
        int length;

    public:
        Scanner(istream& in) : in(in), index(0), length(0) {}
        
        bool isPrintableChar(int c) const {
            return c >= '!' && c <= '~';
        }
        
        bool isDigit(int c) const {
            return c >= '0' && c <= '9';
        }
        
        bool hasNextByte() {
            if (index < length) return true;
            in.read(buffer, sizeof(buffer));
            length = in.gcount();
            index = 0;
            return length > 0;
        }
        
        bool hasNext() {
            while (hasNextByte() && !isPrintableChar(buffer[index])) {
                index++;
            }
            return hasNextByte();
        }
        
        int readByte() {
            if (!hasNextByte()) return -1;
            return static_cast<int>(buffer[index++]);
        }
        
        string next() {
            if (!hasNext()) throw runtime_error("no input");
            string sb;
            int b = readByte();
            while (isPrintableChar(b)) {
                sb += static_cast<char>(b);
                b = readByte();
            }
            return sb;
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
    };

    void solve() {
        Scanner sc(cin);
        int H = sc.nextInt();
        int W = sc.nextInt();
        int c[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i][j] = sc.nextInt();
            }
        }
        int min[10];
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
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                int A = sc.nextInt();
                if (A >= 0 && A < 10) {
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
