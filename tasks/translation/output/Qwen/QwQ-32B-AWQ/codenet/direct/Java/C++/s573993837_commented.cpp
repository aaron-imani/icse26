#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

class InputReader {
private:
    istream& in;
    queue<string> tokens;

public:
    InputReader(istream& inputStream) : in(inputStream) {}

    string next() {
        if (tokens.empty()) {
            string line;
            getline(in, line);
            istringstream iss(line);
            string token;
            while (iss >> token) {
                tokens.push(token);
            }
        }
        string res = tokens.front();
        tokens.pop();
        return res;
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
    while (t-- > 0) {
        long long n = sc.nextLong();
        long long m = sc.nextLong();
        if (n == 0) {
            out << 0 << '\n';
            continue;
        }
        if (n == m) {
            out << 0 << '\n';
            continue;
        }
        if (n > m) {
            n %= m;
        }
        out << min(m - n, n) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    InputReader in(cin);
    solve(in, cout);
    return 0;
}
// End of Code
