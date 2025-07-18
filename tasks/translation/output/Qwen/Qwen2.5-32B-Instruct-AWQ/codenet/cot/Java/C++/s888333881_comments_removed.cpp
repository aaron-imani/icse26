#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Graph0n {
private:
    vector<Node0n> dt;
public:
    Graph0n(int sz) { for(int i=0; i<sz; i++) { Node0n node1; dt.push_back(node1); } }
    void add(int vn, int val) { dt[vn].add(val); }
    void add2(int vn, int val) { dt[vn].add(val); dt[val].add(vn); }
    int get(int vn, int index) { return dt[vn].get(index); }
    vector<int> get(int vn) { return dt[vn].getAll(); }
    int sizeOf(int vn) { return dt[vn].size(); }
    void clear() { for(int i=0; i<dt.size(); i++) { dt[i].clear(); } }
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
    int from=-1, v2=-1; long weight;
    Edge(int vn, long w) { this->v2 = vn; this->weight = w; }
    Edge(int cm, int vn, long w) { this->from = cm; this->v2 = vn; this->weight = w; }
};

class Edge2 {
public:
    int v2; long cost1, cost2;
    Edge2(int vn, long w1, long w2) { this->v2 = vn; this->cost1 = w1; this->cost2 = w2; }
};

class Comparator_Edge : public std::binary_function<Edge, Edge, bool> {
public:
    bool operator()(const Edge& a, const Edge& b) const {
        if(a.weight > b.weight) return true;
        else if(a.weight < b.weight) return false;
        else return b.v2 < a.v2;
    }
};

class V2Comp : public std::binary_function<Edge, Edge, bool> {
public:
    bool operator()(const Edge& a, const Edge& b) const {
        if(a.v2 > b.v2) return true;
        else if(a.v2 < b.v2) return false;
        else if(a.weight > b.weight) return true;
        else if(a.weight < b.weight) return false;
        else return false;
    }
};

class antiV2 : public std::binary_function<Edge, Edge, bool> {
public:
    bool operator()(const Edge& a, const Edge& b) const {
        if(a.v2 > b.v2) return false;
        else if(a.v2 < b.v2) return true;
        else if(a.weight > b.weight) return true;
        else if(a.weight < b.weight) return false;
        else return false;
    }
};

class Vector {
public:
    int x, y;
    Vector(int sx, int sy) { this->x = sx; this->y = sy; }
};

class FastScanner {
private:
    istream& in;
    char buffer[1024];
    int ptr = 0;
    int buflen = 0;
    bool hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
            ptr = 0;
            in.read(buffer, 1024);
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
    FastScanner(istream& in) : in(in) {}
    bool hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte(); }
    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string sb;
        int b = readByte();
        while(isPrintableChar(b)) {
            sb += b;
            b = readByte();
        }
        return sb;
    }
    long long nexL() {
        if (!hasNext()) throw runtime_error("No more input");
        long long n = 0;
        bool minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw runtime_error("Invalid number format");
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if(b == -1 || !isPrintableChar(b) || b == ':') {
                return minus ? -n : n;
            } else {
                throw runtime_error("Invalid number format");
            }
            b = readByte();
        }
    }
    int nexI() {
        long long nl = nexL();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Number out of range");
        return (int) nl;
    }
    double nexD() { return stod(next()); }
    void ni(vector<long long>& array2) {
        for(int i=0; i<array2.size(); i++) {
            array2[i] = nexL();
        }
        return;
    }
    void ni(vector<int>& array2) {
        for(int i=0; i<array2.size(); i++) {
            array2[i] = nexI();
        }
        return;
    }
    void ni(vector<int>& as, vector<int>& bs) {
        for(int i=0; i<as.size(); i++) {
            as[i] = nexI();
            bs[i] = nexI();
        }
        return;
    }
    void ni(vector<long long>& as, vector<long long>& bs) {
        for(int i=0; i<as.size(); i++) {
            as[i] = nexL();
            bs[i] = nexL();
        }
        return;
    }
    void ni(vector<int>& as, vector<int>& bs, vector<int>& cs) {
        for(int i=0; i<as.size(); i++) {
            as[i] = nexI();
            bs[i] = nexI();
            cs[i] = nexI();
        }
        return;
    }
    void nisan(vector<vector<int>>& as) {
        for(int i=0; i<as.size(); i++) {
            for(int j=0; j<as[0].size(); j++) {
                as[i][j] = nexI();
            }
        }
        return;
    }
};

int main() {
    FastScanner sc(cin);
    int n = sc.nexI();
    string s = sc.next();
    vector<bool> flaged(n, false);
    fill(flaged.begin(), flaged.end(), false);

    long long pop1st = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '1') {
            flaged[i] = true;
            pop1st++;
        }
    }

    long long surp1 = 0;
    for(int i=0; i<n; i++) {
        surp1 *= 2;
        if(flaged[i]) surp1++;
        surp1 %= (pop1st + 1);
    }

    long long surp9 = 0;
    if(pop1st > 1) {
        for(int i=0; i<n; i++) {
            surp9 *= 2;
            if(flaged[i]) surp9++;
            surp9 %= (pop1st - 1);
        }
    }

    for(int p=0; p<n; p++) {
        if(flaged[p]) {
            if(pop1st == 1) {
                cout << 0 << endl;
                continue;
            }
            long long dw = surp9;
            long long dif = pow(2, n-p-1, pop1st-1);
            dw -= dif;
            dw += (pop1st - 1);
            dw %= (pop1st - 1);
            int ans = 1;
            while(dw != 0) {
                if(dw < 0) cout << 1/0 << endl;
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        } else {
            long long dw = surp1;
            long long dif = pow(2, n-p-1, pop1st+1);
            dw += dif;
            dw %= (pop1st + 1);
            int ans = 1;
            while(dw != 0) {
                if(dw < 0) cout << 1/0 << endl;
                int count = countFlaged(dw);
                dw %= count;
                ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}

int INF = (int)1e8;
long long INFL = (long long)1e17;
long long e97 = (long long)1e9 + 7;

void assertion(bool b) { if(!b) throw runtime_error("Assertion failed"); }

int abs(int a) { return (a >= 0) ? a : -a; }
long long abs(long long a) { return (a >= 0) ? a : -a; }
double abs(double a) { return (a >= 0) ? a : -a; }

int min(int a, int b) { return (a > b) ? b : a; }
long long min(long long a, long long b) { return (a > b) ? b : a; }
double min(double a, double b) { return (a > b) ? b : a; }

int max(int a, int b) { return (a > b) ? a : b; }
long long max(long long a, long long b) { return (a > b) ? a : b; }
double max(double a, double b) { return (a > b) ? a : b; }

int minN(int... ins) {
    int min = ins[0];
    for(int i=1; i<ins.size(); i++) { if(ins[i] < min) min = ins[i]; }
    return min;
}

int maxN(int... ins) {
    int max = ins[0];
    for(int i=1; i<ins.size(); i++) { if(ins[i] > max) max = ins[i]; }
    return max;
}

long long minN(long long... ins) {
    long long min = ins[0];
    for(int i=1; i<ins.size(); i++) { if(ins[i] < min) min = ins[i]; }
    return min;
}

long long maxN(long long... ins) {
    long long max = ins[0];
    for(int i=1; i<ins.size(); i++) { if(ins[i] > max) max = ins[i]; }
    return max;
}

int minExAd(int[] dt, int ad) {
    int min = INF;
    for(int i=0; i<dt.size(); i++) { if((i != ad) && (dt[i] < min)) min = dt[i]; }
    return min;
}

long long minExAd(long long[] dt, int ad) {
    long long min = INFL;
    for(int i=0; i<dt.size(); i++) { if((i != ad) && (dt[i] < min)) min = dt[i]; }
    return min;
}

int minExVal(int[] dt, int ex_val) {
    int min = INF;
    for(int i=0; i<dt.size(); i++) { if((dt[i] != ex_val) && (dt[i] < min)) min = dt[i]; }
    return min;
}

long long minExVal(long long[] dt, long long ex_val) {
    long long min = INFL;
    for(int i=0; i<dt.size(); i++) { if((dt[i] != ex_val) && (dt[i] < min)) min = dt[i]; }
    return min;
}

int maxExAd(int[] dt, int ad) {
    int max = -INF;
    for(int i=0; i<dt.size(); i++) { if((i != ad) && (dt[i] > max)) max = dt[i]; }
    return max;
}

long long maxExAd(long long[] dt, int ad) {
    long long max = -INFL;
    for(int i=0; i<dt.size(); i++) { if((i != ad) && (dt[i] > max)) max = dt[i]; }
    return max;
}

int maxExVal(int[] dt, int ex_val) {
    int max = -INF;
    for(int i=0; i<dt.size(); i++) { if((dt[i] != ex_val) && (dt[i] > max)) max = dt[i]; }
    return max;
}

long long maxExVal(long long[] dt, long long ex_val) {
    long long max = -INFL;
    for(int i=0; i<dt.size(); i++) { if((dt[i] != ex_val) && (dt[i] > max)) max = dt[i]; }
    return max;
}

int sumA(int[] dt) {
    int sum = 0;
    for(int e : dt) { sum += e; }
    return sum;
}

long long sumA(long long[] dt) {
    long long sum = 0;
    for(long long e : dt) { sum += e; }
    return sum;
}

int sumA(vector<int> dt) {
    int sum = 0;
    for(int e : dt) { sum += e; }
    return sum;
}

bool same3(long long a, long long b, long long c) {
    if(a != b) return false;
    if(b != c) return false;
    if(c != a) return false;
    return true;
}

bool dif3(long long a, long long b, long long c) {
    if(a == b) return false;
    if(b == c) return false;
    if(c == a) return false;
    return true;
}

bool triangle_inequality(int a, int b, int c) {
    if((a + b) < c) return false;
    if((b + c) < a) return false;
    if((c + a) < b) return false;
    return true;
}

double hypod(double a, double b) {
    return sqrt(a*a + b*b);
}

long long factorial(int n) {
    long long ans = 1;
    for(long long i=n; i>0; i--) { ans *= i; }
    return ans;
}

long long facP(int n, long long p) {
    long long ans = 1;
    for(long long i=n; i>0; i--) {
        ans *= i;
        ans %= p;
    }
    return ans;
}

long long lcm(long long m, long long n) {
    long long ans = m / gcd(m, n);
    ans *= n;
    return ans;
}

long long gcd(long long m, long long n) {
    if(m < n) return gcd(n, m);
    if(n == 0) return m;
    return gcd(n, m % n);
}

bool is_prime(long long a) {
    if(a == 1) return false;
    for(long long i=2; i<=sqrt(a); i++) { if(a % i == 0) return false; }
    return true;
}

long long modinv(long long a, long long p) {
    long long b = p, u = 1, v = 0;
    while(b > 0) {
        long long t = a / b;
        long long pe = a % b;
        a = b; b = pe;
        pe = u - t * v;
        u = v; v = pe;
    }
    u %= p;
    if(u < 0) u += p;
    return u;
}

int pow(int n, int k) {
    int ans = 1;
    for(int i=0; i<k; i++) ans *= n;
    return ans;
}

long long pow(long long n, int k) {
    long long ans = 1;
    for(int i=0; i<k; i++) ans *= n;
    return ans;
}

int pow2(int in) { return in * in; }
long long pow2(long long in) { return in * in; }
double pow2(double in) { return in * in; }

int getDigit2(long long num) {
    long long cf = 1; int d = 0;
    while(num >= cf) { d++; cf = (1LL << d); }
    return d;
}

int getDigit10(long long num) {
    long long cf = 1; int d = 0;
    while(num >= cf) { d++; cf *= 10; }
    return d;
}

bool isINF(int in) {
    if(((long long)in * 20) > INF) return true;
    else return false;
}

bool isINFL(long long in) {
    if((in * 10000) > INFL) return true;
    else return false;
}

long long pow10E97(long long ob, long long soeji, long long p) {
    if(ob == 0) return 0;
    if(soeji == 0) return 1;
    if(soeji == 2) return (ob * ob) % p;

    int d = getDigit2(soeji);
    vector<long long> ob_pow_2pow(d);

    ob_pow_2pow[0] = ob;
    for(int i=1; i<d; i++) { ob_pow_2pow[i] = (ob_pow_2pow[i-1] * ob_pow_2pow[i-1]) % p; }

    long long ans = 1;
    for(int i=d-1; i>=0; i--) {
        if(soeji >= (1LL << i)) {
            soeji -= (1LL << i);
            ans = (ans * ob_pow_2pow[i]) % p;
        }
    }
    return ans % p;
}

long long flag(long long pos) { return (1LL << pos); }
bool isFlaged(int bit, int pos) { return (bit & (1 << pos)) > 0; }
bool isFlaged(long long bit, int pos) { return (bit & (1LL << pos)) > 0; }
int deflag(int bit, int pos) { return bit & ~(1 << pos); }
int countFlaged(int bit) {
    int ans = 0;
    for(int i=0; i<getDigit2(bit); i++) {
        if((bit & (1 << i)) > 0) ans++;
    }
    return ans;
}

int countFlaged(long long bit) {
    int ans = 0;
    for(long long i=0; i<getDigit2(bit); i++) {
        if((bit & (1LL << i)) > 0) ans++;
    }
    return ans;
}

void showflag(int bit) {
    for(int i=0; i<getDigit2(bit); i++) {
        if(isFlaged(bit, i)) cout << "O";
        else cout << ".";
    }
    cout << endl;
}

int biSearch(vector<int> dt, int target) {
    int left = 0, right = dt.size() - 1;
    int mid = -1;
    while(left <= right) {
        mid = (right + left) / 2;
        if(dt[mid] == target) return mid;
        if(dt[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int biSearchMax(vector<long long> dt, long long target) {
    int left = -1, right = dt.size();
    int mid = -1;
    while((right - left) > 1) {
        mid = left + (right - left) / 2;
        if(dt[mid] <= target) left = mid;
        else right = mid;
    }
    return left;
}

int biSearchMaxAL(vector<int> dt, long long target) {
    int left = -1, right = dt.size();
    int mid = -1;
    while((right - left) > 1) {
        mid = left + (right - left) / 2;
        if(dt[mid] <= target) left = mid;
        else right = mid;
    }
    return left;
}

void fill_parent(vector<int>& ob) {
    for(int i=0; i<ob.size(); i++) ob[i] = i;
}

int get_root_uf(vector<int>& parent, int index) {
    if(parent[index] == index) return index;
    int root = get_root_uf(parent, parent[index]);
    parent[index] = root;
    return root;
}

bool is_same_uf(vector<int>& parent, int x, int y) {
    if(get_root_uf(parent, x) == get_root_uf(parent, y)) return true;
    else return false;
}

void unite_uf(vector<int>& parent, int receiver, int attacker) {
    parent[get_root_uf(parent, attacker)] = get_root_uf(parent, receiver);
}

vector<int> Xdir4 = {1, 0, 0, -1};
vector<int> Ydir4 = {0, 1, -1, 0};

vector<int> Xdir8 = {1, 1, 1, 0, 0, -1, -1, -1};
vector<int> Ydir8 = {1, 0, -1, 1, -1, 1, 0, -1};

bool is_in_area(int y, int x, int h, int w) {
    if(y < 0) return false;
    if(x < 0) return false;
    if(y >= h) return false;
    if(x >= w) return false;
    return true;
}

void show2(vector<vector<bool>>& dt, int lit_x, int lit_y) {
    for(int j=0; j<dt.size(); j++) {
        for(int i=0; i<dt[j].size(); i++) {
            if((i == lit_y) && (j == lit_x)) cout << "X";
            else if(dt[j][i]) cout << "O";
            else cout << ".";
        }
        cout << endl;
    }
}

void show2(vector<vector<int>>& dt, string cmnt) {
    for(int i=0; i<dt.size(); i++) {
        for(int j=0; j<dt[i].size(); j++) {
            cout << dt[i][j] << ",";
        }
        cout << "<-" << cmnt << ":" << i << endl;
    }
}

void show2(vector<vector<long long>>& dt, string cmnt) {
    for(int i=0; i<dt.size(); i++) {
        for(int j=0; j<dt[i].size(); j++) {
            cout << dt[i][j] << ",";
        }
        cout << "<-" << cmnt << ":" << i << endl;
    }
}

void disp_que(deque<long long>& dt) {
    long long a = 0;
    while(dt.size() > 0) {
        a = dt.front();
        dt.pop_front();
        cout << a;
    }
    cout << "\n";
}

void disp_list(vector<int>& dt) {
    for(int i=0; i<dt.size(); i++) {
        cout << dt[i] << ",";
    }
    cout << "\n";
}

void prtlnas(vector<int>& as) {
    for(int i=0; i<as.size(); i++) {
        cout << as[i] << endl;
    }
}

void prtlnas(vector<long long>& as) {
    for(int i=0; i<as.size(); i++) {
        cout << as[i] << endl;
    }
}

void prtspas(vector<int>& as) {
    cout << as[0];
    for(int i=1; i<as.size(); i++) {
        cout << " " << as[i];
    }
    cout << endl;
}

void prtspas(vector<long long>& as) {
    cout << as[0];
    for(int i=1; i<as.size(); i++) {
        cout << " " << as[i];
    }
    cout << endl;
}

void prtspas(vector<int>& as) {
    cout << as[0];
    for(int i=1; i<as.size(); i++) {
        cout << " " << as[i];
    }
    cout << endl;
}

void fill(vector<bool>& ob, bool res) { for(int i=0; i<ob.size(); i++) ob[i] = res; }
void fill(vector<int>& ob, int res) { for(int i=0; i<ob.size(); i++) ob[i] = res; }
void fill(vector<long long>& ob, long long res) { for(int i=0; i<ob.size(); i++) ob[i] = res; }
void fill(vector<char>& ob, char res) { for(int i=0; i<ob.size(); i++) ob[i] = res; }
void fill(vector<double>& ob, double res) { for(int i=0; i<ob.size(); i++) ob[i] = res; }
void fill(vector<vector<bool>>& ob, bool res) { for(int i=0; i<ob.size(); i++) for(int j= 0; j<ob[0].size(); j++) ob[i][j] = res; }
void fill(vector<vector<int>>& ob, int res) { for(int i=0; i<ob.size(); i++) for(int j=0; j<ob[0].size(); j++) ob[i][j] = res; }
void fill(vector<vector<long long>>& ob, long long res) { for(int i=0; i<ob.size(); i++) for(int j=0; j<ob[0].size(); j++) ob[i][j] = res; }
void fill(vector<vector<char>>& ob, char res) { for(int i=0; i<ob.size(); i++) for(int j=0; j<ob[0].size(); j++) ob[i][j] = res; }
void fill(vector<vector<double>>& ob, double res) { for(int i=0; i<ob.size(); i++) for(int j=0; j<ob[0].size(); j++) ob[i][j] = res; }
void fill(vector<vector<vector<int>>>& ob, int res) { for(int i=0; i<ob.size(); i++) for(int j=0; j<ob[0].size(); j++) for(int k=0; k<ob[0][0].size(); k++) ob[i][j][k] = res; }
void fill(vector<vector<vector<long long>>>& ob, long long res) { for(int i=0; i<ob.size(); i++) for(int j=0; j<ob[0].size(); j++) for(int k=0; k<ob[0][0].size(); k++) ob[i][j][k] = res; }
// End of Code
