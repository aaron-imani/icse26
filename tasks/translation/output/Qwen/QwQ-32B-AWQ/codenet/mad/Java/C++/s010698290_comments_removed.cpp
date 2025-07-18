#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<char> solved(n + 1, '0');
    vector<int> penal(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int num;
        string str;
        cin >> num >> str;

        if (str[0] == 'A') {
            solved[num] = '1';
        } else {
            if (solved[num] == '0') {
                penal[num]++;
            }
        }
    }

    int correct_ans = 0, num_penal = 0;
    for (int i = 1; i <= n; ++i) {
        if (solved[i] == '1') {
            correct_ans++;
            num_pen['1'] += penal[i];
        }
    }

    cout << correct_ans << " " << num_penal << endl;
} // End of Code
