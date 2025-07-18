#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    int N, M;
    iss >> N >> M;

    vector<int> shortage;

    for(int i = 0; i < M; ++i) {
        string s;
        getline(cin, s);
        int A = stoi(s);
        int sht = (N > A) ? N - A : 0;
        shortage.push_back(sht);
    }

    sort(shortage.begin(), shortage.end());

    int ans = 0;
    for(int i = 0; i < M - 1; ++i) {
        ans += shortage[i];
    }

    cout << ans << endl;

    return 0;
} // End of Code
