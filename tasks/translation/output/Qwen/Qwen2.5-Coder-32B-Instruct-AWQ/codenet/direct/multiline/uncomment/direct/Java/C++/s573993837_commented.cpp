#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

class InputReader {
public:
    istream &stream;
    string buffer;
    vector<string> tokens;

    InputReader(istream &stream) : stream(stream) {}

    bool next() {
        if (!tokens.empty()) {
            return true;
        }
        while (getline(stream, buffer)) {
            stringstream ss(buffer);
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
            if (!tokens.empty()) {
                return true;
            }
        }
        return false;
    }

    string nextString() {
        next();
        string result = tokens.front();
        tokens.erase(tokens.begin());
        return result;
    }

    int nextInt() {
        return stoi(nextString());
    }

    long long nextLong() {
        return stoll(nextString());
    }

    double nextDouble() {
        return stod(nextString());
    }
};

void solve(InputReader &sc, ostream &pw) {
    int t = 1;
    while (t--) {
        long long n = sc.nextLong();
        long long m = sc.nextLong();
        if (n == 0) {
            pw << 0 << endl;
            continue;
        }
        if (n == m) {
            pw << 0 << endl;
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            pw << min(m - n, n) << endl;
            continue;
        }
        pw << min(m - n, n) << endl;
    }
}

int main() {
    InputReader in(cin);
    solve(in, cout);
    return 0;
}
// End of Code
