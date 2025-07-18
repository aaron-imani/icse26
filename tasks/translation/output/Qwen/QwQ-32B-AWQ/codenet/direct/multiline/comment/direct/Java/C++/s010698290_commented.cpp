#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<bool> solved(n + 1);
    vector<int> penal(n + 1);

    for (int i = 0; i < m; ++i) {
        int num;
        string str;
        cin >> num >> str;
        if (str == "A") {
            solved[num] = true;
        } else {
            if (!solved[num]) {
                penal[num]++;
            }
        }
    }

    int correct_ans = 0;
    int num_penal = 0;

    for (int i = 1; i <= n; ++i) {
        if (solved[i]) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    cout << correct_ans << " " << num_penal << '\n';

    return 0;
}
// End of Code
