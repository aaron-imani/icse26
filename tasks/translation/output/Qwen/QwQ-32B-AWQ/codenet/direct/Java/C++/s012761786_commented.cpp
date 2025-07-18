#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

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

vector<string> splitString(const string& s) {
    vector<string> result;
    for (char c : s) {
        result.push_back(string(1, c));
    }
    return result;
}

vector<char> splitChar(const string& s) {
    return vector<char>(s.begin(), s.end());
}

int charToInt(char c) {
    return c - '0';
}

int maxInt(int arr[], int lng) {
    int max = arr[0];
    for (int i = 1; i < lng; i++) {
        max = std::max(max, arr[i]);
    }
    return max;
}

int minInt(int arr[], int lng) {
    int min = arr[0];
    for (int i = 1; i < lng; i++) {
        min = std::min(min, arr[i]);
    }
    return min;
}

long long maxLong(long long arr[], int lng) {
    long long max = arr[0];
    for (int i = 1; i < lng; i++) {
        max = std::max(max, arr[i]);
    }
    return max;
}

long long minLong(long long arr[], int lng) {
    long long min = arr[0];
    for (int i = 1; i < lng; i++) {
        min = std::min(min, arr[i]);
    }
    return min;
}

int main() {
    long long n = nextLong();
    long long a = nextLong();
    long long b = nextLong();

    long long sa = std::llabs(a - b);

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
