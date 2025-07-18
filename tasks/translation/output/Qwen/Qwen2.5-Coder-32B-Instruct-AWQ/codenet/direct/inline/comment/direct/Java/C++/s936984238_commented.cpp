#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int number;
        cin >> number;
        if (number == 0)
            break;

        vector<int> score(number);
        for (int i = 0; i < number; i++) {
            cin >> score[i];
        }

        sort(score.begin(), score.end());
        int sum = 0;
        for (int i = 1; i < number - 1; i++) {
            sum += score[i];
        }
        cout << sum / (number - 2) << endl;
    }
    return 0;
}
// End of Code
