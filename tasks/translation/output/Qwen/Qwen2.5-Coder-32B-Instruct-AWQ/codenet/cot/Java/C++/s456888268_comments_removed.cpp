#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

class Main {
public:
    static void solve() {
        string tmp = ns();
        vector<char> s(tmp.begin(), tmp.end());
        int n = s.size();
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'S') {
                cnt++;
            } else {
                if(cnt == 0) continue;
                ans++;
                cnt--;
            }
        }
        cout << n - 2 * ans << endl;
    }

private:
    static const long long mod = 1e9 + 7;
    static const int dx[4];
    static const int dy[4];
    static const int dx8[8];
    static const int dy8[8];
    static const int inf;
    static const long long linf;
    static const double dinf;
    static const double eps;
    static const double pi;

    static istream* is;
    static ostream* out;
    static string INPUT;

    static void reverse(vector<int>& ar) {
        reverse(ar.begin(), ar.end());
    }

    static void reverse(vector<long long>& ar) {
        reverse(ar.begin(), ar.end());
    }

    static void reverse(vector<double>& ar) {
        reverse(ar.begin(), ar.end());
    }

    static void reverse(vector<char>& ar) {
        reverse(ar.begin(), ar.end());
    }

    static string getReverse(string s) {
        reverse(s.begin(), s.end());
        return s;
    }

    template <typename T>
    static void reverse(vector<T>& ls) {
        reverse(ls.begin(), ls.end());
    }

    template <typename T>
    static void reverse(T ar[], int len) {
        for (int i = 0; i < len / 2; i++) {
            T t = ar[i];
            ar[i] = ar[len - 1 - i];
            ar[len - 1 - i] = t;
        }
    }

    static void sbnl() {
        cout << endl;
    }

    static int lowerBound(vector<int>& a, int x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin();
    }

    static int upperBound(vector<int>& a, int x) {
        return upper_bound(a.begin(), a.end(), x) - a.begin();
    }

    static int lowerBound(vector<long long>& a, long long x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin();
    }

    static int upperBound(vector<long long>& a, long long x) {
        return upper_bound(a.begin(), a.end(), x) - a.begin();
    }

    static int lowerBound(vector<double>& a, double x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin();
    }

    static int upperBound(vector<double>& a, double x) {
        return upper_bound(a.begin(), a.end(), x) - a.begin();
    }

    static int lowerBound(vector<char>& a, char x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin();
    }

    static int upperBound(vector<char>& a, char x) {
        return upper_bound(a.begin(), a.end(), x) - a.begin();
    }

    static int max(int x, int y) {
        return std::max(x, y);
    }

    static int min(int x, int y) {
        return std::min(x, y);
    }

    static int max(int x, int y, int z) {
        return std::max(x, std::max(y, z));
    }

    static int min(int x, int y, int z) {
        return std::min(x, std::min(y, z));
    }

    static long long max(long long x, long long y) {
        return std::max(x, y);
    }

    static long long min(long long x, long long y) {
        return std::min(x, y);
    }

    static long long max(long long x, long long y, long long z) {
        return std::max(x, std::max(y, z));
    }

    static long long min(long long x, long long y, long long z) {
        return std::min(x, std::min(y, z));
    }

    static double max(double x, double y) {
        return std::max(x, y);
    }

    static double min(double x, double y) {
        return std::min(x, y);
    }

    static double max(double x, double y, double z) {
        return std::max(x, std::max(y, z));
    }

    static double min(double x, double y, double z) {
        return std::min(x, std::min(y, z));
    }

    static void sort(vector<int>& ar) {
        std::sort(ar.begin(), ar.end());
    }

    static void sort(vector<long long>& ar) {
        std::sort(ar.begin(), ar.end());
    }

    static void sort(vector<double>& ar) {
        std::sort(ar.begin(), ar.end());
    }

    static void sort(vector<char>& ar) {
        std::sort(ar.begin(), ar.end());
    }

    static void rsort(vector<int>& ar) {
        std::sort(ar.begin(), ar.end(), greater<int>());
    }

    static void rsort(vector<long long>& ar) {
        std::sort(ar.begin(), ar.end(), greater<long long>());
    }

    static void rsort(vector<double>& ar) {
        std::sort(ar.begin(), ar.end(), greater<double>());
    }

    static void rsort(vector<char>& ar) {
        std::sort(ar.begin(), ar.end(), greater<char>());
    }

    static void fill(vector<int>& arr, int x) {
        std::fill(arr.begin(), arr.end(), x);
    }

    static void fill(vector<long long>& arr, long long x) {
        std::fill(arr.begin(), arr.end(), x);
    }

    static void fill(vector<bool>& arr, bool x) {
        std::fill(arr.begin(), arr.end(), x);
    }

    static void fill(vector<double>& arr, double x) {
        std::fill(arr.begin(), arr.end(), x);
    }

    static void fill(vector<vector<int>>& arr, int x) {
        for (auto& row : arr) {
            std::fill(row.begin(), row.end(), x);
        }
    }

    static void fill(vector<vector<long long>>& arr, long long x) {
        for (auto& row : arr) {
            std::fill(row.begin(), row.end(), x);
        }
    }

    static void fill(vector<vector<bool>>& arr, bool x) {
        for (auto& row : arr) {
            std::fill(row.begin(), row.end(), x);
        }
    }

    static void fill(vector<vector<double>>& arr, double x) {
        for (auto& row : arr) {
            std::fill(row.begin(), row.end(), x);
        }
    }

    static long long plus(long long x, long long y) {
        long long res = (x + y) % mod;
        return res < 0 ? res + mod : res;
    }

    static long long sub(long long x, long long y) {
        long long res = (x - y) % mod;
        return res < 0 ? res + mod : res;
    }

    static long long mul(long long x, long long y) {
        long long res = (x * y) % mod;
        return res < 0 ? res + mod : res;
    }

    static long long div(long long x, long long y) {
        long long res = x * pow(y, mod - 2) % mod;
        return res < 0 ? res + mod : res;
    }

    static long long pow(long long x, long long y) {
        if (y < 0)
            return 0;
        if (y == 0)
            return 1;
        if (y % 2 == 1)
            return (x * pow(x, y - 1)) % mod;
        long long root = pow(x, y / 2);
        return root * root % mod;
    }

    static void main() {
        is = &cin;
        out = &cout;
        solve();
        out->flush();
    }

private:
    static const int BUFFER_SIZE = 1024;
    static char buffer[BUFFER_SIZE];
    static int buffer_pos;
    static int buffer_len;

    static int readByte() {
        if (buffer_pos >= buffer_len) {
            buffer_pos = 0;
            buffer_len = is->read(buffer, BUFFER_SIZE);
            if (buffer_len == -1) {
                return -1;
            }
        }
        return buffer[buffer_pos++];
    }

    static bool isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }

    static int skip() {
        int b;
        while ((b = readByte()) != -1 && isSpaceChar(b));
        return b;
    }

    static double nd() {
        return stod(ns());
    }

    static char nc() {
        return (char) skip();
    }

    static string ns() {
        int b = skip();
        string ret;
        while (!(isSpaceChar(b))) {
            ret += (char) b;
            b = readByte();
        }
        return ret;
    }

    static vector<int> na(int n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = ni();
        }
        return a;
    }

    static vector<long long> nla(int n) {
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = nl();
        }
        return a;
    }

    static int ni() {
        int num = 0, b;
        bool minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
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

    static long long nl() {
        long long num = 0;
        int b;
        bool minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
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
};

const int Main::dx[4] = { -1, 0, 1, 0 };
const int Main::dy[4] = { 0, -1, 0, 1 };
const int Main::dx8[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int Main::dy8[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int Main::inf = INT_MAX / 2;
const long long Main::linf = LLONG_MAX / 3;
const double Main::dinf = DBL_MAX / 3;
const double Main::eps = 1e-10;
const double Main::pi = M_PI;
char Main::buffer[Main::BUFFER_SIZE];
int Main::buffer_pos = 0;
int Main::buffer_len = 0;

int main() {
    Main::main();
    return 0;
}
// End of Code
