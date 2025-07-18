#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string next();
int nextInt();
long long nextLong();
double nextDouble();
vector<string> splitString(const string&);
vector<char> splitChar(const string&);
int charToInt(char);
int maxInt(int[], int);
int minInt(int[], int);
long long maxLong(long long[], int);
long long minLong(long long[], int);

int main() {
    long long n = nextLong();
    long long a = nextLong();
    long long b = nextLong();

    long long sa = std::llabs(a - b);

    long long ans = 0;

    if (sa % 2 == 0) {
        ans = sa / 2;
    }
    else {
        long long AAA = std::min((n - a), (a - 1LL));
        long long BBB = std::min((n - b), (b - 1LL));

        ans = std::min(AAA, BBB);

        sa -= 1;
        ans += 1;

        ans += sa / 2;
    }

    cout << ans << endl;

    return 0;
}

string next() {
    string s;
    cin >> s;
    return s;
}

int nextInt() {
    int val;
    cin >> val;
    return val;
}

long long nextLong() {
    long long val;
    cin >> val;
    return val;
}

double nextDouble() {
    double val;
    cin >> val;
    return val;
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

// End of Code
