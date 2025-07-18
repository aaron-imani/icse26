#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long nextLong() {
    long num;
    cin >> num;
    return num;
}

int main() {
    long n = nextLong();
    long a = nextLong();
    long b = nextLong();

    long sa = abs(a - b);

    long ans = 0;

    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        long AAA = min((n - a), (a - 1));
        long BBB = min((n - b), (b - 1));

        ans = min(AAA, BBB);

        sa -= 1;
        ans += 1;

        ans += sa / 2;
    }

    cout << ans << endl;
}

// End of Code
