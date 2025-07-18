#include <iostream>
#include <algorithm>

using namespace std;

class Main {
public:
    void solve() {
        int N;
        cin >> N;
        int max, min;
        cin >> max;
        min = max;
        for (int i = 1; i < N; i++) {
            int in;
            cin >> in;
            max = std::max(max, in);
            min = std::min(min, in);
        }
        cout << max - min;
    }
};

int main() {
    Main().solve();
    return 0;
}
// End of Code
