#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

const int MOD = 1e9 + 7;

class FastScanner {
private:
    istream& in;

public:
    FastScanner(istream& stream) : in(stream) {}

    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Overflow");
        return static_cast<int>(nl);
    }

    long long nextLong() {
        int sign = 1;
        int b = in.get();
        while ((b < '0' || '9' < b) && b != '-' && b != '+') {
            b = in.get();
        }
        if (b == '-') {
            sign = -1;
            b = in.get();
        } else if (b == '+') {
            b = in.get();
        }
        long long ret = b - '0';
        while (true) {
            b = in.get();
            if (b < '0' || '9' < b) return ret * sign;
            ret *= 10;
            ret += b - '0';
        }
    }

    double nextDouble() {
        int sign = 1;
        int b = in.get();
        while ((b < '0' || '9' < b) && b != '-' && b != '+') {
            b = in.get();
        }
        if (b == '-') {
            sign = -1;
            b = in.get();
        } else if (b == '+') {
            b = in.get();
        }
        double ret = b - '0';
        while (true) {
            b = in.get();
            if (b < '0' || '9' < b) break;
            ret *= 10;
            ret += b - '0';
        }
        if (b != '.') return sign * ret;
        double div = 1;
        b = in.get();
        while ('0' <= b && b <= '9') {
            ret *= 10;
            ret += b - '0';
            div *= 10;
            b = in.get();
        }
        return sign * ret / div;
    }

    char nextChar() {
        int b = in.get();
        while (isspace(b)) {
            b = in.get();
        }
        return static_cast<char>(b);
    }

    string nextStr() {
        string sb;
        int b = in.get();
        while (isspace(b)) {
            b = in.get();
        }
        while (b != -1 && !isspace(b)) {
            sb.push_back(static_cast<char>(b));
            b = in.get();
        }
        return sb;
    }

    string nextLine() {
        string sb;
        int b = in.get();
        while (b != -1 && b != '\n') {
            sb.push_back(static_cast<char>(b));
            b = in.get();
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

    vector<long long> nextLongArray(int n) {
        vector<long long> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextLong();
        }
        return res;
    }

    vector<long long> nextLongArrayDec(int n) {
        vector<long long> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextLong() - 1;
        }
        return res;
    }

    vector<long long> nextLongArray1Index(int n) {
        vector<long long> res(n + 1);
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

void solve(FastScanner& in, ostream& out) {
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

int main() {
    FastScanner in(cin);
    ostream& out = cout;

    solve(in, out);
    return 0;
}
// End of Code
