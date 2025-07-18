#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000006;
const ll MOD = 1e9 + 7;

class Helper {
public:
    Helper(ll mod, int maxn) : MOD(mod), MAXN(maxn) {}

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    ll max(ll a, ll b) {
        return a > b ? a : b;
    }

    ll min(ll a, ll b) {
        return a < b ? a : b;
    }

    ll sum(vector<ll>& ar) {
        ll sum = 0;
        for (ll itr : ar) sum += itr;
        return sum;
    }

    void shuffle(vector<int>& ar) {
        random_shuffle(ar.begin(), ar.end());
    }

    void shuffle(vector<ll>& ar) {
        random_shuffle(ar.begin(), ar.end());
    }

    void reverse(vector<int>& ar) {
        reverse(ar.begin(), ar.end());
    }

    void reverse(vector<ll>& ar) {
        reverse(ar.begin(), ar.end());
    }

    ll pow(ll base, ll exp, ll MOD) {
        base %= MOD;
        ll ret = 1;
        while (exp > 0) {
            if (exp & 1) ret = ret * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return ret;
    }

    void initIO(istream& is, ostream& os) {
        cin.rdbuf(is.rdbuf());
        cout.rdbuf(os.rdbuf());
    }

    string next() {
        string s;
        cin >> s;
        return s;
    }

    int nextInt() {
        int x;
        cin >> x;
        return x;
    }

    ll nextLong() {
        ll x;
        cin >> x;
        return x;
    }

    void print(const string& a) {
        cout << a;
    }

    void printsp(const string& a) {
        print(a);
        print(" ");
    }

    void println() {
        cout << "\n";
    }

    void println(const string& a) {
        print(a);
        println();
    }

    void flush() {
        cout.flush();
    }

private:
    ll MOD;
    int MAXN;
};

class Solver {
public:
    Solver() {
        hp = Helper(MOD, MAXN);
        hp.initIO(cin, cout);
    }

    void solve() {
        int tc = TESTCASES ? hp.nextInt() : 1;
        for (int tce = 1; tce <= tc; ++tce) solve(tce);
    }

    bool TESTCASES = false;

    void solve(int tc) {
        int N = hp.nextInt();
        ll K = hp.nextLong();
        vector<int> A(N);
        for (int i = 0; i < N; ++i) A[i] = hp.nextInt();

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
            hp.println(to_string(straight[K] + 1));
        } else {
            K -= straight.size();
            hp.println(to_string(cycle[K % cycle.size()] + 1));
        }
    }

private:
    Helper hp;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solver solver;
    solver.solve();
    return 0;
}
// End of Code
