#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class FastReader {
private:
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
        getline(cin, line);
        return line;
    }
};

int main() {
    try {
        FastReader s;
        int n = s.nextInt();
        int m = s.nextInt();

        vector<int> penal(n + 1, 0);
        vector<bool> solved(n + 1, false);

        for (int i = 0; i < m; i++) {
            int num = s.nextInt();
            string str = s.next();
            if (str[0] == 'A') {
                solved[num] = true;
            } else {
                if (!solved[num]) {
                    penal[num]++;
                }
            }
        }

        int correct_ans = 0;
        int num_penal = 0;
        for (int i = 1; i <= n; i++) {
            if (solved[i]) {
                correct_ans++;
                num_penal += penal[i];
            }
        }

        cout << correct_ans << " " << num_penal << endl;

    } catch (exception &e) {
        cerr << e.what() << endl;
    }
    return 0;
}
// End of Code
