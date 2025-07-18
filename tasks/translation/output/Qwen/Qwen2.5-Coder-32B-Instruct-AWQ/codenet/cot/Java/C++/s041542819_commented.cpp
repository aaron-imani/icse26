#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>
#include <stdexcept>

class LightScanner {
private:
    std::istringstream iss;
    std::string line;
    std::vector<std::string> tokens;
    size_t tokenIndex;

public:
    LightScanner(std::istream& in) {
        std::string input((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
        iss.str(input);
        tokenIndex = 0;
    }

    std::string string() {
        if (tokenIndex >= tokens.size()) {
            std::getline(iss, line);
            tokens.clear();
            std::istringstream lineStream(line);
            std::string token;
            while (lineStream >> token) {
                tokens.push_back(token);
            }
            tokenIndex = 0;
        }
        return tokens[tokenIndex++];
    }

    int ints() {
        return std::stoi(string());
    }

    long long longs() {
        return std::stoll(string());
    }
};

class LightWriter {
private:
    std::ostream& out;

public:
    LightWriter(std::ostream& out) : out(out) {}

    LightWriter& print(char c) {
        out << c;
        return *this;
    }

    LightWriter& print(const std::string& s) {
        out << s;
        return *this;
    }

    LightWriter& ans(const std::string& s) {
        out << ' ' << s;
        return *this;
    }

    LightWriter& ans(long long l) {
        return ans(std::to_string(l));
    }

    LightWriter& ansln(long long n) {
        ans(n);
        out << '\n';
        return *this;
    }

    LightWriter& ln() {
        out << '\n';
        return *this;
    }

    void close() {
        out.flush();
    }
};

class IntMath {
public:
    static long long min(std::initializer_list<long long> v) {
        return *std::min_element(v.begin(), v.end());
    }
};

class ArrayUtil {
public:
    static int lowerBound(const std::vector<long long>& a, long long t) {
        return lowerBound(a, t, 0);
    }

    static int lowerBound(const std::vector<long long>& a, long long t, int min) {
        int max = a.size();
        while (min < max) {
            int mid = (min + max) / 2;
            if (t <= a[mid]) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        return min;
    }
};

class DLazyFaith {
public:
    void solve(int testNumber, LightScanner& in, LightWriter& out) {
        int a = in.ints(), b = in.ints(), q = in.ints();
        std::vector<long long> s(a + 2), t(b + 2);
        s[0] = t[0] = -10000000000LL;
        for (int i = 0; i < a; i++) {
            s[i + 1] = in.longs();
        }
        for (int i = 0; i < b; i++) {
            t[i + 1] = in.longs();
        }
        s[a + 1] = t[b + 1] = 20000000000LL;
        for (int i = 0; i < q; i++) {
            long long x = in.longs();
            long long sl = x - s[std::max(0, ArrayUtil::lowerBound(s, x + 1) - 1)];
            long long tl = x - t[std::max(0, ArrayUtil::lowerBound(t, x + 1) - 1)];
            long long sr = s[ArrayUtil::lowerBound(s, x)] - x;
            long long tr = t[ArrayUtil::lowerBound(t, x)] - x;
            out.ansln(IntMath::min({
                std::max(sl, tl),
                std::max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
            }));
        }
    }
};

int main() {
    LightScanner in(std::cin);
    LightWriter out(std::cout);
    DLazyFaith solver;
    solver.solve(1, in, out);
    out.close();
    return 0;
}
// End of Code
