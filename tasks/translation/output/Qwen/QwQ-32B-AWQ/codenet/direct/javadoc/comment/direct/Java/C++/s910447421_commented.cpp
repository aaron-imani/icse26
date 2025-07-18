#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> balls;
int N;
int ans = 100;

int check(int p, int q, vector<bool>& taken) {
    int ret = 0;
    while (true) {
        bool added = false;
        int start = 0;
        int x = -1, y = -1;
        for (int i = 0; i < N; i++) {
            if (!taken[i]) {
                added = true;
                ret++;
                start = i;
                taken[i] = true;
                x = balls[i].first + p;
                y = balls[i].second + q;
                break;
            }
        }
        if (!added) break;
        for (int i = start + 1; i < N; i++) {
            if (balls[i].first == x && balls[i].second == y) {
                taken[i] = true;
                x += p;
                y += q;
            }
        }
    }
    return ret;
}

void solve() {
    for (int add = 1; add < N; add++) {
        vector<bool> taken(N, false);
        int p = balls[add].first - balls[0].first;
        int q = balls[add].second - balls[0].second;
        int currentCount = check(p, q, taken);
        ans = min(ans, currentCount);
    }
}

int main() {
    cin >> N;
    ans = N;
    balls.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        balls[i] = {x, y};
    }
    sort(balls.begin(), balls.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    solve();
    // Flip coordinates and sort again
    for (auto& p : balls) {
        swap(p.first, p.second);
    }
    sort(balls.begin(), balls.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    solve();
    cout << ans << endl;
}
// End of Code
