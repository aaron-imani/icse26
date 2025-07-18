#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

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

long nextLong() {
    long x;
    cin >> x;
    return x;
}

vector<string> splitString(string s) {
    vector<string> res;
    for (char c : s) {
        res.push_back(string(1, c));
    }
    return res;
}

vector<char> splitChar(string s) {
    return vector<char>(s.begin(), s.end());
}

int charToInt(char c) {
    return c - '0';
}

int maxInt(const int* a, int lng) {
    int max = a[0];
    for (int i = 1; i < lng; i++) {
        max = std::max(max, a[i]);
    }
    return max;
}

int minInt(const int* a, int lng) {
    int min = a[0];
    for (int i = 1; i < lng; i++) {
        min = std::min(min, a[i]);
    }
    return min;
}

long maxLong(const long* a, int lng) {
    long max = a[0];
    for (int i = 1; i < lng; i++) {
        max = std::max(max, a[i]);
    }
    return max;
}

long minLong(const long* a, int lng) {
    long min = a[0];
    for (int i = 1; i < lng; i++) {
        min = std::min(min, a[i]);
    }
    return min;
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

        ans = std::min(AAA, BBB);

        sa -= 1;
        ans += 1;

        ans += sa / 2;
    }

    cout << ans << endl;

    return 0;
}
// End of Code
