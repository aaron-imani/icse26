#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Solver {
public:
    void solve(int testNumber, istream& in, ostream& out) {
        int ans = 0;
        int K = 0, S = 0;
        in >> K >> S;
        int wk = 0;
        for(int x = 0; x <= K; x++) {
            for(int y = 0; y <= K; y++) {
                wk = S - x - y;
                if(wk >= 0 && wk <= K) {
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
        int ret;
        in >> ret;
        return ret;
    }
    long long nextLong() {
        long long ret;
        in >> ret;
        return ret;
    }
    string nextString() {
        string ret;
        in >> ret;
        return ret;
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
