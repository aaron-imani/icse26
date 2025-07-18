#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans;
int N;
vector<pair<int, int>> balls;

void solve() {
    for (int add = 1; add < N; ++add) {
        int p = balls[add].first - balls[0].first;
        int q = balls[add].second - balls[0].second;
        vector<bool> taken(N, false);
        int current = check(p, q, taken);
        if (current < ans) ans = current;
    }
}

int check(int p, int q, vector<bool>& taken) {
    int ret = 0;
    while (true) {
        bool added = false;
        int start = 0;
        int x = -1, y = -1;
        for (int i = 0; i < N; ++i) {
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
        for (int i = start + 1; i < N; ++i) {
            if (!taken[i] && balls[i].first == x && balls[i].second == y) {
                taken[i] = true;
                x += p;
                y += q;
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    ans = N;
    balls.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> balls[i].first >> balls[i].second;
    }
    sort(balls.begin(), balls.end());
    solve();
    for (auto& p : balls) swap(p.first, p.second);
    sort(balls.begin(), balls.end());
    solve();
    cout << ans << endl;
    return 0;
}
// End of Code
