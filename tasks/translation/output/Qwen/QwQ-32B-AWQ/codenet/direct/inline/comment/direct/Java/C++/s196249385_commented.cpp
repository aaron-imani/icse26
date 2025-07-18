#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> cumsum(n + 1);
    for (int i = 0; i < n; ++i) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    vector<long long> b;
    long long max_val = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            long long sum = cumsum[j + 1] - cumsum[i];
            b.push_back(sum);
            if (sum > max_val) {
                max_val = sum;
            }
        }
    }

    long long mask = 1;
    while (mask <= max_val) {
        mask <<= 1;
    }
    mask >>= 1;

    while (mask > 0) {
        vector<long long> tmp;
        for (auto e : b) {
            if ((e & mask) != 0) {
                tmp.push_back(e);
            }
        }
        if (tmp.size() >= k) {
            b = tmp;
        }
        mask >>= 1;
    }

    if (b.size() < k) {
        cout << 0 << endl;
    } else {
        long long ans = -1;
        for (auto e : b) {
            ans &= e;
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
// End of Code
