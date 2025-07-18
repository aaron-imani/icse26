#include <iostream>
#include <cmath>
#include <algorithm>

//update 2019/12/13

long nextLong() {
    long n;
    std::cin >> n;
    return n;
}

int main() {
    long n = nextLong();
    long a = nextLong();
    long b = nextLong();

    long sa = std::abs(a - b);

    long ans = 0;

    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        long AAA = std::min((n - a), (a - 1));
        long BBB = std::min((n - b), (b - 1));

        ans = std::min(AAA, BBB); //片方が端っこに来るまで。

        //差を1減らす⇒差が偶数になる
        sa -= 1;
        ans += 1;

        //差は偶数
        ans += sa / 2;
    }

    std::cout << ans << std::endl;

    return 0;
}
// End of Code
