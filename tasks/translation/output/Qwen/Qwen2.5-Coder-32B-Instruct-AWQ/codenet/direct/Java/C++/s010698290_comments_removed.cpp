#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class FastReader {
    string line;
    stringstream ss;

public:
    string next() {
        if (!getline(cin, line)) return "";
        ss.clear();
        ss.str(line);
        string word;
        ss >> word;
        return word;
    }

    int nextInt() {
        return stoi(next());
    }

    long long nextLong() {
        return stoll(next());
    }

    double nextDouble() {
        return stod(next());
    }

    string nextLine() {
        if (!getline(cin, line)) return "";
        return line;
    }
};

int main() {
    try {
        FastReader s;
        int i, j;
        int m, n, t, max, k, x, y, min, correct_ans, num, num_penal;
        long long a, b, sum;

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
                if (!solved[num]) {
                    penal[num]++;
                }
            }
        }

        correct_ans = 0;
        num_penal = 0;
        for (i = 1; i <= n; i++) {
            if (solved[i]) {
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
