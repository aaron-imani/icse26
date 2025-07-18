#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>

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

    //constant
    static const long long mod = 1e9 + 7;
    static const int dx[] = { -1, 0, 1, 0 };
    static const int dy[] = { 0, -1, 0, 1 };
    static const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    static const int inf = INT_MAX / 2;
    static const long long linf = LLONG_MAX / 3;
    static const double dinf = numeric_limits<double>::max() / 3;
    static const double eps = 1e-10;
    static const double pi = M_PI;
    static string sb;
    static istream* is;
    static ostream* out;
    static string INPUT;

    //libraries
    template<typename T>
    static void reverse(vector<T>& ar) {
        std::reverse(ar.begin(), ar.end());
    }

    static void sbnl() {
        sb += "\n";
    }

    template<typename T>
    static int lowerBound(vector<T>& a, T x) {
        return std::lower_bound(a.begin(), a.end(), x) - a.begin();
    }

    template<typename T>
    static int upperBound(vector<T>& a, T x) {
        return std::upper_bound(a.begin(), a.end(), x) - a.begin();
    }

    static int ni() {
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

    static string ns() {
        int b = skip();
        string sb;
        while (!(isSpaceChar(b))) {
            sb += (char) b;
            b = readByte();
        }
        return sb;
    }

private:
    static int readByte() {
        if (is->eof())
            return -1;
        return is->get();
    }

    static bool isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }

    static int skip() {
        int b;
        while ((b = readByte()) != -1 && isSpaceChar(b))
            ;
        return b;
    }

public:
    static void main() {
        is = &cin;
        out = &cout;
        solve();
    }
};

int main() {
    Main::main();
    return 0;
}
// End of Code
