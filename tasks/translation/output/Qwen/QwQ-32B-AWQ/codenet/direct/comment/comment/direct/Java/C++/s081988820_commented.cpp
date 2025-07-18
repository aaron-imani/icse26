#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <optional>
#include <stdexcept>

struct Main {
    class Scanner {
    private:
        std::istream& in;
        std::vector<char> buffer;
        int index, length;

    public:
        Scanner(std::istream& in) : in(in), buffer(1024), index(0), length(0) {}

        bool isPrintableChar(int c) {
            return '!' <= c && c <= '~';
        }

        bool hasNextByte() {
            if (index < length) return true;
            in.read(buffer.data(), buffer.size());
            length = static_cast<int>(in.gcount());
            index = 0;
            return length > 0;
        }

        bool hasNext() {
            while (hasNextByte()) {
                int c = static_cast<unsigned char>(buffer[index]);
                if (isPrintableChar(c)) return true;
                ++index;
            }
            return false;
        }

        int readByte() {
            if (hasNextByte()) return static_cast<unsigned char>(buffer[index++]);
            return -1;
        }

        std::string next() {
            if (!hasNext()) throw std::runtime_error("no input");
            std::string s;
            int b = readByte();
            while (isPrintableChar(b)) {
                s += static_cast<char>(b);
                b = readByte();
            }
            return s;
        }

        long long nextLong() {
            if (!hasNext()) throw std::runtime_error("no input");
            long long val = 不出;
            bool minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            while (isPrintableChar(b)) {
                if (std::isdigit(b)) {
                    val = val * 10 + (b - '0');
                }
                b = readByte();
            }
            return minus ? -val : val;
        }

        int nextInt() { return static_cast<int>(nextLong()); }
        double nextDouble() { return std::stod(next()); }
    };

    class MobiusFunction {
    public:
        virtual int get(int n) = 0;
    };

    class SieveMobiusFunction : public MobiusFunction {
    private:
        int size;
        std::vector<int> mobiusFunctionValues;

    public:
        SieveMobiusFunction(int s) : size(s), mobiusFunctionValues(s) {
            mobiusFunctionValues[0] = 0;
            mobiusFunctionValues[1] = 1;
            for (int i = 2; i < size; ++i) mobiusFunctionValues[i] = 1;
            for (int i = 2; i * i < size; ++i) {
                for (int k = 1; i * i * k < size; ++k) {
                    mobiusFunctionValues[i * i * k] *= 0;
                }
            }
            for (int i = 2; i < size; ++i) {
                if (mobiusFunctionValues[i] == 1) {
                    for (int k = 1; i * k < size; ++k) {
                        mobiusFunctionValues[i * k] *= -2;
                    }
                }
                if (mobiusFunctionValues[i] > 1) mobiusFunctionValues[i] = 1;
                if (mobiusFunctionValues[i] < -1) mobiusFunctionValues[i] = -1;
            }
        }

        int get(int n) override {
            if (n > size) throw std::runtime_error("n exceeds size");
            return n < 0 ? 0 : mobiusFunctionValues[n];
        }
    };

    class CombCalculator {
    public:
        virtual long long comb(int n, int m) = 0;
    };

    class FactorialTableCombCalculator : public CombCalculator {
    private:
        int size;
        std::vector<long long> fact, inv_fact;
        long long mod;

        long long inverse(long long n, long long mod) {
            return pow(n, mod - 2, mod);
        }

        long long pow(long long n, long long p, long long mod) {
            if (!p) return 1LL;
            long long h = pow(n, p / 2, mod);
            h = (h * h) % mod;
            return p % 2 ? (h * n) % mod : h;
        }

    public:
        FactorialTableCombCalculator(int s, long long m) : size(s), mod(m) {
            fact.resize(s + 1);
            inv_fact.resize(s + 1);
            fact[0] = 1;
            for (int i = 1; i <= s; ++i) fact[i] = (fact[i-1] * i) % mod;
            inv_fact[s] = inverse(fact[s], mod);
            for (int i = s-1; i >= 0; --i) inv_fact[i] = (inv_fact[i+1] * (i+1)) % mod;
        }

        long long comb(int n, int m) override {
            if (n > size) throw std::runtime_error("n exceeds size");
            if (n < 0 || m < 0 || n < m) return 0;
            return (fact[n] * inv_fact[m] % mod) * inv_fact[n - m] % mod;
        }
    };

    void solve() {
        Scanner sc(std::cin);
        int H = sc.nextInt();
        int W = sc.nextInt();
        std::vector<std::vector<int>> c(10, std::vector<int>(10));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                c[i][j] = sc.nextInt();
            }
        }
        std::vector<int> min(10);
        for (int i = 0; i < 10; ++i) min[i] = c[i][1];
        for (int tc = 0; tc < 10; ++tc) {
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    min[i] = std::min(min[i], c[i][j] + min[j]);
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
        std::cout << ans << std::endl;
    }
};

int main() {
    Main main;
    main.solve();
    return 0;
}
// End of Code
