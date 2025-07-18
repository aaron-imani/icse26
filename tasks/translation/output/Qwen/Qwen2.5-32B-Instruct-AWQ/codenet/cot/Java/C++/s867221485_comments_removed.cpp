#include <iostream>
#include <string>

using namespace std;

int N;
int K;
long Q;
int A;
int B;
long C;
double min = 9999999;
long ans = 0;

int main() {
    int N;
    cin >> N;

    string s;
    getline(cin, s);
    getline(cin, s);

    bool flag = false;
    int ans = 0;
    int hen = 0;
    int sha = 0;
    int dot = 0;
    int temp = 0;
    bool first = true;
    for (int i = 0; i < N; i++) {
        if (s[i] == '#') {
            first = false;
            if (sha <= dot) {
                ans += sha;
                sha = 0;
                dot = 0;
                first = true;
            } else {
            }
            sha++;
        } else {
            dot++;
        }
    }

    if (sha <= dot) {
        ans += sha;
        dot = 0;
    } else {
    }

    cout << ans + dot << endl;
} // End of Code
