#include <iostream>
#include <algorithm>

using namespace std;

long long n, a, b, sa, ans;

string next() {
    string s;
    cin >> s;
    return s;
}

int nextInt() {
    int x;
    cin >> x;
    return x;
}

long long nextLong() {
    long long x;
    cin >> x;
    return x;
}

double nextDouble() {
    double x;
    cin >> x;
    return x;
}

int charToInt(char aaa) {
    return aaa - 48;
}

int main() {
    n = nextLong();
    a = nextLong();
    b = nextLong();

    sa = abs(a - b);

    ans = 0;

    if (sa % 2 ==  0) {
        ans = sa / 2;
    } else {
        long long AAA = min((n - a), (a - 1));
        long long BBB = min((n - b), (b - 1));

        ans = min(AAA, BBB);

        sa -= 1;
        ans += 1;

        ans += sa / 2;
    }

    cout << ans << endl;

    return 0;
}
// End of Code
