#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class FastScanner {
private:
    ifstream fin;
    string buffer;
    size_t pos;

public:
    FastScanner(istream &in) : fin(), buffer(), pos(0) {
        swap(fin, dynamic_cast<ifstream&>(in));
    }

    ~FastScanner() {
        fin.close();
    }

    int nextInt() {
        return (int)nextLong();
    }

    long long nextLong() {
        skipWhitespace();
        bool negative = false;
        if (buffer[pos] == '-') {
            negative = true;
            ++pos;
        }
        long long result = 0;
        while (pos < buffer.size() && isdigit(buffer[pos])) {
            result = result * 10 + (buffer[pos] - '0');
            ++pos;
        }
        return negative ? -result : result;
    }

    double nextDouble() {
        skipWhitespace();
        bool negative = false;
        if (buffer[pos] == '-') {
            negative = true;
            ++pos;
        }
        double result = 0;
        while (pos < buffer.size() && isdigit(buffer[pos])) {
            result = result * 10 + (buffer[pos] - '0');
            ++pos;
        }
        if (pos < buffer.size() && buffer[pos] == '.') {
            ++pos;
            double divisor = 1;
            while (pos < buffer.size() && isdigit(buffer[pos])) {
                result = result * 10 + (buffer[pos] - '0');
                divisor *= 10;
                ++pos;
            }
            result /= divisor;
        }
        return negative ? -result : result;
    }

    char nextChar() {
        skipWhitespace();
        return buffer[pos++];
    }

    string nextStr() {
        skipWhitespace();
        string result;
        while (pos < buffer.size() && !isspace(buffer[pos])) {
            result += buffer[pos++];
        }
        return result;
    }

    string nextLine() {
        string result;
        while (pos < buffer.size() && buffer[pos] != '\n') {
            result += buffer[pos++];
        }
        if (pos < buffer.size() && buffer[pos] == '\n') {
            ++pos;
        }
        return result;
    }

    vector<int> nextIntArray(int n) {
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = nextInt();
        }
        return result;
    }

private:
    void skipWhitespace() {
        while (pos < buffer.size() && isspace(buffer[pos])) {
            ++pos;
        }
        if (pos == buffer.size()) {
            buffer.clear();
            pos = 0;
            string line;
            if (getline(fin, line)) {
                buffer = line;
            }
        }
    }
};

void solve(FastScanner &in, ostream &out) {
    int N = in.nextInt();
    vector<int> A(N);
    for (int &x : A) x = in.nextInt();

    long long ans = 0, sum = A[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    out << ans << "\n";
}

int main() {
    FastScanner in(cin);
    ostream &out = cout;
    solve(in, out);
    return 0;
}
// End of Code
