#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class MyInput {
public:
    MyInput(istream& is) : in(is) {}

    int nextInt() {
        string s = nextString();
        return stoi(s);
    }

    long long nextLong() {
        string s = nextString();
        return stoll(s);
    }

    double nextDouble() {
        string s = nextString();
        return stod(s);
    }

    string nextString() {
        string s;
        in >> s;
        return s;
    }

    char nextChar() {
        char c;
        in >> c;
        return c;
    }

private:
    istream& in;
};

class Solver {
public:
    Solver(MyInput& in, ostream& out) : in(in), out(out) {}

    void solve() {
        int H = in.nextInt();
        int W = in.nextInt();
        vector<vector<char>> C(H + 2, vector<char>(W + 2));
        for (int i = 0; i < H; i++) {
            string s = in.nextString();
            for (int j = 0; j < W; j++) {
                C[i + 1][j + 1] = s[j];
            }
        }
        if (H == 1 && W == 1) {
            out << "No" << endl;
            return;
        }
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if (C[i][j] == '#' && C[i - 1][j] != '#' && C[i + 1][j] != '#' 
                    && C[i][j - 1] != '#' && C[i][j + 1] != '#') {
                    out << "No" << endl;
                    return;
                }
            }
        }
        out << "Yes" << endl;
    }

private:
    MyInput& in;
    ostream& out;
};

int main() {
    MyInput in(cin);
    Solver solver(in, cout);
    solver.solve();
    return 0;
}
// End of Code
