#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    int N, M;
    size_t pos = line.find(' ');
    N = stoi(line.substr(0, pos));
    M = stoi(line.substr(pos + 1));

    vector<int> shortage(M);

    for (int i = 0; i < M; i++) {
        getline(cin, line);
        pos = line.find(' ');
        int A = stoi(line.substr(0, pos));
        shortage[i] = N > A ? N - A : 0;
    }

    sort(shortage.begin(), shortage.end());

    int ans = 0;

    for (int i = 0; i < M - 1; i++) {
        ans += shortage[i];
    }

    cout << ans << endl;

    return 0;
}
// End of Code
