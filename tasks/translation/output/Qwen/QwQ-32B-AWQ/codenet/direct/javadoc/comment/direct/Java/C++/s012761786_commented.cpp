#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    long n, a, b;
    cin >> n >> a >> b;

    long sa = std::abs(a - b);

    long ans = 0;

    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        long AAA = std::min(n - a, a - 1);
        long BBB = std::min(n - b, b - 1);

        ans = std::min(AAA, BBB);

        sa -= 1;
        ans += 1;

        ans += sa / 2;
    }

    cout << ans << endl;
    return 0;
}
// End of Code
