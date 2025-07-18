#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

class FastScanner {
private:
    FILE *stream;
    char buffer[1024];
    size_t ptr = 0, buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = fread(buffer, 1, sizeof(buffer), stream);
        return buflen > 0;
    }

    int readByte() {
        if (hasNextByte()) return static_cast<int>(buffer[ptr++]);
        return -1;
    }

    static bool isPrintableChar(int c) {
        return c >= 33 && c <= 126;
    }

public:
    FastScanner() : stream(stdin) {}

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string res;
        int b = readByte();
        while (isPrintableChar(b)) {
            res += static_cast<char>(b);
            b = readByte();
        }
        return res;
    }

    long long nexL() {
        if (!hasNext()) throw runtime_error("No more input");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') throw invalid_argument("Invalid number");
        while (true) {
            if (b >= '0' && b <= '9') {
                n = n * 10 + (b - '0');
            } else if (b == -1 || !isPrintableChar(b) || b == ':') {
                break;
            } else {
                throw invalid_argument("Invalid character in number");
            }
            b = readByte();
        }
        return minus ? -n : n;
    }

    int nexI() {
        long long val = nexL();
        if (val < INT_MIN || val > INT_MAX) throw invalid_argument("Value out of int range");
        return static_cast<int>(val);
    }
};

long long powMod(long long base, long long exp, long long mod) {
    if (mod == 1) return 0;
    base %= mod;
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    FastScanner sc;
    vector<bool> flaged;
    long long pop1st = 0;

    int n = sc.nexI();
    string s = sc.next();
    flaged.resize(n);
    fill(flaged.begin(), flaged.end(), false);

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2LL;
        surp1 %= (pop1st + 1LL); // To prevent overflow
        if (flaged[i]) {
            surp1++;
        }
        surp1 %= (pop1st + 1LL);
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2LL;
            surp9 %= (pop1st - 1LL);
            if (flaged[i]) {
                surp9++;
            }
            surp9 %= (pop1st - 1LL);
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                cout << 0 << '\n';
                continue;
            }
            long long dw = surp9;
            long long dif = powMod(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1LL);
            dw %= (pop1st - 1LL);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) {
                    cout << "Error\n";
                    return 1;
                }
                int count = __builtin_popcountll(dw);
                dw %= count;
                ans++;
            }
            cout << ans << '\n';
        } else {
            long long dw = surp1;
            long long dif = powMod(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1LL);

            int ans = 1;
            while (dw != 0) {
                int count = __builtin_popcountll(dw);
                dw %= count;
                ans++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
// End of Code
