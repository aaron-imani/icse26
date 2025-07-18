#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> penal(n + 1, 0);
    vector<bool> solved(n + 1, false);

    for(int i = 0; i < m; i++) {
        int num;
        string str;
        cin >> num >> str;
        if(str[0] == 'A') {
            solved[num] = true;
        } else {
            if(!solved[num]) {
                penal[num]++;
            }
        }
    }

    int correct_ans = 0, num_penal = 0;
    for(int i = 1; i <= n; i++) {
        if(solved[i]) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    cout << correct_ans << " " << num_penal << "\n";

    return 0;
}
// End of Code
