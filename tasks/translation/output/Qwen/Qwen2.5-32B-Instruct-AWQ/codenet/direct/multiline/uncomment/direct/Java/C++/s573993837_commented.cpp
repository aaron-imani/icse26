#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class InputReader {
public:
    string next() {
        while (!tokenizer.empty()) {
            tokenizer.pop_back();
        }
        string line;
        getline(cin, line);
        stringstream ss(line);
        string token;
        while (ss >> token) {
            tokenizer.push_back(token);
        }
        if (tokenizer.empty()) {
            return "";
        }
        string result = tokenizer.front();
        tokenizer.erase(tokenizer.begin());
        return result;
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

private:
    vector<string> tokenizer;
};

void solve(InputReader &in, ostream &out) {
    int t = 1;
    while (t--) {
        long long n = in.nextLong();
        long long m = in.nextLong();
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    InputReader in(cin);
    ostream &out = cout;

    solve(in, out);

    return 0;
}

// End of Code
