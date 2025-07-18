#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    int N, M;
    size_t spacePos = line.find(' ');
    N = stoi(line.substr(0, spacePos));
    M = stoi(line.substr(spacePos + 1));

    vector<int> shortage(M);

    for (int i = 0; i < M; i++) {
        getline(cin, line);
        int A = stoi(line);
        shortage[i] = (N > A) ? N - A : 0;
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
