#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

static int ans = 100;
static vector<pair<int, int>> balls;
static int N;
static vector<bool> taken;

void solve() {
    for (int add = 1; add < N; add++) {
        taken.assign(N, false);
        int p = balls[add].first - balls[0].first;
        int q = balls[add].second - balls[0].second; // Differences
        ans = min(ans, check(p, q));
    }
}

int check(int p, int q) {
    int ret = 0;
    while (true) {
        bool added = false;
        int start = 0;
        int x = -1;
        int y = -1; // Coordinates that we want next
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    ans = N;
    balls.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> balls[i].first >> balls[i].second;
    }
    sort(balls.begin(), balls.end());

    solve();

    for (auto &ball : balls) {
        swap(ball.first, ball.second);
    }
    sort(balls.begin(), balls.end());

    solve();

    cout << ans << endl;

    return 0;
}

// End of Code
