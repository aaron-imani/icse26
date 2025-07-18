#include <iostream>
#include <algorithm>

using namespace std;

class Main {
private:
    int N;
    int max, min;

public:
    void solve() {
        cin >> N;
        cin >> max >> min;
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
    Main mainInstance;
    mainInstance.solve();
    return 0;
}
// End of Code
