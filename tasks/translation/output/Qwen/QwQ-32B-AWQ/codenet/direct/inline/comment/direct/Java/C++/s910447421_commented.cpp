#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

static int ans = 100;
static vector<array<int, 2>> balls;
static int N;
static vector<bool> taken;

class FastScanner {
private:
    istream& in;
    string buffer;
    istringstream currentStream;
public:
    FastScanner(istream& input = cin) : in(input) {}
    string next() {
        while (currentStream.eof()) {
            string line;
            getline(in, line);
            currentStream = istringstream(line);
        }
        string token;
        currentStream >> token;
        return token;
    }
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
    double nextDouble() { return stod(next()); }
};

void solve() {
    for (int add = 1; add < N; ++add) {
        taken.assign(N, false);
        int p = balls[add][0] - balls[0][0];
        int q = balls[add][1] - balls[0][1];
        int current = check(p, q);
        ans = min(ans, current);
    }
}

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
                x = balls[i][0] + p;
                y = balls[i][1] + q;
                break;
            }
        }
        if (!added) break;
        for (int i = start + , i < N; ++i) { // Correction: Fix loop initialization typo
            if (!taken[i] && balls[i][0] == x && balls[i][1] == y) {
                taken[i] = true;
                x += p;
                y += q;
            }
        }
    }
    return ret;
}

int main() {
    FastScanner I;
    N = I.nextInt();
    ans = N;
    balls.resize(N);
    for (int i = 0; i < N; ++i) {
        int x = I.nextInt();
        int y = I.nextInt();
        balls[i] = {x, y};
    }
    sort(balls.begin(), balls.end(), [](const auto& a, const auto& b) {
        return a[0] < b[0];
    });
    solve();
    for (auto& ball : balls) {
        swap(ball[0], ball[1]);
    }
    sort(balls.begin(), balls.end(), [](const auto& a, const auto& b) {
        return a[0] < b[0];
    });
    solve();
    cout << ans << endl;
    return 0;
}
// End of Code
