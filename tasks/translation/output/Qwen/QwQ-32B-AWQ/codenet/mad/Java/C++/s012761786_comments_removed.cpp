#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

string next() {
    string s;
    cin >> s;
    return s;
}

int nextInt() {
    return stoi(next());
}

long long nextLong() {
    return stoll(next());
}

double nextDouble() {
    return stod(next());
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

int maxInt(int a[], int lng) {
    int max_val = a[0];
    for (int i = 1; i < lng; i++) {
        max_val = std::max(max_val, a[i]);
    }
    return max_val;
}

int minInt(int a[], int lng) {
    int min_val = a[0];
    for (int i = 1; i < lng; i++) {
        min_val = std::min(min_val, a[i]);
    }
    return min_val;
}

long long maxLong(long long a[], int lng) {
    long long max_val = a[0];
    for (int i = 1; i < lng; i++) {
        max_val = std::max(max_val, a[i]);
    }
    return max_val;
}

long long minLong(long long a[], int lng) {
    long long min_val = a[0];
    for (int i = 1; i < lng; i++) {
        min_val = std::min(min_val, a[i]);
    }
    return min_val;
}

int main() {
    long long n = nextLong();
    long long a = nextLong();
    long long b = nextLong();

    long long sa = std::llabs(a - b); // Use std::llabs for long long

    long long ans = 0;

    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        long long AAA = std::min((n - a), (a - 1));
        long long BBB = std::min((n - b), (b - 1));

        ans = std::min(AAA, BBB);

        sa -= 1;
        ans += 1;

        ans += sa / 2;
    }

    cout << ans << endl;

    return 0;
}
// End of Code
