#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

// For her who keeps the fire kindling in me...

using namespace std;

class FastReader {
public:
    string next() {
        string str;
        getline(cin, str);
        stringstream ss(str);
        string word;
        while (ss >> word) {
            return word;
        }
        return "";
    }

    int nextInt() {
        return stoi(next());
    }

    long nextLong() {
        return stol(next());
    }

    double nextDouble() {
        return stod(next());
    }

    string nextLine() {
        string str;
        getline(cin, str);
        return str;
    }
};

int main() {
    try {
        FastReader s;
        int i, j;
        int m, n, t, max, k, x, y, min, correct_ans, num, num_penal;
        long a, b, sum;

        string str;

        n = s.nextInt();
        m = s.nextInt();

        vector<int> penal(n + 1, 0);
        vector<bool> solved(n + 1, false);

        for (i = 0; i < m; i++) {
            num = s.nextInt();
            str = s.next();
            if (str[0] == 'A') {
                solved[num] = true;
            } else {
                if (solved[num] == false)
                    penal[num]++;
            }
        }

        correct_ans = 0;
        num_penal = 0;
        for (i = 1; i <= n; i++) {
            if (solved[i] == true) {
                correct_ans++;
                num_penal += penal[i];
            }
        }

        cout << correct_ans << " " << num_penal << "\n";

    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
// End of Code
