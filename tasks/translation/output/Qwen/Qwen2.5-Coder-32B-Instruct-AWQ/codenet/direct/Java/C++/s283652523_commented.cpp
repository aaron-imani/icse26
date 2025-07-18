#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class FastScanner {
private:
    ifstream input;

public:
    FastScanner() { input = ifstream(cin.rdbuf()); }
    FastScanner(string filename) { input = ifstream(filename); }
    void close() { input.close(); }

    int nextInt() {
        long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Number out of int range");
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
        } catch (exception e) {
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
        } catch (exception e) {
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
        } catch (exception e) {
            cerr << e.what() << endl;
            return 0;
        }
    }

    string nextStr() {
        try {
            string ret;
            int b = input.get();
            while (isspace(b)) {
                b = input.get();
            }
            while (b != -1 && !isspace(b)) {
                ret += static_cast<char>(b);
                b = input.get();
            }
            return ret;
        } catch (exception e) {
            cerr << e.what() << endl;
            return "";
        }
    }

    string nextLine() {
        try {
            string ret;
            int b = input.get();
            while (b != -1 && b != '\n') {
                ret += static_cast<char>(b);
                b = input.get();
            }
            return ret;
        } catch (exception e) {
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

    vector<long> nextLongArray(int n) {
        vector<long> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextLong();
        }
        return res;
    }

    vector<double> nextDoubleArray(int n) {
        vector<double> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextDouble();
        }
        return res;
    }
};

class Main {
private:
    FastScanner in;
    ofstream out;

public:
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
        in = FastScanner();
        out = ofstream(cout.rdbuf());
        /*
        try {
            string path = "input.txt";
            out = ofstream(path);
        } catch (exception e) {
            cerr << e.what() << endl;
        }
        */
        solve();
        out.flush();
        in.close();
        out.close();
    }
};

int main() {
    Main().m();
    return 0;
}
// End of Code
