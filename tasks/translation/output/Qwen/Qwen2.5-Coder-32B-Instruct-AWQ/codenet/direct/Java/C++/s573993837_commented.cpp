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
    istream& stream;
    string buffer;
    vector<string> tokens;
    int tokenIndex;

    InputReader(istream& _stream) : stream(_stream), tokenIndex(0) {}

    string next() {
        while (tokenIndex == tokens.size()) {
            if (!getline(stream, buffer)) {
                return "";
            }
            tokens.clear();
            stringstream ss(buffer);
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
            tokenIndex = 0;
        }
        return tokens[tokenIndex++];
    }

    int nextInt() {
        return stoi(next());
    }

    long long nextLong() {
        return stoll(next());
    }

    double nextDouble() {
        return stod(next());
    }
};

void solve(InputReader& sc, ostream& out) {
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
