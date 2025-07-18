#include <iostream>
#include <limits>

using namespace std;

static int d;

static bool read() {
    if (!(cin >> d)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

static int solve() {
    int ans = 0;
    for (int i = 1; i * d < 600; i++) {
        int x = i * d;
        int y = x * x;
        ans += y * d;
    }
    return ans;
}

int main() {
    while (read()) {
        cout << solve() << endl;
    }
    return 0;
}
// End of Code
