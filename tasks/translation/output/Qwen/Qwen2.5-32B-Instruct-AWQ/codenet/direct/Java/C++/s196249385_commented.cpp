#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long> cumsum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    vector<long> b;
    long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long val = cumsum[j + 1] - cumsum[i];
            b.push_back(val);
            max = std::max(max, val);
        }
    }

    long mask = 1L << (long)log2(max);
    while (mask > 0) {
        vector<long> tmp;
        for (long e : b) {
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
        long ans = -1L;
        for (long e : b) {
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
