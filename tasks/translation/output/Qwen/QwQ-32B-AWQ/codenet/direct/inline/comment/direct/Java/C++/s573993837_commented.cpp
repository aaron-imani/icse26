#include <iostream>
#include <sstream>
using namespace std;

class InputReader {
private:
    istream& in;
    string currentLine;
    istringstream tokenStream;
public:
    InputReader(istream& inputStream) : in(inputStream) {}
    string next() {
        while (tokenStream.eof()) {
            if (!getline(in, currentLine)) break;
            tokenStream = istringstream(currentLine);
        }
        string token;
        if (tokenStream >> token) return token;
        return "";
    }
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
    double nextDouble() { return stod(next()); }
};

void solve(InputReader& in, ostream& out) {
    int t = 1;
    while (t-- > 0) {
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
        n %= m;
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
