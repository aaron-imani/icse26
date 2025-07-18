#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class Solver {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int ans = 0;
        int K, S;
        in >> K >> S;
        int wk = 0;
        for (int x = 0; x <= K; x++) {
            for (int y = 0; y <= K; y++) {
                wk = S - x - y;
                if (wk >= 0 && wk <= K) {
                    ans++;
                }
            }
        }
        out << ans << endl;
    }
};

class MyInput {
private:
    istream& in;
public:
    MyInput(istream& is) : in(is) {}
    int nextInt() {
        int value;
        in >> value;
        return value;
    }
    long long nextLong() {
        long long value;
        in >> value;
        return value;
    }
    string nextString() {
        string value;
        in >> value;
        return value;
    }
};

int main() {
    istream& inputStream = cin;
    ostream& outputStream = cout;
    MyInput in(inputStream);
    Solver solver;
    solver.solve(1, inputStream, outputStream);
    return 0;
}
// End of Code
