#include <iostream>
#include <vector>
using namespace std;

class Helper {
public:
    Helper() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }

    long long nextLong() {
        long long x;
        cin >> x;
        return x;
    }

    vector<int> getIntArray(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; ++i) cin >> res[i];
        return res;
    }

    void print(const string& s) {
        cout << s;
    }

    void println(const string& s) {
        cout << s << '\n';
    }

    void println(int x) {
        cout << x << '\n';
    }

    void flush() {
        cout << flush;
    }
};

class Solver {
public:
    Helper hp;
    const int MAXN = 1000006;
    const long long MOD = 1e9 + 7;

    bool TESTCASES = false;

    void solve() {
        int tc = TESTCASES ? hp.nextInt() : 1;
        for (int tce = 1; tce <= tc; ++tce) solve(tce);
        hp.flush();
    }

    void solve(int tc) {
        int N = hp.nextInt();
        long long K = hp.nextLong();
        vector<int> A = hp.getIntArray(N);

        vector<int> straight, cycle;
        vector<bool> vis(N, false);
        int curr = 0;
        while (!vis[curr]) {
            vis[curr] = true;
            curr = A[curr] - 1;
        }

        int st = 0;
        while (st != curr) {
            straight.push_back(st);
            st = A[st] - 1;
        }

        cycle.push_back(curr);
        curr = A[curr] - 1;
        while (curr != cycle[0]) {
            cycle.push_back(curr);
            curr = A[curr] - 1;
        }

        if (K < straight.size()) {
            hp.println(straight[K] + 1);
        } else {
            K -= straight.size();
            int idx = (int)(K % cycle.size());
            hp.println(cycle[idx] + 1);
        }
    }
};

int main() {
    Solver().solve();
    return 0;
}
// End of Code
