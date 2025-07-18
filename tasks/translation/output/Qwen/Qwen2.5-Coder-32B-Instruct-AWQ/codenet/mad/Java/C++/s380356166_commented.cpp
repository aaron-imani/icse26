// End of Code
#include <iostream>
#include <sstream>

class MyInput {
private:
    std::istream& in;
    std::string buffer;
    size_t pos;
    size_t readLen;

    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    bool isSpace(char c) {
        return c == ' ' || c == '' || c == '
' || c == '	';
    }

    int read() {
        if (pos >= readLen) {
            pos = 0;
            if (!std::getline(in, buffer)) {
                throw std::runtime_error("End of file");
            }
            readLen = buffer.size();
        }
        return pos < readLen ? buffer[pos++] : -1;
    }

public:
    MyInput(std::istream& is) : in(is), pos(0), readLen(0) {}

    int nextInt() {
        std::string numStr;
        int c = read();
        if (c == '-') {
            numStr += c;
            c = read();
        }
        while (isDigit(c)) {
            numStr += c;
            c = read();
        }
        return std::stoi(numStr);
    }

    long long nextLong() {
        std::string numStr;
        int c = read();
        if (c == '-') {
            numStr += c;
            c = read();
        }
        while (isDigit(c)) {
            numStr += c;
            c = read();
        }
        return std::stoll(numStr);
    }

    std::string nextString() {
        std::string str;
        int c = read();
        while (isSpace(c)) {
            c = read();
        }
        while (!isSpace(c) && c != -1) {
            str += c;
            c = read();
        }
        return str;
    }
};

class Solver {
public:
    void solve(int testNumber, MyInput& in, std::ostream& out) {
        int ans = 0;
        int K = in.nextInt();
        int S = in.nextInt();
        int wk = 0;
        for (int x = 0; x <= K; x++) {
            for (int y = 0; y <= K; y++) {
                wk = S - x - y;
                if (wk >= 0 && wk <= K) {
                    ans++;
                }
            }
        }
        out << ans << std::endl;
    }
};

int main() {
    MyInput in(std::cin);
    std::ostream& out = std::cout;

    Solver solver;
    solver.solve(1, in, out);

    return 0;
}
// End of Code
