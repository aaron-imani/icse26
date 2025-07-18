#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

const int MOD = 1e9 + 7;

class FastScanner {
private:
    std::istream& input;

public:
    FastScanner() : input(std::cin) {}
    FastScanner(std::istream& stream) : input(stream) {}

    void close() {
        // No need to close cin
    }

    int nextInt() {
        long nl = nextLong();
        if (nl < std::numeric_limits<int>::min() || nl > std::numeric_limits<int>::max()) throw std::out_of_range("Number out of int range");
        return static_cast<int>(nl);
    }

    long nextLong() {
        try {
            int sign = 1;
            int b = input.get();
            while ((b < '0' || '9' < b) && b != '-' && b != '+') {
                b = input.get();
            }
            if (b == '-') {
                sign = -1;
                b = input.get();
            } else if (b == '+') {
                b = input.get();
            }
            long ret = b - '0';
            while (true) {
                b = input.get();
                if (b < '0' || '9' < b) return ret * sign;
                ret *= 10;
                ret += b - '0';
            }
        } catch (std::ios_base::failure& e) {
            std::cerr << e.what() << std::endl;
            return -1;
        }
    }

    double nextDouble() {
        try {
            double sign = 1;
            int b = input.get();
            while ((b < '0' || '9' < b) && b != '-' && b != '+') {
                b = input.get();
            }
            if (b == '-') {
                sign = -1;
                b = input.get();
            } else if (b == '+') {
                b = input.get();
            }
            double ret = b - '0';
            while (true) {
                b = input.get();
                if (b < '0' || '9' < b) break;
                ret *= 10;
                ret += b - '0';
            }
            if (b != '.') return sign * ret;
            double div = 1;
            b = input.get();
            while ('0' <= b && b <= '9') {
                ret *= 10;
                ret += b - '0';
                div *= 10;
                b = input.get();
            }
            return sign * ret / div;
        } catch (std::ios_base::failure& e) {
            std::cerr << e.what() << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
        }
    }

    char nextChar() {
        try {
            int b = input.get();
            while (std::isspace(b)) {
                b = input.get();
            }
            return static_cast<char>(b);
        } catch (std::ios_base::failure& e) {
            std::cerr << e.what() << std::endl;
            return 0;
        }
    }

    std::string nextStr() {
        try {
            std::string sb;
            int b = input.get();
            while (std::isspace(b)) {
                b = input.get();
            }
            while (b != -1 && !std::isspace(b)) {
                sb += static_cast<char>(b);
                b = input.get();
            }
            return sb;
        } catch (std::ios_base::failure& e) {
            std::cerr << e.what() << std::endl;
            return "";
        }
    }

    std::string nextLine() {
        try {
            std::string sb;
            int b = input.get();
            while (b != -1 && b != '\n') {
                sb += static_cast<char>(b);
                b = input.get();
            }
            return sb;
        } catch (std::ios_base::failure& e) {
            std::cerr << e.what() << std::endl;
            return "";
        }
    }

    std::vector<int> nextIntArray(int n) {
        std::vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }
};

class Main {
private:
    FastScanner in;
    std::ostream& out;

public:
    Main() : out(std::cout) {}

    void solve() {
        int N = in.nextInt();
        std::vector<int> A = in.nextIntArray(N);

        long long ans = 0, sum = A[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            ans += (sum * A[i]) % MOD;
            ans %= MOD;
            sum += A[i];
            sum %= MOD;
        }
        out << ans << std::endl;
    }

    void m() {
        solve();
        out.flush();
    }
};

int main() {
    Main mainInstance;
    mainInstance.m();
    return 0;
}
// End of Code
