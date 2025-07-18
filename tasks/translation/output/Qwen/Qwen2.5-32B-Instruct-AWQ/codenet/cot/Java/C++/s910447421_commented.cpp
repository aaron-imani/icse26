#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

static int ans = 100;
static vector<vector<int>> balls;
static int N;
static vector<bool> taken;

int min(int a, int b) { return std::min(a, b); }

void solve() {
    for (int add = 1; add < N; add++) {
        taken = vector<bool>(N, false);
        int p = balls[add][0] - balls[0][0];
        int q = balls[add][1] - balls[0][1]; //Differences
        ans = min(ans, check(p, q));
    }
}

int check(int p, int q) {
    int ret = 0;
    while (true) {
        bool added = false;
        int start = 0;
        int x = -1;
        int y = -1; //Coordinates that we want next
        for (int i = 0; i < N; i++) {
            if (!taken[i]) {
                added = true;
                ret++;
                start = i;
                taken[i] = true;
                x = balls[i][0] + p;
                y = balls[i][1] + q;
                break;
            }
        }
        if (!added) break;
        for (int i = start + 1; i < N; i++) {
            if (balls[i][0] == x && balls[i][1] == y) {
                taken[i] = true;
                x += p;
                y += q;
            }
        }
    }
    return ret;
}

int main() {
    /*Fixate two coordinates in ordered pairs and extend same arithmetic difference for as
     * long as possible (sort coordinates first)
     * Make connected graphs of coordinates that can be achieved with set p and q values
     * */
    cin >> N;
    ans = N;
    balls = vector<vector<int>>(N, vector<int>(2));
    for (int i = 0; i < N; i++) {
        cin >> balls[i][0];
        cin >> balls[i][1];
    }
    sort(balls.begin(), balls.end());
    solve();
    for (int i = 0; i < N; i++) {
        int x = balls[i][0];
        int y = balls[i][1];
        balls[i][0] = y;
        balls[i][1] = x;
    }
    sort(balls.begin(), balls.end());
    solve();
    cout << ans << endl;
    return 0;
}
// End of Code
