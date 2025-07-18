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
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    vector<long> b(n * (n + 1) / 2);
    long max = 0;
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            b[index++] = cumsum[j + 1] - cumsum[i];
            max = max > (cumsum[j + 1] - cumsum[i]) ? max : (cumsum[j + 1] - cumsum[i]);
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
    solve();
    return 0;
}
// End of Code
