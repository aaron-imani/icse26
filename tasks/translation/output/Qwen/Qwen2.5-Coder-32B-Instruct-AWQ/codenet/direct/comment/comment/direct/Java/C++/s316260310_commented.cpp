#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1000006;
const ll MOD = 1e9 + 7;

class Helper {
public:
    Helper(ll mod, int maxn) : MOD(mod), MAXN(maxn) {}

    ll getFactorial(int n) {
        if (factorial.empty()) setFactorial();
        return factorial[n];
    }

    ll ncr(int n, int r) {
        if (r > n) return 0;
        if (factorial.empty()) setFactorial();
        ll numerator = factorial[n];
        ll denominator = (factorial[r] * factorial[n - r]) % MOD;
        return (numerator * pow(denominator, MOD - 2, MOD)) % MOD;
    }

    vector<ll> getLongArray(int size) {
        vector<ll> ar(size);
        for (int i = 0; i < size; ++i) cin >> ar[i];
        return ar;
    }

    vector<int> getIntArray(int size) {
        vector<int> ar(size);
        for (int i = 0; i < size; ++i) cin >> ar[i];
        return ar;
    }

    vector<string> getStringArray(int size) {
        vector<string> ar(size);
        for (int i = 0; i < size; ++i) cin >> ar[i];
        return ar;
    }

    string joinElements(const vector<ll>& ar) {
        stringstream ss;
        for (size_t i = 0; i < ar.size(); ++i) {
            ss << ar[i];
            if (i < ar.size() - 1) ss << " ";
        }
        return ss.str();
    }

    string joinElements(const vector<int>& ar) {
        stringstream ss;
        for (size_t i = 0; i < ar.size(); ++i) {
            ss << ar[i];
            if (i < ar.size() - 1) ss << " ";
        }
        return ss.str();
    }

    string joinElements(const vector<string>& ar) {
        stringstream ss;
        for (size_t i = 0; i < ar.size(); ++i) {
            ss << ar[i];
            if (i < ar.size() - 1) ss << " ";
        }
        return ss.str();
    }

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    ll max(const vector<ll>& ar) {
        return *max_element(ar.begin(), ar.end());
    }

    int max(const vector<int>& ar) {
        return *max_element(ar.begin(), ar.end());
    }

    ll min(const vector<ll>& ar) {
        return *min_element(ar.begin(), ar.end());
    }

    int min(const vector<int>& ar) {
        return *min_element(ar.begin(), ar.end());
    }

    ll sum(const vector<ll>& ar) {
        return accumulate(ar.begin(), ar.end(), 0LL);
    }

    ll sum(const vector<int>& ar) {
        return accumulate(ar.begin(), ar.end(), 0LL);
    }

    void shuffle(vector<int>& ar) {
        random_shuffle(ar.begin(), ar.end());
    }

    void shuffle(vector<ll>& ar) {
        random_shuffle(ar.begin(), ar.end());
    }

    void reverse(vector<int>& ar) {
        ::reverse(ar.begin(), ar.end());
    }

    void reverse(vector<ll>& ar) {
        ::reverse(ar.begin(), ar.end());
    }

    ll pow(ll base, ll exp, ll MOD) {
        base %= MOD;
        ll ret = 1;
        while (exp > 0) {
            if (exp & 1) ret = (ret * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return ret;
    }

private:
    ll MOD;
    int MAXN;
    vector<ll> factorial;

    void setFactorial() {
        factorial.resize(MAXN);
        factorial[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }
    }
};

class Solver {
public:
    Solver() : hp(MOD, MAXN) {}

    void solve() {
        int tc = TESTCASES ? hp.nextInt() : 1;
        for (int tce = 1; tce <= tc; ++tce) solve(tce);
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
            cout << straight[K] + 1 << "\n";
        } else {
            K -= straight.size();
            cout << cycle[K % cycle.size()] + 1 << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solver solver;
    solver.solve();
    return 0;
}
// End of Code
