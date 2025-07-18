#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Main {
public:
    static int number;
    static vector<int> score;
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

int Main::number;
vector<int> Main::score;
istream& Main::sc = cin;

int main() {
    Main::main();
} // End of Code
