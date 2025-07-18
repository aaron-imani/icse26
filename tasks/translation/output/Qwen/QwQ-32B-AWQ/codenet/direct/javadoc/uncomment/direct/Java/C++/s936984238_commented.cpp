#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static vector<int> score;
static int number;

bool read() {
    cin >> number;
    if (number == 0) return false;
    score.clear();
    for(int i = 0; i < number; i++) {
        int temp;
        cin >> temp;
        score.push_back(temp);
    }
    return true;
}

void slove() {
    sort(score.begin(), score.end());
    int sum = 0;
    for(int i = 1; i < number - 1; i++) {
        sum += score[i];
    }
    cout << sum / (number - 2) << endl;
}

int main() {
    while(read()) {
        slove();
    }
    return 0;
}
// End of Code
