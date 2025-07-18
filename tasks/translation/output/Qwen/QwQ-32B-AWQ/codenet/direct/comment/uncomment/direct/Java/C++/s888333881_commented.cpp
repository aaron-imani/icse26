#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long powMod(long long base, long long exp, long long mod) {
    if (exp == 0) return 1 % mod;
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<bool> flaged(n);
    long long pop1st = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; ++i) {
        surp1 = (surp1 * 2) % (pop1st + 1);
        if (flaged[i]) {
            surp1 = (surp1 + 1) % (pop1st + 1);
        }
    }

    long long surp9 = 0;
    if (pop1st > 1) {
        surp9 = 0;
        for (int i = 0; i < n; ++i) {
            surp9 = (surp9 * 2) % (pop1st - 1);
            if (flaged[i]) {
                surp9 = (surp9 + 1) % (pop1st - 1);
            }
        }
    }

    for (int p = 0; p < n; ++p) {
        if (flaged[p]) {
            if (pop1st == 1) {
                cout << 0 << endl;
                continue;
            }
            long long dw = surp9;
            long long exponent = n - p - 1;
            long long mod = pop1st - 1;
            long long dif = powMod(2, exponent, mod);
            dw -= dif;
            dw += mod; // To handle negative values
            dw %= mod;
            int ans = 1;
            while (dw != 0) {
                int count = __builtin_popcountll(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        } else {
            long long dw = surp1;
            long long exponent = n - p - 1;
            long long mod = pop1st + 1;
            long long dif = powMod(2, exponent, mod);
            dw += dif;
            dw %= mod;
            int ans = 1;
            while (dw != 0) {
                int count = __builtin_popcountll(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
// End of Code
