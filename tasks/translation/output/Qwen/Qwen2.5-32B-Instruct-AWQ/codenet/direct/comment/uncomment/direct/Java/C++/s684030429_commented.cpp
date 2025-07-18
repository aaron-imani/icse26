#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Main {
private:
    int max = 0, cur = 0;
    int ni() {
        int a;
        cin >> a;
        return a;
    }

public:
    void solve() {
        int a = ni();
        int b = ni();

        cout << max(0, a - 2 * b) << endl;
    }
};

int main() {
    Main().solve();
    return 0;
}

// End of Code
