#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int ans = 100;
int N;
vector<pair<int, int>> balls;

class FastScanner {
private:
    istream& in;
    string line;
    istringstream stream;
    vector<string> tokens;
    size_t pos;

public:
    FastScanner(istream& in = cin) : in(in), pos(0) {}

    string next() {
        if (pos >= tokens.size()) {
            if (!getline(in, line)) return "";
            tokens.clear();
            stream.str(line);
            stream.clear();
            string token;
            while (stream >> token) {
                tokens.push_back(token);
            }
            pos = 0;
        }
        return tokens[pos++];
    }

    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
    double nextDouble() { return stod(next()); }
};

void solve() {
    for (int add = 1; add < N; add++) {
        vector<bool> taken(N, false);
        int p = balls[add].first - balls[0].first;
        int q = balls[add].second - balls[0].second;
        int current = check(p, q, taken);
        ans = min(ans, current);
    }
}

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

int main() {
    FastScanner I;
    N = I.nextInt();
    ans = N;
    balls.resize(N);
    for (int i = 0; i < N; i++) {
        int x = I.nextInt();
        int y = I.nextInt();
        balls[i] = make_pair(x, y);
    }
    sort(balls.begin(), balls.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    solve();
    for (int i = 0; i < N; i++) {
        swap(balls[i].first, balls[i].second);
    }
    sort(balls.begin(), balls.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    solve();
    cout << ans << endl;
    return 0;
}
// End of Code
