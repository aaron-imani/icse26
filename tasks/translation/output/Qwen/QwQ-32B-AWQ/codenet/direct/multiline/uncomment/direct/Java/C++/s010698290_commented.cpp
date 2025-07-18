#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

class FastReader {
private:
    istream& in;
    queue<string> tokens;
public:
    FastReader(istream& input = cin) : in(input) {}

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
        if (tokens.empty()) throw runtime_error("No token available");
        string res = tokens.front();
        tokens.pop();
        return res;
    }

    int nextInt() {
        return stoi(next());
    }
};

int main() {
    FastReader fr;
    int n = fr.nextInt();
    int m = fr.nextInt();

    vector<bool> solved(n+1, false);
    vector<int> penal(n+1, 0);

    for (int i = 0; i < m; ++i) {
        int num = fr.nextInt();
        string str = fr.next();
        if (str == "A") {
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
