#include <iostream>
#include <unordered_map>
#include <string>

const long long INF = LONG_MAX / 2;
const int MOD = 1'000'000'007;
const int SIZE = 1'000'000;

long long fac[SIZE];
long long inv[SIZE];
long long finv[SIZE];

class FastScanner {
private:
    std::istream& in;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        in.read(buffer, 1024);
        buflen = in.gcount();
        return buflen > 0;
    }

    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }

    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

public:
    FastScanner(std::istream& input = std::cin) : in(input) {}

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    std::string next() {
        if (!hasNext()) throw std::runtime_error("No more input");
        std::string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.push_back(static_cast<char>(b));
            b = readByte();
        }
        return sb;
    }

    long long nextLong() {
        if (!hasNext()) throw std::runtime_error("No more input");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) throw std::runtime_error("Invalid number format");
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw std::runtime_error("Invalid number format");
            }
            b = readByte();
        }
    }

    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw std::runtime_error("Number out of range");
        return static_cast<int>(nl);
    }

    double nextDouble() {
        return std::stod(next());
    }
};

class Main {
public:
    void solve() {
        FastScanner sc;
        int n = sc.nextInt();
        int m = sc.nextInt();
        std::unordered_map<int, int> map;

        for (int i = 0; i < m; i++) {
            int s = sc.nextInt();
            int c = sc.nextInt();
            if (map.find(s) != map.end() && map[s] != c) {
                std::cout << -1 << std::endl;
                exit(0);
            }
            map[s] = c;
        }

        for (int i = 0; i < 1000; i++) {
            std::string s = std::to_string(i);
            bool flag = true;
            if (s.length() < n) continue;
            for (int j = 0; j < n; j++) {
                if ((map.find(j + 1) != map.end() && map[j + 1] != s[j] - '0') || (map.find(j + 1) == map.end() && s[j] - '0' != 0)) {
                    if (map.find(j + 1) == map.end() && j == 0 && s[j] - '0' == 1) {
                        continue;
                    }
                    flag = false;
                    break;
                }
            }
            if (flag && s.length() == n) {
                std::cout << s << std::endl;
                exit(0);
            }
        }

        std::cout << -1 << std::endl;
    }

    long long gcd(long long a, long long b) { // return a and b's greatest common divisor
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) { // return a and b's least common multiple
        return a * b / gcd(a, b);
    }

    long long inv(long long a) { // return a's inverse modulo MOD
        return pow(a, MOD - 2);
    }

    long long pow(long long a, long long r) { // return a^r modulo MOD
        long long sum = 1;
        while (r > _end_of_code
