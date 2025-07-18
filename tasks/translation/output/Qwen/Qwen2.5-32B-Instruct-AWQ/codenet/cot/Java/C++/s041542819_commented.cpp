#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <stdexcept>
#include <locale>
#include <fstream>
#include <iomanip>

using namespace std;

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
            long long sl = x - s[max(0, lowerBound(s, x + 1) - 1)];
            long long tl = x - t[max(0, lowerBound(t, x + 1) - 1)];
            long long sr = s[lowerBound(s, x)] - x;
            long long tr = t[lowerBound(t, x)] - x;
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

private:
    int lowerBound(const vector<long long>& a, long long t) {
        int min = 0, max = a.size();
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

    long long longs() {
        return stoll(string());
    }
};

class LightWriter : public std::ostream {
public:
    LightWriter(std::ostream& out) : std::ostream(out.rdbuf()) {}

    LightWriter& ans(const string& s) {
        if (!breaked) {
            *this << ' ';
        }
        *this << s;
        return *this;
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
        *this << endl;
        breaked = true;
        if (autoflush) {
            flush();
        }
        return *this;
    }

    ~LightWriter() {
        flush();
    }

private:
    bool autoflush = false;
    bool breaked = true;
};

int main() {
    LightScanner in(cin);
    LightWriter out(cout);
    DLazyFaith solver;
    solver.solve(1, in, out);
    return 0;
}
// End of Code
