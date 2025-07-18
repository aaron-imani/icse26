#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class FastScanner {
public:
    string next() {
        while (!st.hasMoreTokens()) {
            try {
                st = StringTokenizer(br.readLine());
            } catch (exception& e) {
                throw e;
            }
        }
        return st.nextToken();
    }

    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
    double nextDouble() { return stod(next()); }

private:
    class StringTokenizer {
    public:
        StringTokenizer(string str) : tokens(move(str)), pos(0) {}
        bool hasMoreTokens() const { return pos < tokens.size(); }
        string nextToken() {
            stringstream ss(tokens[pos]);
            string token;
            ss >> token;
            ++pos;
            return token;
        }

    private:
        vector<string> tokens;
        size_t pos;
    };

    StringTokenizer st;
    istream& br;
};

class OutPut {
public:
    template<typename T>
    void pln(T x) { cout << x << endl; }

    template<typename T>
    void p(T x) { cout << x; }
};

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
    FastScanner I(cin);
    OutPut O;
    N = I.nextInt();
    ans = N;
    balls.resize(N);
    for (int i = 0; i < N; i++) {
        balls[i].first = I.nextInt();
        balls[i].second = I.nextInt();
    }
    sort(balls.begin(), balls.end());
    solve();
    for (auto& ball : balls) {
        swap(ball.first, ball.second);
    }
    sort(balls.begin(), balls.end());
    solve();
    O.pln(ans);
}

// End of Code
