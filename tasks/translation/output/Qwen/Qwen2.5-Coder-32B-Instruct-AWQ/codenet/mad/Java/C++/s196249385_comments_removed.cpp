#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Printer {
    ostream& out;
public:
    Printer(ostream& o) : out(o) {}
    void println(long x) {
        out << x << endl;
    }
    void close() {
        out.flush();
    }
};

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
            long diff = cumsum[j + 1] - cumsum[i];
            b.push_back(diff);
            max = max > diff ? max : diff;
        }
    }

    long mask = 1;
    while (mask <= max) {
        mask <<= 1;
    }
    mask >>= 1;

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

    Printer pr(cout);
    if (b.size() < k) {
        pr.println(0);
    } else {
        long ans = -1L;
        for (long e : b) {
            ans &= e;
        }

        pr.println(ans);
    }
    pr.close();
}

int main() {
    solve();
    return 0;
}
// End of Code
