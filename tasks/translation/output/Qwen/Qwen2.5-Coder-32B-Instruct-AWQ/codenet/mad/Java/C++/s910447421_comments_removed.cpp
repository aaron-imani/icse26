// End of Code
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int ans = 100;
vector<vector<int>> balls;
int N;
vector<bool> taken;

int custom_min(int a, int b) { return (a < b) ? a : b; }

void solve() {
    for (int add = 1; add < N; add++) {
        taken.assign(N, false);
        int p = balls[add][0] - balls[0][0];
        int q = balls[add][1] - balls[0][1];

        ans = custom_min(ans, check(p, q));
    }
}

int check(int p, int q) {
    int ret = 0;
    while (true) {
        bool added = false;
        int start = 0;
        int x = -1;
        int y = -1;

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

class FastScanner {
    istream& in;
    string str;
    vector<string> vec;
    size_t pos;

public:
    FastScanner(istream& in) : in(in), pos(0) {}

    string next() {
        while (pos >= vec.size()) {
            pos = 0;
            getline(in, str);
            stringstream ss(str);
            string token;
            vec.clear();
            while (ss >> token) {
                vec.push_back(token);
            }
        }
        return vec[pos++];
    }

    int nextInt() { return stoi(next()); }

    long long nextLong() { return stoll(next()); }

    double nextDouble() { return stod(next()); }
};

class OutPut {
public:
    void pln(int x) { cout << x << endl; }
    void pln(long long x) { cout << x << endl; }
    void pln(double x) { cout << x << endl; }
    void pln(bool x) { cout << (x ? "true" : "false") << endl; }
    void pln(const string& x) { cout << x << endl; }
    void pln(char x) { cout << x << endl; }
    void p(int x) { cout << x; }
    void p(long long x) { cout << x; }
    void p(double x) { cout << x; }
    void p(bool x) { cout << (x ? "true" : "false"); }
    void p(const string& x) { cout << x; }
    void p(char x) { cout << x; }
};

int main() {
    FastScanner I(cin);
    OutPut O;

    N = I.nextInt();
    ans = N;
    balls.resize(N, vector<int>(2));
    for (int i = 0; i < N; i++) {
        balls[i][0] = I.nextInt();
        balls[i][1] = I.nextInt();
    }
    sort(balls.begin(), balls.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    solve();
    for (int i = 0; i < N; i++) {
        int x = balls[i][0];
        int y = balls[i][1];
        balls[i][0] = y;
        balls[i][1] = x;
    }
    sort(balls.begin(), balls.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    solve();
    O.pln(ans);

    return 0;
}
// End of Code
