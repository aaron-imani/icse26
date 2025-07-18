#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

// InputReader class to handle input efficiently
class InputReader {
public:
    istream& stream;
    string currentLine;
    stringstream tokenizer;

    InputReader(istream& stream) : stream(stream) {}

    string next() {
        while (!tokenizer && getline(stream, currentLine)) {
            tokenizer = stringstream(currentLine);
        }
        string token;
        if (tokenizer >> token) {
            return token;
        }
        throw runtime_error("No more tokens available");
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

// Solve function to handle the input and output as required
void solve(InputReader& in, ostream& out) {
    int t = 1;
    while (t--) {
        long long n = in.nextLong();
        long long m = in.nextLong();
        if (n == 0) {
            out <<  0 << endl;
            continue;
        }
        if (n == m) {
            out <<  0 << endl;
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
    cin.tie(nullptr);

    InputReader in(cin);
    ostream& out = cout;

    solve(in, out);

    return 0;
}
// End of Code
