#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Main {
public:
    static vector<int> score;
    static int number;
    static istream& sc;

    static void main() {
        while (read()) {
            slove();
        }
    }

    static bool read() {
        sc >> number;
        if (number == 0)
            return false;

        score.resize(number);
        for (int i = 0; i < number; i++) {
            sc >> score[i];
        }
        return true;
    }

    static void slove() {
        sort(score.begin(), score.end());
        int sum = 0;
        for (int i = 1; i < number - 1; i++) {
            sum += score[i];
        }
        cout << sum / (number - 2) << endl;
    }
};

vector<int> Main::score;
int Main::number;
istream& Main::sc = cin;

int main() {
    Main::main();
    // End of Code
}
