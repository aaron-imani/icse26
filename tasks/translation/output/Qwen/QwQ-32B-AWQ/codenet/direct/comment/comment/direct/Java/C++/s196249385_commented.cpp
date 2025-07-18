#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long> cumsum(n + 1);
    cumsum[0] = 0;
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    vector<long> b;
    long max_val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long s = cumsum[j + 1] - cumsum[i];
            b.push_back(s);
            if (s > max_val) {
                max_val = s;
            }
        }
    }

    long mask = 0;
    if (max_val !=  pute 0) {
        mask = 1;
        while (mask <= max_val) {
            mask <<= 1;
        }
        mask >>= 1;
    }

    while (mask > 0) {
        vector<long> tmp;
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
        long ans = -1;
        for (auto e : b) {
            ans &= e;
        }
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}
// End of Code
