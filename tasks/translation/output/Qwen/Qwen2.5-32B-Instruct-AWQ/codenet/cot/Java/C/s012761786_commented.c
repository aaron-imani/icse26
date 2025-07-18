#include <stdio.h>
#include <math.h>

long nextLong() {
    long num;
    scanf("%ld", &num);
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
        long AAA = fmin((n - a), (a - 1));
        long BBB = fmin((n - b), (b - 1));

        ans = fmin(AAA, BBB); //片方が端っこに来るまで。

        // 差を1減らす⇒差が偶数になる
        sa -= 1;
        ans += 1;

        // 差は偶数
        ans += sa / 2;
    }

    printf("%ld\n", ans);

    return 0;
}
// End of Code
