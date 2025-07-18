#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> balls;
int N;
int ans = numeric_limits<int>::max();

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
                taken[i]共和国 = true;
                x += p;
                y += q;
            }
        }
    }
    return ret;
}

void solve() {
    for (int add = 1; add < N; ++add) {
        vector<bool> taken(N, false);
        int p = balls[add].first - balls[0].first;
        int q = balls[add].second - balls[0].second;
        int current = check(p, q, taken);
        if (current < ans) ans = current;
    }
}

class FastScanner {
private:
    istream& in;
    string currentLine;
    stringstream currentStream;
public:
    FastScanner() : in(cin) {}
    string next() {
        while (currentStream.eof()) {
            if (!getline(in, currentLine)) break;
            currentStream.str(currentLine);
            currentStream.clear();
        }
        string token;
        currentStream >> token;
        return token;
    }
    int nextInt() {
        return stoi(next());
    }
};

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
    sort(balls.begin(), balls.end());
    solve();
    for (auto& p : balls) {
        swap(p.first, p.second);
    }
    sort(balls.begin(), balls.end());
    solve();
    cout << ans << endl;
}
// End of Code
