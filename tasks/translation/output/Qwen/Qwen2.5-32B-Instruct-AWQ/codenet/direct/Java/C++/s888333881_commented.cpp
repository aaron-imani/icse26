#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <sstream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <ctime>
#include <complex>
#include <numeric>
#include <functional>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i > (b); --i)
#define debug(x) cerr << #x << " = " << x << endl

const int INF = 1e9;
const ll INFL = 1e18;
const ll e97 = 1e9 + 7;

template<typename T>
void fill_parent(T& ob) {
    for (int i = 0; i < ob.size(); i++) ob[i] = i;
}

template<typename T>
int get_root_uf(T& parent, int index) {
    if (parent[index] == index) return index;
    int root = get_root_uf(parent, parent[index]);
    parent[index] = root;
    return root;
}

template<typename T>
bool is_same_uf(T& parent, int x, int y) {
    if (get_root_uf(parent, x) == get_root_uf(parent, y)) return true;
    else return false;
}

template<typename T>
void unite_uf(T& parent, int receiver, int attacker) {
    parent[get_root_uf(parent, attacker)] = get_root_uf(parent, receiver);
}

int abs(int a) { return (a >= 0) ? a : -a; }
ll abs(ll a) { return (a >= 0) ? a : -a; }
double abs(double a) { return (a >= 0) ? a : -a; }

int min(int a, int b) { return (a > b) ? b : a; }
ll min(ll a, ll b) { return (a > b) ? b : a; }
double min(double a, double b) { return (a > b) ? b : a; }

int max(int a, int b) { return (a > b) ? a : b; }
ll max(ll a, ll b) { return (a > b) ? a : b; }
double max(double a, double b) { return (a > b) ? a : b; }

int minN(int... ins) {
    int min = ins[0];
    for (int i = 1; i < ins.length; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

int maxN(int... ins) {
    int max = ins[0];
    for (int i = 1; i < ins.length; i++) {
        if (ins[i] > max) max = ins[i];
    }
    return max;
}

ll minN(ll... ins) {
    ll min = ins[0];
    for (int i = 1; i < ins.length; i++) {
        if (ins[i] < min) min = ins[i];
    }
    return min;
}

ll maxN(ll... ins) {
    ll max = ins[0];
    for (int i = 1; i < ins.length; i++) {
        if (ins[i] > max) max = ins[i];
    }
    return max;
}

int minExAd(int* dt, int ad) {
    int min = INF;
    for (int i = 0; i < dt.length; i++) {
        if ((i != ad) && (dt[i] < min)) min = dt[i];
    }
    return min;
}

ll minExAd(ll* dt, int ad) {
    ll min = INFL;
    for (int i = 0; i < dt.length; i++) {
        if ((i != ad) && (dt[i] < min)) min = dt[i];
    }
    return min;
}

int minExVal(int* dt, int ex_val) {
    int min = INF;
    for (int i = 0; i < dt.length; i++) {
        if ((dt[i] != ex_val) && (dt[i] < min)) min = dt[i];
    }
    return min;
}

ll minExVal(ll* dt, ll ex_val) {
    ll min = INFL;
    for (int i = 0; i < dt.length; i++) {
        if ((dt[i] != ex_val) && (dt[i] < min)) min = dt[i];
    }
    return min;
}

int maxExAd(int* dt, int ad) {
    int max = -INF;
    for (int i = 0; i < dt.length; i++) {
        if ((i != ad) && (dt[i] > max)) max = dt[i];
    }
    return max;
}

ll maxExAd(ll* dt, int ad) {
    ll max = -INFL;
    for (int i = 0; i < dt.length; i++) {
        if ((i != ad) && (dt[i] > max)) max = dt[i];
    }
    return max;
}

int maxExVal(int* dt, int ex_val) {
    int max = -INF;
    for (int i = 0; i < dt.length; i++) {
        if ((dt[i] != ex_val) && (dt[i] > max)) max = dt[i];
    }
    return max;
}

ll maxExVal(ll* dt, ll ex_val) {
    ll max = -INFL;
    for (int i = 0; i < dt.length; i++) {
        if ((dt[i] != ex_val) && (dt[i] > max)) max = dt[i];
    }
    return max;
}

int sumA(int* dt) {
    int sum = 0;
    for (int e : dt) sum += e;
    return sum;
}

ll sumA(ll* dt) {
    ll sum = 0;
    for (ll e : dt) sum += e;
    return sum;
}

int sumA(vector<int>& dt) {
    int sum = 0;
    for (int e : dt) sum += e;
    return sum;
}

bool same3(ll a, ll b, ll c) {
    if (a != b) return false;
    if (b != c) return false;
    if (c != a) return false;
    return true;
}

bool dif3(ll a, ll b, ll c) {
    if (a == b) return false;
    if (b == c) return false;
    if (c == a) return false;
    return true;
}

bool triangle_inequality(int a, int b, int c) {
    if ((a + b) < c) return false;
    if ((b + c) < a) return false;
    if ((c + a) < b) return false;
    return true;
}

double hypod(double a, double b) {
    return sqrt(a * a + b * b);
}

ll factorial(int n) {
    ll ans = 1;
    for (ll i = n; i > 0; i--) ans *= i;
    return ans;
}

ll facP(int n, ll p) {
    ll ans = 1;
    for (ll i = n; i > 0; i--) {
        ans *= i;
        ans %= p;
    }
    return ans;
}

ll lcm(ll m, ll n) {
    ll ans = m / gcd(m, n);
    ans *= n;
    return ans;
}

ll gcd(ll m, ll n) {
    if (m < n) return gcd(n, m);
    if (n == 0) return m;
    return gcd(n, m % n);
}

bool is_prime(ll a) {
    if (a == 1) return false;
    for (ll i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

ll modinv(ll a, ll p) {
    ll b = p, u = 1, v = 0;
    while (b > 0) {
        ll t = a / b;
        ll pe = a % b;
        a = b;
        b = pe;
        pe = u - t * v;
        u = v;
        v = pe;
    }
    u %= p;
    if (u < 0) u += p;
    return u;
}

int pow(int n, int k) {
    int ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

ll pow(ll n, int k) {
    ll ans = 1;
    for (int i = 0; i < k; i++) ans *= n;
    return ans;
}

int pow2(int in) { return in * in; }
ll pow2(ll in) { return in * in; }
double pow2(double in) { return in * in; }

int getDigit2(ll num) {
    ll cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf = (1LL << d);
    }
    return d; // numはd桁の数で、2^dより小さい
}

int getDigit10(ll num) {
    ll cf = 1;
    int d = 0;
    while (num >= cf) {
        d++;
        cf *= 10;
    }
    return d; // numはd桁の数で、10^dより小さい
}

bool isINF(int in) {
    if (((ll)in * 20) > INF) return true;
    else return false;
}

bool isINFL(ll in) {
    if ((in * 10000) > INFL) return true;
    else return false;
}

ll pow10E97(ll ob, ll soeji, ll p) {
    if (ob == 0) return 0;
    if (soeji == 0) return 1;
    if (soeji == 2) return (ob * ob) % p;

    int d = getDigit2(soeji);
    vector<ll> ob_pow_2pow(d);

    ob_pow_2pow[0] = ob;
    for (int i = 1; i < d; i++) ob_pow_2pow[i] = (ob_pow_2pow[i - 1] * ob_pow_2pow[i - 1]) % p;

    ll ans = 1;
    for (int i = d - 1; i >= 0; i--) {
        if (soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

ll flag(ll pos) { return (1LL << pos); }
bool isFlaged(int bit, int pos) {
    if ((bit & (1 << pos)) > 0) return true;
    else return false;
}

bool isFlaged(ll bit, int pos) {
    if ((bit & (1LL << pos)) > 0) return true;
    else return false;
}

int deflag(int bit, int pos) { return bit & ~(1 << pos); }
int countFlaged(int bit) {
    int ans = 0;
    for (int i = 0; i < getDigit2(bit); i++) {
        if ((bit & (1 << i)) > 0) ans++;
    }
    return ans;
}

int countFlaged(ll bit) {
    int ans = 0;
    for (ll i = 0; i < getDigit2(bit); i++) {
        if ((bit & (1LL << i)) > 0) ans++;
    }
    return ans;
}

void showflag(int bit) {
    for (int i = 0; i < getDigit2(bit); i++) {
        if (isFlaged(bit, i)) cout << "O";
        else cout << ".";
    }
    cout << endl;
}

int biSearch(vector<int>& dt, int target) {
    int left = 0, right = dt.size() - 1;
    int mid = -1;
    while (left <= right) {
        mid = (right + left) / 2;
        if (dt[mid] == target) return mid;
        if (dt[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int biSearchMax(vector<ll>& dt, ll target) {
    int left = -1, right = dt.size();
    int mid = -1;

    while ((right - left) > 1) {
        mid = left + (right - left) / 2;
        if (dt[mid] <= target) left = mid;
        else right = mid;
    }
    return left; // target未満の最大のaddress
}

int biSearchMaxAL(vector<int>& dt, ll target) {
    int left = -1, right = dt.size();
    int mid = -1;

    while ((right - left) > 1) {
        mid = left + (right - left) / 2;
        if (dt[mid] <= target) left = mid;
        else right = mid;
    }
    return left; // target以下の最大のaddress
}

void fill(bool* ob, bool res) { for (int i = 0; i < ob.length; i++) ob[i] = res; }
void fill(int* ob, int res) { for (int i = 0; i < ob.length; i++) ob[i] = res; }
void fill(ll* ob, ll res) { for (int i = 0; i < ob.length; i++) ob[i] = res; }
void fill(char* ob, char res) { for (int i = 0; i < ob.length; i++) ob[i] = res; }
void fill(double* ob, double res) { for (int i = 0; i < ob.length; i++) ob[i] = res; }
void fill(bool** ob, bool res) { for (int i = 0; i < ob.length; i++) for (int j = 0; j < ob[0].length; j++) ob[i][j] = res; }
void fill(int** ob, int res) { for (int i = 0; i < ob.length; i++) for (int j = 0; j < ob[0].length; j++) ob[i][j] = res; }
void fill(ll** ob, ll res) { for (int i = 0; i < ob.length; i++) for (int j = 0; j < ob[0].length; j++) ob[i][j] = res; }
void fill(char** ob, char res) { for (int i = 0; i < ob.length; i++) for (int j = 0; j < ob[0].length; j++) ob[i][j] = res; }
void fill(double** ob, double res) { for (int i = 0; i < ob.length; i++) for (int j = 0; j < ob[0].length; j++) ob[i][j] = res; }
void fill(int*** ob, int res) { for (int i = 0; i < ob.length; i++) for (int j = 0; j < ob[0].length; j++) for (int k = 0; k < ob[0][0].length; k++) ob[i][j][k] = res; }
void fill(ll*** ob, ll res) { for (int i = 0; i < ob.length; i++) for (int j = 0; j < ob[0].length; j++) for (int k = 0; k < ob[0][0].length; k++) ob[i][j][k] = res; }

class FastScanner {
private:
    ifstream in;
    vector<char> buffer;
    int ptr = 0;
    int buflen = 0;

    bool hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            in.read(buffer.data(), buffer.size());
            buflen = in.gcount();
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }

    int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1; }
    static bool isPrintableChar(int c) { return 33 <= c && c <= 126; }

public:
    FastScanner() : in(cin.rdbuf()), buffer(1024) {}

    bool hasNext() { while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte(); }
    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string sb;
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.push_back(b);
            b = readByte();
        }
        return sb;
    }

    ll nexL() {
        if (!hasNext()) throw runtime_error("No more input");
        ll n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw runtime_error("Invalid number format");
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b) || b == ':') {
                return minus ? -n : n;
            } else {
                throw runtime_error("Invalid number format");
            }
            b = readByte();
        }
    }

    int nexI() {
        ll nl = nexL();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Number out of range");
        return (int) nl;
    }

    double nexD() { return stod(next()); }

    void ni(vector<ll>& array2) {
        for (int i = 0; i < array2.size(); i++) {
            array2[i] = nexL();
        }
        return;
    }

    void ni(vector<int>& array2) {
        for (int i = 0; i < array2.size(); i++) {
            array2[i] = nexI();
        }
        return;
    }

    void ni(vector<int>& as, vector<int>& bs) {
        for (int i = 0; i < as.size(); i++) {
            as[i] = nexI();
            bs[i] = nexI();
        }
        return;
    }

    void ni(vector<ll>& as, vector<ll>& bs) {
        for (int i = 0; i < as.size(); i++) {
            as[i] = nexL();
            bs[i] = nexL();
        }
        return;
    }

    void ni(vector<int>& as, vector<int>& bs, vector<int>& cs) {
        for (int i = 0; i < as.size(); i++) {
            as[i] = nexI();
            bs[i] = nexI();
            cs[i] = nexI();
        }
        return;
    }

    void nisan(vector<vector<int>>& as) {
        for (int i = 0; i < as.size(); i++) {
            for (int j = 0; j < as[0].size(); j++) {
                as[i][j] = nexI();
            }
        }
        return;
    }
};

class Graph0n {
private:
    vector<Node0n> dt;

public:
    Graph0n(int sz) { dt.resize(sz); }
    void add(int vn, int val) { dt[vn].add(val); }
    void add2(int vn, int val) { dt[vn].add(val); dt[val].add(vn); }
    int get(int vn, int index) { return dt[vn].get(index); }
    vector<int> get(int vn) { return dt[vn].getAll(); }
    int sizeOf(int vn) { return dt[vn].size(); }
    void clear() { for (int i = 0; i < dt.size(); i++) dt[i].clear(); }
};

class Node0n {
private:
    vector<int> next_vs;

public:
    void add(int val) { next_vs.push_back(val); }
    int get(int ad) { return next_vs[ad]; }
    vector<int> getAll() { return next_vs; }
    int size() { return next_vs.size(); }
    void clear() { next_vs.clear(); }
};

class Edge {
public:
    int from = -1, v2 = -1;
    ll weight;

    Edge(int vn, ll w) : v2(vn), weight(w) {}
    Edge(int cm, int vn, ll w) : from(cm), v2(vn), weight(w) {}
};

class Edge2 {
public:
    int v2;
    ll cost1, cost2;

    Edge2(int vn, ll w1, ll w2) : v2(vn), cost1(w1), cost2(w2) {}
};

class Comparator_Edge : public std::function<int(Edge, Edge)> {
public:
    int operator()(Edge a, Edge b) {
        if (a.weight > b.weight) return -1;
        else if (a.weight < b.weight) return 1;
        else return b.v2 - a.v2;
    }
};

class V2Comp : public std::function<int(Edge, Edge)> {
public:
    int operator()(Edge a, Edge b) {
        if (a.v2 > b.v2) return -1;
        else if (a.v2 < b.v2) return 1;
        else if (a.weight > b.weight) return -1;
        else if (a.weight < b.weight) return 1;
        else return 0;
    }
};

class antiV2 : public std::function<int(Edge, Edge)> {
public:
    int operator()(Edge a, Edge b) {
        if (a.v2 > b.v2) return 1;
        else if (a.v2 < b.v2) return -1;
        else if (a.weight > b.weight) return -1;
        else if (a.weight < b.weight) return 1;
        else return 0;
    }
};

class Vector {
public:
    int x, y;

    Vector(int sx, int sy) : x(sx), y(sy) {}
};

int main() {
    FastScanner sc;
    FastScanner::ostream out(cout.rdbuf());

    int n = sc.nexI();
    string s = sc.next();
    vector<bool> flaged(n, false);

    ll pop1st = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    ll surp1 = 0;
    for (int i = 0; i < n; i++) {
        surp1 *= 2;
        if (flaged[i]) surp1++;
        surp1 %= (pop1st + 1);
    }

    ll surp9 = 0;
    if (pop1st > 1) {
        for (int i = 0; i < n; i++) {
            surp9 *= 2;
            if (flaged[i]) surp9++;
            surp9 %= (pop1st - 1);
        }
    }

    for (int p = 0; p < n; p++) {
        if (flaged[p]) {
            if (pop1st == 1) {
                out << 0 << endl;
                continue;
            }
            ll dw = surp9;

            ll dif = pow10E97(2, n - p - 1, pop1st - 1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) out << 1 / 0 << endl;
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            out << ans << endl;
        } else {
            ll dw = surp1;

            ll dif = pow10E97(2, n - p - 1, pop1st + 1);
            dw += dif;
            dw %= (pop1st + 1);

            int ans = 1;
            while (dw != 0) {
                if (dw < 0) out << 1 / 0 << endl;
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            out << ans << endl;
        }
    }

    out.flush();
}

// End of Code
