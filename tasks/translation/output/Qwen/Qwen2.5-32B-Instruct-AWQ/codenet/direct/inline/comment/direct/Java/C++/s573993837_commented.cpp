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
    int current = 0;

    InputReader(istream &stream) : reader(stream) {}

    string next() {
        if (current >= current_line.size() || current_line.empty()) {
            getline(reader, current_line);
            current = 0;
        }
        stringstream ss(current_line);
        string token;
        while (ss >> token) {
            if (current++ == 0) return token;
        }
        return "";
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
    cin.tie(NULL);

    InputReader in(cin);
    solve(in, cout);

    return 0;
}

// End of Code
