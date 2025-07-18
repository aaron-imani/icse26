#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> a >> b;

    long long sa = abs(a - b);

    long long ans = 0;

    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        long long AAA = min((n - a), (a - 1));
        long long BBB = min((n - b), (b - 1));

        ans = min(AAA, BBB); // One side reaches the edge.

        // Reduce the difference by 1 to make it even
        sa -= 1;
        ans += 1;

        // Difference is now even
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

vector<string> splitString(string s) {
    vector<string> result;
    for (char c : s) {
        result.push_back(string(1, c));
    }
    return result;
}

vector<char> splitChar(string s) {
    return vector<char>(s.begin(), s.end());
}

int charToInt(char aaa) {
    return aaa - '0';
}

int maxInt(vector<int>& a) {
    return *max_element(a.begin(), a.end());
}

int minInt(vector<int>& a) {
    return *min_element(a.begin(), a.end());
}

long long maxLong(vector<long long>& a) {
    return *max_element(a.begin(), a.end());
}

long long minLong(vector<long long>& a) {
    return *min_element(a.begin(), a.end());
}

// End of Code
