#include <iostream>
using namespace std;

int d;

bool read() { return cin >> d; }

int solve() {
    int ans = 0;
    for(int i = 1; i * d < 600; i++) {
        int x = i * d;
        int y = x * x;
        ans += y * d;
    }
    return ans;
}

int main() {
    while(read()) {
        cout << solve() << endl;
    }
    return 0;
}
// End of Code
