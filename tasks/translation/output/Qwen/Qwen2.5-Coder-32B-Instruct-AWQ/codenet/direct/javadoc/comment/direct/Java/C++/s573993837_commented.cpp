#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>

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
            tokens = split(buffer, ' ');
            if (!tokens.empty()) {
                return true;
            }
        }
        return false;
    }

    string nextString() {
        if (next()) {
            string token = tokens.front();
            tokens.erase(tokens.begin());
            return token;
        }
        return "";
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

private:
    vector<string> split(const string &s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

void solve(InputReader &sc, ostream &out) {
    int t = 1;
    while (t--) {
        long long n = sc.nextLong();
        long long m = sc.nextLong();
        if (n == 0) {
            out << 0 << endl;
            continue;
        }
        if (n == m) {
            out << 0 << endl;
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            out << min(m - n, n) << endl;
            continue;
        }
        out << min(m - n, n) << endl;
    }
}

int main() {
    InputReader in(cin);
    solve(in, cout);
    return 0;
}
// End of Code
