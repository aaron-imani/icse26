#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int MOD = 1e9 + 7;

class FastScanner {
private:
    FILE *input;

public:
    FastScanner() : input(stdin) {}
    FastScanner(FILE *stream) : input(stream) {}

    void close() {
        fclose(input);
    }

    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Number format exception");
        return static_cast<int>(nl);
    }

    long long nextLong() {
        int sign = 1;
        int b = fgetc(input);
        while ((b < '0' || '9' < b) && b != '-' && b != '+') {
            b = fgetc(input);
        }
        if (b == '-') {
            sign = -1;
            b = fgetc(input);
        } else if (b == '+') {
            b = fgetc(input);
        }
        long long ret = b - '0';
        while (true) {
            b = fgetc(input);
            if (b < '0' || '9' < b) return ret * sign;
            ret *= 10;
            ret += b - '0';
        }
    }

    double nextDouble() {
        double sign = 1;
        int b = fgetc(input);
        while ((b < '0' || '9' < b) && b != '-' && b != '+') {
            b = fgetc(input);
        }
        if (b == '-') {
            sign = -1;
            b = fgetc(input);
        } else if (b == '+') {
            b = fgetc(input);
        }
        double ret = b - '0';
        while (true) {
            b = fgetc(input);
            if (b < '0' || '9' < b) break;
            ret *= 10;
            ret += b - '0';
        }
        if (b != '.') return sign * ret;
        double div = 1;
        b = fgetc(input);
        while ('0' <= b && b <= '9') {
            ret *= 10;
            ret += b - '0';
            div *= 10;
            b = fgetc(input);
        }
        return sign * ret / div;
    }

    char nextChar() {
        int b = fgetc(input);
        while (isspace(b)) {
            b = fgetc(input);
        }
        return static_cast<char>(b);
    }

    string nextStr() {
        string sb;
        int b = fgetc(input);
        while (isspace(b)) {
            b = fgetc(input);
        }
        while (b != EOF && !isspace(b)) {
            sb.push_back(static_cast<char>(b));
            b = fgetc(input);
        }
        return sb;
    }

    string nextLine() {
        string sb;
        int b = fgetc(input);
        while (b != EOF && b != '\n') {
            sb.push_back(static_cast<char>(b));
            b = fgetc(input);
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
};

class Main {
private:
    FastScanner in;
    FILE *out;

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
        fprintf(out, "%lld\n", ans);
    }

public:
    void m() {
        in = FastScanner();
        out = stdout;

        solve();
        fclose(out);
        in.close();
    }
};

int main() {
    Main().m();
    return 0;
} // End of Code
