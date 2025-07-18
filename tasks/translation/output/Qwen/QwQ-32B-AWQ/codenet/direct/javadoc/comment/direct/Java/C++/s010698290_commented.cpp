#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

class FastReader {
private:
    istream& in;
    queue<string> tokens;

public:
    FastReader(istream& inStream = cin) : in(inStream) {}

    string next() {
        while (tokens.empty()) {
            string line;
            if (!getline(in, line)) break;
            stringstream ss(line);
            string token;
            while (ss >> token) {
                tokens.push(token);
            }
        }
        if (tokens.empty()) throw runtime_error("No more tokens");
        string res = tokens.front();
        tokens.pop();
        return res;
    }

    int nextInt() {
        string s = next();
        return stoi(s);
    }
};

int main() {
    FastReader s;
    int n = s.nextInt();
    int m = s.nextInt();

    vector<int> penal(n + 1, 0);
    vector<bool> solved(n + 1, false);

    for (int i = 0; i < m; ++i) {
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
    for (int i = 1; i <= n; ++i) {
        if (solved[i]) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    cout << correct_ans << " " << num_penal << endl;
    return 0;
}
// End of Code
