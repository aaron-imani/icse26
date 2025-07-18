#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> score;
int number;

bool read() {
    std::cin >> number;
    if (number == 0)
        return false;
    
    score.resize(number);
    for (int i = 0; i < number; i++) {
        std::cin >> score[i];
    }
    return true;
}

void solve() {
    std::sort(score.begin(), score.end());
    int sum = 0;
    for (int i = 1; i < number - 1; i++) {
        sum += score[i];
    }
    std::cout << sum / (number - 2) << std::endl;
}

int main() {
    while (read()) {
        solve();
    }
}
// End of Code
