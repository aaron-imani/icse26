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

    ll sum(vector<ll> ar) {
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
        in = &is;
        out = &os;
    }

    string next() {
        string s;
        *in >> s;
        return s;
    }

    int nextInt() {
        return stoi(next());
    }

    ll nextLong() {
        return stoll(next());
    }

    vector<int> getIntArray(int size) {
        vector<int> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = nextInt();
        return ar;
    }

    vector<ll> getLongArray(int size) {
        vector<ll> ar(size);
        for (int i = 0; i < size; ++i) ar[i] = nextLong();
        return ar;
    }

    void print(const string& a) {
        *out << a;
    }

    void printsp(const string& a) {
        print(a);
        print(" ");
    }

    void println() {
        *out << "\n";
    }

    void println(const string& a) {
        print(a);
        println();
    }

    void flush() {
        out->flush();
    }

private:
    ll MOD;
    int MAXN;
    istream* in;
    ostream* out;
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
        hp.flush();
    }

private:
    Helper hp;
    bool TESTCASES = false;

    void solve(int tc) {
        int N = hp.nextInt();
        ll K = hp.nextLong();
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
            hp.println(to_string(straight[K] + 1));
        } else {
            K -= straight.size();
            hp.println(to_string(cycle[K % cycle.size()] + 1));
        }
    }
};

int main() {
    Solver solver;
    solver.solve();
    return 0;
}
// End of Code
