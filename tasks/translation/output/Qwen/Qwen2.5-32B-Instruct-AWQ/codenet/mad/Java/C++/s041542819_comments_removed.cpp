#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class LightScanner {
private:
    istream& reader;
    string currentLine;
    istringstream currentStream;

public:
    LightScanner(istream& in) : reader(in) {}

    string string() {
        if (!currentStream) {
            getline(reader, currentLine);
            currentStream = istringstream(currentLine);
        }
        string token;
        currentStream >> token;
        return token;
    }

    int ints() {
        return stoi(string());
    }

    long long longs() {
        return stoll(string());
    }
};

class LightWriter {
private:
    ostream& out;
    bool autoflush = false;
    bool breaked = true;

public:
    LightWriter(ostream& out) : out(out) {}

    LightWriter& print(char c) {
        out.write(&c, 1);
        breaked = false;
        return *this;
    }

    LightWriter& print(const string& s) {
        out.write(s.c_str(), s.size());
        breaked = false;
        return *this;
    }

    LightWriter& ans(const string& s) {
        if (!breaked) {
            print(' ');
        }
        return print(s);
    }

    LightWriter& ans(long long l) {
        return ans(to_string(l));
    }

    LightWriter& ansln(long long... n) {
        for (auto n1 : {n}) {
            ans(n1).ln();
        }
        return *this;
    }

    LightWriter& ln() {
        out << '\n';
        breaked = true;
        if (autoflush) {
            out.flush();
        }
        return *this;
    }

    void close() {
        out.close();
    }
};

class IntMath {
public:
    static long long min(long long... v) {
        return *min_element(begin(v), end(v));
    }
};

class ArrayUtil {
public:
    static int lowerBound(const vector<long long>& a, long long t) {
        return lowerBound(a, t, 0);
    }

    static int lowerBound(const vector<long long>& a, long long t, int min) {
        int max = a.size();
        while (min < max) {
            int mid = (min + max) / 2;
            if (t <= a[mid]) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        return min;
    }
};

class DLazyFaith {
public:
    void solve(int testNumber, LightScanner& in, LightWriter& out) {
        int a = in.ints(), b = in.ints(), q = in.ints();
        vector<long long> s(a + 2), t(b + 2);
        s[0] = t[0] = -10000000000LL;
        for (int i = 0; i < a; i++) {
            s[i + 1] = in.longs();
        }
        for (int i = 0; i < b; i++) {
            t[i + 1] = in.longs();
        }
        s[a + 1] = t[b + 1] = 20000000000LL;
        for (int i = 0; i < q; i++) {
            long long x = in.longs();
            long long sl = x - s[max(0, ArrayUtil::lowerBound(s, x + 1) - 1)];
            long long tl = x - t[max(0, ArrayUtil::lowerBound(t, x + 1) - 1)];
            long long sr = s[ArrayUtil::lowerBound(s, x)] - x;
            long long tr = t[ArrayUtil::lowerBound(t, x)] - x;
            out.ansln(min({
                max(sl, tl),
                max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
            }));
        }
    }
};

int main() {
    LightScanner in(cin);
    LightWriter out(cout);
    DLazyFaith solver;
    solver.solve(1, in, out);
    out.close();
    return 0;
}
// End of Code
