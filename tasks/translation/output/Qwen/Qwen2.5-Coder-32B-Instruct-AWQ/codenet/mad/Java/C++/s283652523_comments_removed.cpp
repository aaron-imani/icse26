#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class FastScanner {
private:
    istream& input;

public:
    FastScanner() : input(cin) {}
    FastScanner(istream& stream) : input(stream) {}

    void close() {
        // No need to close cin
    }

    int nextInt() {
        long nl = nextLong();
        if (nl < numeric_limits<int>::min() || nl > numeric_limits<int>::max()) throw invalid_argument("Number out of int range");
        return static_cast<int>(nl);
    }

    long nextLong() {
        long ret = 0;
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
        while ('0' <= b && b <= '9') {
            ret *= 10;
            ret += b - '0';
            b = input.get();
        }
        return ret * sign;
    }

    double nextDouble() {
        double ret = 0;
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
        while ('0' <= b && b <= '9') {
            ret *= 10;
            ret += b - '0';
            b = input.get();
        }
        if (b != '.') return ret * sign;
        double div = 1;
        b = input.get();
        while ('0' <= b && b <= '9') {
            ret *= 10;
            ret += b - '0';
            div *= 10;
            b = input.get();
        }
        return ret * sign / div;
    }

    char nextChar() {
        int b = input.get();
        while (isspace(b)) {
            b = input.get();
        }
        return static_cast<char>(b);
    }

    string nextStr() {
        string sb;
        int b = input.get();
        while (isspace(b)) {
            b = input.get();
        }
        while (b != -1 && !isspace(b)) {
            sb += static_cast<char>(b);
            b = input.get();
        }
        return sb;
    }

    string nextLine() {
        string sb;
        int b = input.get();
        while (b != -1 && b != '
') {
            sb += static_cast<char>(b);
            b = input.get();
        }
        return sb;
    }

    vector<int> nextIntArray(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    vector<int> nextIntArrayDec(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextInt() - 1;
        }
        return res;
    }

    vector<int> nextIntArray1Index(int n) {
        vector<int> res(n + 1);
        for (int i = 0; i < n; i++) {
            res[i + 1] = nextInt();
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

    vector<long> nextLongArrayDec(int n) {
        vector<long> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextLong() - 1;
        }
        return res;
    }

    vector<long> nextLongArray1Index(int n) {
        vector<long> res(n + 1);
        for (int i = 0; i < n; i++) {
            res[i + 1] = nextLong();
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
        cout << ans << endl;
    }
};

int main() {
    Main main;
    main.solve();
    return 0;
}
// End of Code
