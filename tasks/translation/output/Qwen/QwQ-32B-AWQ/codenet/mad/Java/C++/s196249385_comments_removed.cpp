#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> cumsum(n + 1);
    cumsum[0] = 0;
    for (int i = 0; i < n; ++i) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    vector<long long> b;
    long long max_val = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            long long s = cumsum[j + 1] - cumsum[i];
            b.push_back(s);
            if (s > max_val) max_val = s;
        }
    }

    long long mask = 1;
    if (max_val == 0) mask = 0;
    else {
        while (mask <= max_val) mask <<= 1;
        mask >>= 1;
    }

    vector<long long> current = b;
    while (mask > 0) {
        vector<long long> tmp;
        for (long long e : current) {
            if ((e & mask) != 0) {
                tmp.push_back(e);
            }
        }
        if (tmp.size() >= k) {
            current = tmp;
        }
        mask >>= 1;
    }

    if (current.size() < k) {
        cout << 0 << endl;
    } else {
        long long ans = -1;
        for (long long e : current) {
            ans &= e;
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
// End of Code
