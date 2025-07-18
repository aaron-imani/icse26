#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include <exception>

using namespace std;

class FastReader {
private:
    istream& in;
    string line;
    deque<string> tokens;

public:
    FastReader(istream& input = cin) : in(input) {}

    string next() {
        while (tokens.empty()) {
            if (!getline(in, line)) {
                throw runtime_error("Error reading input");
            }
            stringstream ss(line);
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
        }
        string result = tokens.front();
        tokens.pop_front();
        return result;
    }

    int nextInt() {
        return stoi(next());
    }
};

int main() {
    FastReader s;
    int n = s.nextInt();
    int m = s.nextInt();

    vector<int> penal(n+1);
    vector<bool> solved(n+1);

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

    int correct_ans = 0, num_penal = 0;
    for (int i = 1; i <= n; ++i) {
        if (solved[i]) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    cout << correct_ans << " " << num_penal << '\n';
    return 0;
} // End of Code
