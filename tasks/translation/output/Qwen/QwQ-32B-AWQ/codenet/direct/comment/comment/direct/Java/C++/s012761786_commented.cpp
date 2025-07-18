#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    long n, a, b;
    cin >> n >> a >> b;
    long sa = labs(a - b);
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
    return 0;
}
// End of Code
