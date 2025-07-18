#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(const vector<pair<int, int>>& balls, int p, int q, int N) {
    vector<bool> taken(N, false);
    int ret = 0;
    while (true) {
        bool added = false;
        int start = 0;
        int x = -1, y = -1;
        for (int i = 0; i < N; ++i) {
            if (!taken[i]) {
                added = true;
                ret++;
                taken[i] = true;
                start = i;
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

void solve(const vector<pair<int, int>>& balls, int N, int& ans) {
    for (int add = 1; add < N; ++add) {
        int p = balls[add].first - balls[0].first;
        int q = balls[add].second - balls[0].second;
        int current = check(balls, p, q, N);
        if (current < ans) {
            ans = current;
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> balls(N);
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        balls[i] = make_pair(x, y);
    }
    int ans = N;
    sort(balls.begin(), balls.end());
    solve(balls, N, ans);
    for (auto& p : balls) {
        swap(p.first, p.second);
    }
    sort(balls.begin(), balls.end());
    solve(balls, N, ans);
    cout << ans << endl;
}
// End of Code
