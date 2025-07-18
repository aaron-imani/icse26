#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Printer {
    ostream& os;
public:
    Printer(ostream& o) : os(o) {}
    template<typename T>
    void println(const T& t) { os << t << endl; }
    void close() { os.flush(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> cumsum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cumsum[i + 1] = cumsum[i] + a[i];
    }

    vector<long long> b;
    long long max_val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long diff = cumsum[j + 1] - cumsum[i];
            b.push_back(diff);
            max_val = max(max_val, diff);
        }
    }

    long long mask = 1LL << 62;
    while (mask > 0) {
        vector<long long> tmp;
        for (long long e : b) {
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
        Printer pr(cout);
        pr.println(0);
    } else {
        long long ans = -1LL;
        for (long long e : b) {
            ans &= e;
        }

        Printer pr(cout);
        pr.println(ans);
    }

    return 0;
}
// End of Code
