#include <iostream>
#include <istream>
#include <ostream>
#include <stdexcept>

class MyInput {
private:
    static const int buffer_size = 1024 * 8;
    char buffer[buffer_size];
    int pos = 0;
    int readLen = 0;
    std::istream& inStream;

    int getChar() {
        if (pos >= readLen) {
            pos = 0;
            inStream.read(buffer, buffer_size);
            readLen = inStream.gcount();
            if (readLen <= 0) {
                throw std::runtime_error("EOF encountered");
            }
        }
        return buffer[pos++];
    }

    static bool isSpace(int c) {
        return c == ' ' || c == '\r' || c == '\n' || c == '\t';
    }

public:
    MyInput(std::istream& is) : inStream(is) {}

    int nextInt() {
        int c = getChar();
        while (isSpace(c)) c = getChar();
        bool isNegative = false;
        if (c == '-') {
            isNegative = true;
            c = getChar();
        }
        int ret = 0;
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + (c - '0');
            c = getChar();
        }
        return isNegative ? -ret : ret;
    }
};

class Solver {
public:
    void solve(int testNumber, MyInput& in, std::ostream& out) {
        int ans = 0;
        int K = in.nextInt();
        int S = in.nextInt();
        int wk;
        for (int x = 0; x <= K; ++x) {
            for (int y = 0; y <= K; ++y) {
                wk = S - x - y;
                if (wk >= 0 && wk <= K) {
                    ++ans;
                }
            }
        }
        out << ans << '\n';
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    MyInput in(std::cin);
    std::ostream& out = std::cout;

    Solver solver;
    solver.solve(1, in, out);

    return 0;
}
// End of Code
