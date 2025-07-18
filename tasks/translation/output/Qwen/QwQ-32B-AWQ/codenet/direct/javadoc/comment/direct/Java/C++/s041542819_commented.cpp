#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

void solve(int a, int b, int q, vector<long long>& s, vector<long long>& t, vector<long long>& queries) {
    for (long long x : queries) {
        auto it_s_upper = lower_bound(s.begin(), s.end(), x + 1);
        int p_s_upper = it_s_upper - s.begin();
        int idx_s_lower = max(0, p_s_upper - 1);
        long long sl = x - s[idx_s_lower];

        auto it_t_upper = lower_bound(t.begin(), t.end(), x + 1);
        int p_t_upper = it_t_upper - t.begin();
        int idx_t_lower = max(0, p_t_upper - 1);
        long long tl = x - t[idx_t_lower];

        auto it_s_lower = lower_bound(s.begin(), s.end(), x);
        int p_s_lower = it_s_lower - s.begin();
        long long sr = s[p_s_lower] - x;

        auto it_t_lower = lower_bound(t.begin(), t.end(), x);
        int p_t_lower = it_t_lower - t.begin();
        long long tr = t[p_t_lower] - x;

        long long candidates[6] = {
            max(sl, tl),
            max(sr, tr),
            2 * sl + tr,
            2 * tl + sr,
            sl + 2 * tr,
            tl + 2 * sr
        };
        long long min_val = *min_element(candidates, candidates + 6);
        cout << min_val << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> all;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string token;
        while (ss >> token) {
            all.push_back(stoll(token));
        }
    }

    auto it = all.begin();
    int a = *it++;
    int b = *it++;
    int q = *it++;

    vector<long long> s(a + 2);
    s[0] = -10000000000LL;
    for (int i = 0; i < a; ++i) {
        s[i + 1] = *it++;
    }
    s[a + 1] = 20000000000LL;

    vector<long long> t(b + 2);
    t[0] = -10000000000LL;
    for (int i = 0; i < b; ++i) {
        t[i + 1] = *it++;
    }
    t[b + 1] = 20000000000LL;

    vector<long long> queries;
    for (int i = 0; i < q; ++i) {
        queries.push_back(*it++);
    }

    solve(a, b, q, s, t, queries);

    return 0;
}
// End of Code
