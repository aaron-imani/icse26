#include <iostream>
using namespace std;

static int d;

// Function to read the input value 'd'
static bool read() {
    if (!(cin >> d)) return false;
    return true;
}

// Function to solve the integral approximation
static int solve() {
    int ans = 0;
    for(int i = 1; i * d < 600; ++i) { // Using pre-increment for efficiency
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
