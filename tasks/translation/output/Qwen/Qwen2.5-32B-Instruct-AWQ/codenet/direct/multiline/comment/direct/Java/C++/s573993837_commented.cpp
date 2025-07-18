#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class InputReader {
public:
    istream &reader;
    string current_line;
    int current_pos;

    InputReader(istream &stream) : reader(stream), current_pos(0) {}

    string next() {
        if (current_pos >= current_line.size()) {
            getline(reader, current_line);
            current_pos = 0;
        }
        while (current_pos < current_line.size() && current_line[current_pos] == ' ') {
            ++current_pos;
        }
        string token;
        while (current_pos < current_line.size() && current_line[current_pos] != ' ') {
            token += current_line[current_pos++];
        }
        return token;
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
    cin.tie(nullptr);

    InputReader in(cin);
    solve(in, cout);

    return 0;
}

// End of Code
