#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <functional>
#include <numeric>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <chrono>

using namespace std;

const int INF = 1e8;
const long long INFL = 1e17;
const long long e97 = 1e9 + 7;

template<typename T>
void fill_parent(vector<T>& ob, T val) {
    for (int i = 0; i < ob.size(); i++) ob[i] = val;
}

template<typename T>
T get_root_uf(vector<T>& parent, int index) {
    if (parent[index] == index) return index;
    T root = get_root_uf(parent, parent[index]);
    parent[index] = root;
    return root;
}

template<typename T>
bool is_same_uf(vector<T>& parent, int x, int y) {
    if (get_root_uf(parent, x) == get_root_uf(parent, y)) return true;
    else return false;
}

template<typename T>
void unite_uf(vector<T>& parent, int receiver, int attacker) {
    parent[get_root_uf(parent, attacker)] = get_root_uf(parent, receiver);
}

template<typename T>
int getDigit2(T num) {
    T cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf = (1LL << d);
    }
    return d;
}

template<typename T>
int countFlaged(T bit) {
    int ans = 0;
    for (int i = 0; i < getDigit2(bit); i++) {
        if ((bit & (1LL << i)) > 0) ans++;
    }
    return ans;
}

template<typename T>
T pow10E97(T ob, T soeji, T p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = getDigit2(soeji);
    vector<T> ob_pow_2pow(d);

    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) {
        ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;
    }

    T ans = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> flaged(n, false);

    long long pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2LL;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1LL);
    }

    long long surp9 = 0LL;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2LL;
            if (flaged[i]) surp9++;
            surp9 %= (pop1st - 1LL);
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                cout << 0 << "\n";
                continue;
            }
            long long dw = surp9;

            long long dif = pow10E97(2LL, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1LL);
            dw %= (pop1st - 1LL);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) cout << 1 / 0;
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << "\n";
        } else {
            long long dw = surp1;

            long long dif = pow10E97(2LL, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1LL);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) cout << 1 / 0;
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}

// End of Code
