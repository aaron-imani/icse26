#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

int main() {
    int64_t n, a, b;
    cin >> n >> a >> b;

    int64_t sa = std::llabs(a - b);
    int64_t ans = 0;

    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        int64_t AAA = min((n - a), (a - 1));
        int64_t BBB = min((n - b), (b - 1));

        ans = min(AAA, BBB);

        sa -= 1;
        ans += 1;

        ans += sa / 2;
    }

    cout << ans << endl;

    return 0;
}
// End of Code
