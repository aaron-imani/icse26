#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Helper {
public:
    long long MOD;
    int MAXN;
    istream* in;
    ostream* out;

    Helper(long long mod, int maxn) : MOD(mod), MAXN(maxn), in(nullptr), out(nullptr) {}

    void initIO(istream& inputStream, ostream& outputStream) {
        in = &inputStream;
        out = &outputStream;
    }

    int nextInt() {
        int val;
        (*in) >> val;
        return val;
    }

    long long nextLong() {
        long long val;
        (*in) >> val;
        return val;
    }

    void println(int val) {
        (*out) << val << '\n';
    }

    void println(long long val) {
        (*out) << val << '\n';
    }

    void flush() {
        out->flush();
    }
};

class Solver {
private:
    Helper hp;
    const int MAXN = 1000006;
    const long long MOD = 1e9 + 7;

public:
    Solver() : hp(MOD, MAXN) {
        hp.initIO(cin, cout);
    }

    void solve() {
        int tc = (false ? hp.nextInt() : 1);
        for (int tce = 1; tce <= tc; ++tce) {
            solve(tce);
        }
        hp.flush();
    }

    void solve(int tc) {
        int N = hp.nextInt();
        long long K = hp.nextLong();
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            A[i] = hp.nextInt();
        }

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
            hp.println(cycle[K % cycle.size()] + 1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solver solver;
    solver.solve();
    return 0;
}
// End of Code
