#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int ans = 100;
int N;
vector<pair<int, int>> balls;

class FastScanner {
private:
    vector<string> tokens;
    string current_line;

public:
    FastScanner() {}

    string next() {
        while (tokens.empty()) {
            if (!getline(cin, current_line)) {
                throw runtime_error("No more input");
            }
            stringstream ss(current_line);
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
        }
        string result = tokens.front();
        tokens.erase(tokens.begin());
        return result;
    }

    int nextInt() {
        return stoi(next());
    }
};

class OutPut {
public:
    void pln(int x) {
        cout << x << endl;
    }
};

void solve() {
    for (int add = 1; add < N; add++) {
        vector<bool> taken(N, false);
        int p = balls[add].first - balls[0].first;
        int q = balls[add].second - balls[0].second;
        ans = min(ans, check(p, q, taken));
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
    OutPut O;

    N = I.nextInt();
    ans = N;
    balls.resize(N);
    for (int i = 0; i < N; i++) {
        int x = I.nextInt();
        int y = I.nextInt();
        balls[i] = {x, y};
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

    O.pln(ans);

    return 0;
}
// End of Code
