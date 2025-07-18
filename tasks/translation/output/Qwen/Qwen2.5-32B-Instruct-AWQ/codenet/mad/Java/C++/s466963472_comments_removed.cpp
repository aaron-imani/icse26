#include <iostream>
using namespace std;

static int d;

static bool read() {
    if (!(cin >> d)) return false;
    return true;
}

static int solve() {
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
    // End of Code
}
