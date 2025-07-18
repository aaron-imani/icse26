#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Printer {
public:
    Printer(ostream& out) : out(out) {}
    void println(long value) {
        out << value << endl;
    }
    void close() {
        out.flush();
    }
private:
    ostream& out;
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
            b.push_back(cumsum[j + 1] - cumsum[i]);
            max = max > (cumsum[j + 1] - cumsum[i]) ? max : (cumsum[j + 1] - cumsum[i]);
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
