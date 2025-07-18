#include <iostream>
#include <algorithm>

using namespace std;

class Main {
public:
    void solve() {
        int N;
        cin >> N;
        int max, min;
        max = min = cin.get();

        for (int i = 1; i < N; i++) {
            int in;
            cin >> in;
            max = std::max(max, in);
            min = std::min(min, in);
        }
        cout << max - min << endl;
    }
};

int main() {
    Main().solve();
    // End of Code
}
