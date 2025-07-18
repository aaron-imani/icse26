#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

struct Edge {
    int from = -1, v2 = -1;
    long long weight;
};

struct Edge2 {
    int v2;
    long long cost1, cost2;
};

int INF = 1e8;
long long INFL = 1e17;
long long e97 = 1e9 + 7;

int getDigit2(long long num) {
    long long cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf = (1LL << d);
    }
    return d;
}

long long pow10E97(long long ob, long long soeji, long long p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;
    int d = getDigit2(soeji);
    vector<long long> ob_pow_2pow(d);
    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; ++i) {
        ob_pow_2pow[i] = (ob_pow_2pow[i-1] * ob_pow_2pow[i-1]) % p;
    }
    long long ans = 1;
    for (int i = d-1; i >= 0; --i) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

int countFlaged(long long bit) {
    int ans = 0;
    for (long long i = 0; i < getDigit2(bit); ++i) {
        if ((bit & (1LL << i)) != 0) ans++;
    }
    return ans;
}

struct FastScanner {
    vector<char> buffer;
    size_t ptr = 0, buflen = 0;
    ifstream in;

    FastScanner() {
        buffer.resize(1024);
        in = ifstream(cin.rdbuf());
    }

    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = in.read(buffer.data(), buffer.size()) ? in.gcount() : 0;
        return buflen > 0;
    }

    int readByte() {
        if (hasNextByte()) return buffer[ptr++];
        else return -1;
    }

    static bool isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    bool hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte();
    }

    string next() {
        if (!hasNext()) throw runtime_error("No element");
        string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb += (char)b;
            b = readByte();
        }
        return sb;
    }

    long long nexL() {
        if (!hasNext()) throw runtime_error("No element");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || b > '9') throw runtime_error("Invalid number");
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b) || b == ':') {
                return minus ? -n : n;
            } else {
                throw runtime_error("Invalid number");
            }
            b = readByte();
        }
    }

    int nexI() {
        long long nl = nexL();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Overflow");
        return static_cast<int>(nl);
    }
};

int main() {
    FastScanner sc;
    int n = sc.nexI();
    string s = sc.next();
    vector<bool> flaged(n, false);
    long long pop1st = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; ++i) {
        surp1 *= 2LL;
        if (flaged[i]) surp1 += 1;
        surp1 %= (pop1st + 1LL);
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; ++i) {
            surp9 *= 2LL;
            if (flaged[i]) surp9 += 1;
            surp9 %= (pop1st - 1LL);
        }
    }

    for (int p = 0; p < n; ++p) {
        if (flaged[p]) {
            if (pop1st == 1) {
                cout << 0 << endl;
                continue;
            }
            long long dw = surp9;
            long long dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1LL);
            dw %= (pop1st - 1LL);
            if (dw < 0) dw += (pop1st - 1LL);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) {
                    cout << 1/0;
                }
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        } else {
            long long dw = surp1;
            long long dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1LL);

            int ans = olve << ans << endl;
        }
    }
    return 0;
}
// End of Code
