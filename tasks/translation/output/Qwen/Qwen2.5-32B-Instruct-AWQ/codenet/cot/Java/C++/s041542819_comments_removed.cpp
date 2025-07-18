#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <optional>
#include <locale>

using namespace std;

class DLazyFaith {
public:
    void solve(int testNumber, LightScanner& in, LightWriter& out) {
        int a = in.ints(), b = in.ints(), q = in.ints();
        vector<long> s(a + 2), t(b + 2);
        s[0] = t[0] = -10000000000L;
        for (int i = 0; i < a; i++) {
            s[i + 1] = in.longs();
        }
        for (int i = 0; i < b; i++) {
            t[i + 1] = in.longs();
        }
        s[a + 1] = t[b + 1] = 20000000000L;
        for (int i = 0; i < q; i++) {
            long x = in.longs();
            long sl = x - s[max(0, lowerBound(s, x + 1) - 1)];
            long tl = x - t[max(0, lowerBound(t, x + 1) - 1)];
            long sr = s[lowerBound(s, x)] - x;
            long tr = t[lowerBound(t, x)] - x;
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

class LightScanner {
private:
    istream& reader;
    istringstream tokenizer;

public:
    LightScanner(istream& in) : reader(in) {}

    string string() {
        if (!tokenizer) {
            string line;
            getline(reader, line);
            tokenizer = istringstream(line);
        }
        string token;
        tokenizer >> token;
        return token;
    }

    int ints() {
        return stoi(string());
    }

    long longs() {
        return stol(string());
    }
};

class LightWriter : public ofstream {
public:
    LightWriter(ostream& out) : ofstream(out) {}

    LightWriter& print(char c) {
        write(&c, 1);
        return *this;
    }

    LightWriter& print(const string& s) {
        write(s.c_str(), s.size());
        return *this;
    }

    LightWriter& ans(const string& s) {
        if (!breaked) {
            print(' ');
        }
        return print(s);
    }

    LightWriter& ans(long l) {
        return ans(to_string(l));
    }

    LightWriter& ansln(long... n) {
        for (auto n1 : {n}) {
            ans(n1).ln();
        }
        return *this;
    }

    LightWriter& ln() {
        print("\n");
        breaked = true;
        if (autoflush) {
            flush();
        }
        return *this;
    }

    void close() {
        ofstream::close();
    }

private:
    bool autoflush = false;
    bool breaked = true;
};

class IntMath {
public:
    static long min(long... v) {
        return *min_element(v.begin(), v.end());
    }
};

class ArrayUtil {
public:
    static int lowerBound(const vector<long>& a, long t) {
        return lowerBound(a, t, 0);
    }

    static int lowerBound(const vector<long>& a, long t, int min) {
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

int main() {
    LightScanner in(cin);
    LightWriter out(cout);
    DLazyFaith solver;
    solver.solve(1, in, out);
    out.close();
    // End of Code
}
