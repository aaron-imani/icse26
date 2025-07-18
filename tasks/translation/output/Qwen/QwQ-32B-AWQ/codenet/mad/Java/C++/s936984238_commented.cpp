#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<int> score;
static int number;

bool read() {
    cin >> number;
    if (number == 0) return false;
    score.resize(number);
    for(int i = 0; i < number; i++) {
        cin >> score[i];
    }
    return true;
}

void solve() {
    sort(score.begin(), score.end());
    int sum = 0;
    for(int i = 1; i < number-1; i++) {
        sum += score[i];
    }
    cout << sum/(number-2) << endl;
}

int main() {
    while(read()){
        solve();
    }
    return 0;
}
// End of Code
