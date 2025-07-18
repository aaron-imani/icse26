#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const long long mod = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int inf = numeric_limits<int>::max() / 2;
const long long linf = numeric_limits<long long>::max() / 3;
const double dinf = numeric_limits<double>::max() / 3;
const double eps = 1e-10;
const double pi = M_PI;

const int BUFFER_SIZE = 1024;
vector<char> inbuf(BUFFER_SIZE);
int lenbuf = 0, ptrbuf = 0;

int readByte() {
    if (lenbuf == -1) {
        throw runtime_error("Input error");
    }
    if (ptrbuf >= lenbuf) {
        ptrbuf = 0;
        if (cin.eof()) {
            lenbuf = -1;
            return -1;
        }
        cin.read(inbuf.data(), BUFFER_SIZE);
        lenbuf = cin.gcount();
        if (lenbuf <= 0) {
            lenbuf = -1;
            return -1;
        }
    }
    return static_cast<int>(inbuf[ptrbuf++]);
}

bool isSpaceChar(int c) {
    return !(c >= 33 && c <= 126);
}

int skip() {
    int b;
    while ((b = readByte()) != -1 && isSpaceChar(b))
        ;
    return b;
}

string ns() {
    int b = skip();
    string sb;
    while (!isSpaceChar(b)) {
        sb += static_cast<char>(b);
        b = readByte();
    }
    return sb;
}

int ni() {
    int num = 0, b;
    bool minus = false;
    while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
        ;
    if (b == '-') {
        minus = true;
        b = readByte();
    }
    while (true) {
        if (b >= '0' && b <= '9') {
            num = num * 10 + (b - '0');
        } else {
            return minus ? -num : num;
        }
        b = readByte();
    }
}

long long nl() {
    long long num = 0;
    int b;
    bool minus = false;
    while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
        ;
    if (b == '-') {
        minus = true;
        b = readByte();
    }
    while (true) {
        if (b >= '0' && b <= '9') {
            num = num * 10 + (b - '0');
        } else {
            return minus ? -num : num;
        }
        b = readByte();
    }
}

void reverse(int ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        swap(ar[i], ar[len - 1 - i]);
    }
}

void reverse(long long ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        swap(ar[i], ar[len - 1 - i]);
    }
}

void reverse(double ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        swap(ar[i], ar[len - 1 - i]);
    }
}

void reverse(char ar[], int len) {
    for (int i = 0; i < len / 2; i++) {
        swap(ar[i], ar[len - 1 - i]);
    }
}

string getReverse(const string& s) {
    string temp = s;
    reverse(temp.begin(), temp.end());
    return temp;
}

template<typename T>
void reverse(vector<T>& v) {
    int sz = v.size();
    for (int i = 0; i < sz / 2; i++) {
        swap(v[i], v[sz - 1 - i]);
    }
}

int lowerBound(int a[], int size, int x) {
    int l = -1, r = size;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (a[c] < x) l = c;
        else r = c;
    }
    return r;
}

void solve() {
    string tmp = ns();
    int n = tmp.size();
    int ans = 0, cnt = 0;
    for (char c : tmp) {
        if (c == 'S') {
            cnt++;
        } else {
            if (cnt == 0) continue;
            ans++;
            cnt--;
        }
    }
    cout << (n - 2 * ans) << endl;
}

int main() {
    solve();
    return 0;
}
// End of Code
