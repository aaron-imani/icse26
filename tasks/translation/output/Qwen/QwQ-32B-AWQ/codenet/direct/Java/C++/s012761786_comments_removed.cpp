#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string next() {
    string s;
    cin >> s;
    return s;
}

int nextInt() {
    int num;
    cin >> num;
    return num;
}

long long nextLong() {
    long long num;
    cin >> num;
    return num;
}

double nextDouble() {
    double num;
    cin >> num;
    return num;
}

int main() {
    long long n = nextLong();
    long long a = nextLong();
    long long b = nextLong();

    long long sa = abs(a - b);
    long long ans = 0;

    if (sa % 2 == 0) {
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
