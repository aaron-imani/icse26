#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long highestOneBit(long x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return x - (x >> 1);
}

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
    b.reserve(n * (n + 1) / 2);
    long max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            b.push_back(cumsum[j + 1] - cumsum[i]);
            max = std::max(max, cumsum[j + 1] - cumsum[i]);
        }
    }

    long mask = highestOneBit(max);
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
