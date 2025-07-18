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
        if (!tokens.empty()) return true;
        string line;
        while (getline(stream, line) && line.empty());
        stringstream ss(line);
        string token;
        while (ss >> token) tokens.push_back(token);
        return !tokens.empty();
    }

    string nextToken() {
        if (next()) {
            string token = tokens.front();
            tokens.erase(tokens.begin());
            return token;
        }
        return "";
    }

    int nextInt() {
        return stoi(nextToken());
    }

    long long nextLong() {
        return stoll(nextToken());
    }

    double nextDouble() {
        return stod(nextToken());
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
