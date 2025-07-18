#include <iostream>
#include <sstream>
#include <queue>
#include <string>

using namespace std;

class InputReader {
private:
    istream& in;
    queue<string> tokens;
    string line;
public:
    InputReader(istream& in) : in(in) {}
    void loadNextLine() {
        if (tokens.empty()) {
            getline(in, line);
            stringstream ss(line);
            string token;
            while (ss >> token) {
                tokens.push(token);
            }
        }
    }
    string next() {
        loadNextLine();
        string token = tokens.front();
        tokens.pop();
        return token;
    }
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
    double nextDouble() { return stod(next()); }
};

void solve(InputReader& in, ostream& out) {
    int t = 1;
    while(t-- > 0) {
        long long n = in.nextLong();
        long long m = in.nextLong();
        if (n == 0) {
            out << 0 << '\n';
            continue;
        }
        if (n == m) {
            out << 0 << '\n';
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            out << min(m - n, n) << '\n';
            continue;
        }
        out << min(m - n, n) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    InputReader in(cin);
    solve(in, cout);
    return 0;
}
// End of Code
