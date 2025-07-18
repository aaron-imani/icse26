#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

class InputReader {
public:
    istream& stream;
    string current_line;
    int current = 0;

    InputReader(istream& _stream) : stream(_stream) {}

    string next() {
        if (current >= current_line.size() || current_line.empty()) {
            getline(stream, current_line);
            current = 0;
        }
        stringstream ss(current_line);
        string token;
        while (ss >> token) {
            if (current == 0) break;
            current++;
        }
        current++;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    InputReader in(cin);
    solve(in, cout);

    return 0;
}

// End of Code
