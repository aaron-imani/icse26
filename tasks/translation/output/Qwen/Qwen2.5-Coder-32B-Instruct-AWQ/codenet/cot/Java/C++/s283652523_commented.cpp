#include <iostream>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

const int MOD = 1e9 + 7;

class FastScanner {
private:
    istream& input;

public:
    FastScanner() : input(cin) {}
    FastScanner(istream& stream) : input(stream) {}

    void close() {
        input.clear();
    }

    int nextInt() {
        long nl = nextLong();
        if (nl < numeric_limits<int>::min() || nl > numeric_limits<int>::max()) throw invalid_argument("Number out of int range");
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
        } catch (ios_base::failure& e) {
            cerr << e.what() << endl;
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
        } catch (ios_base::failure& e) {
            cerr << e.what() << endl;
            return numeric_limits<double>::quiet_NaN();
        }
    }

    char nextChar() {
        try {
            int b = input.get();
            while (isspace(b)) {
                b = input.get();
            }
            return static_cast<char>(b);
        } catch (ios_base::failure& e) {
            cerr << e.what() << endl;
            return 0;
        }
    }

    string nextStr() {
        try {
            stringstream ss;
            int b = input.get();
            while (isspace(b)) {
                b = input.get();
            }
            while (b != -1 && !isspace(b)) {
                ss << static_cast<char>(b);
                b = input.get();
            }
            return ss.str();
        } catch (ios_base::failure& e) {
            cerr << e.what() << endl;
            return "";
        }
    }

    string nextLine() {
        try {
            stringstream ss;
            int b = input.get();
            while (b != -1 && b != '\n') {
                ss << static_cast<char>(b);
                b = input.get();
            }
            return ss.str();
        } catch (ios_base::failure& e) {
            cerr << e.what() << endl;
            return "";
        }
    }

    vector<int> nextIntArray(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }
};

class Main {
private:
    FastScanner in;
    ostream& out;

public:
    Main() : out(cout) {}

    void solve() {
        int N = in.nextInt();
        vector<int> A = in.nextIntArray(N);

        long long ans = 0, sum = A[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            ans += (sum * A[i]) % MOD;
            ans %= MOD;
            sum += A[i];
            sum %= MOD;
        }
        out << ans << endl;
    }

    void m() {
        solve();
        out.flush();
        in.close();
    }
};

int main() {
    Main mainInstance;
    mainInstance.m();
    return 0;
}
// End of Code
