// End of Code
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class MyInput {
private:
    std::istream& in;
    std::string buffer;
    size_t pos;

public:
    MyInput(std::istream& is) : in(is), pos(0) {}

    int read() {
        if (pos >= buffer.size()) {
            if (!std::getline(in, buffer)) {
                return -1; // End of file
            }
            pos = 0;
        }
        return pos < buffer.size() ? buffer[pos++] : -1;
    }

    int nextInt() {
        std::string numStr;
        int c;
        while ((c = read()) != -1 && (c < '0' || c > '9') && c != '-');
        if (c == -1) return 0;
        numStr += c;
        while ((c = read()) != -1 && ((c >= '0' && c <= '9') || c == '-')) {
            numStr += c;
        }
        return std::stoi(numStr);
    }

    std::string nextString() {
        std::string str;
        int c;
        while ((c = read()) != -1 && (c == ' ' || c == '	' || c == '
'));
        if (c == -1) return "";
        str += c;
        while ((c = read()) != -1 && c != ' ' && c != '	' && c != '
') {
            str += c;
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
    Solver solver;
    solver.solve(1, in, std::cout);
    return 0;
}
// End of Code
