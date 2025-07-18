#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>

class Scanner {
private:
    std::istream& in;
    std::vector<char> buffer;
    int index = 0;
    int length = 0;

public:
    Scanner(std::istream& in) : in(in), buffer(1024) {}

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
            in.read(buffer.data(), buffer.size());
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

    int readByte() {
        return hasNextByte() ? buffer[index++] : -1;
    }

    std::string next() {
        if (!hasNext()) {
            throw std::runtime_error("no input");
        }
        std::string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb += b;
            b = readByte();
        }
        return sb;
    }

    long long nextLong() {
        if (!hasNext()) {
            throw std::runtime_error("no input");
        }
        long long value =  0;
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

    int nextInt() {
        return static_cast<int>(nextLong());
    }

    double nextDouble() {
        return std::stod(next());
    }
};

class Main {
public:
    void solve() {
        Scanner sc(std::cin);
        int H = sc.nextInt();
        int W = sc.nextInt();
        std::vector<std::vector<int>> c(10, std::vector<int>(10));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i][j] = sc.nextInt();
            }
        }
        std::vector<int> min(10);
        for (int i = 0; i < 10; i++) {
            min[i] = c[i][1];
        }
        for (int tc = 0; tc < 10; tc++) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    min[i] = std::min(min[i], c[i][j] + min[j]);
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
        std::cout << ans << std::endl;
    }
};

int main() {
    Main main;
    main.solve();
    return 0;
}

// End of Code
