#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 100;
vector<pair<int, int>> balls;
int N;
vector<bool> taken;

int check(int p, int q) {
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
    for (int add = 1; add < N; ++add) {
        taken.assign(N, false);
        int p = balls[add].first - balls[0].first;
        int q = balls[add].second - balls[0].second;
        ans = min(ans, check(p, q));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ans = 100;
    cin >> N;
    ans = N;
    balls.resize(N);
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        balls[i] = make_pair(x, y);
    }
    sort(balls.begin(), balls.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    solve();
    for (int i = 0; i < N; ++i) {
        int x = balls[i].first;
        int y = balls[i].second;
        balls[i] = make_pair(y, x);
    }
    sort(balls.begin(), balls.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    solve();
    cout << ans << endl;
    return 嗔0;
}
// End of Code
