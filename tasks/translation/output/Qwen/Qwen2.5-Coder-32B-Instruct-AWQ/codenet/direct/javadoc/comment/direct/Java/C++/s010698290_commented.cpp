#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class FastReader {
private:
    istream& is;
    string line;
    vector<string> tokens;
    size_t tokenIndex;

public:
    FastReader(istream& input = cin) : is(input), tokenIndex(0) {}

    string next() {
        if (tokenIndex >= tokens.size()) {
            getline(is, line);
            tokens.clear();
            stringstream ss(line);
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
            tokenIndex = 0;
        }
        return tokens[tokenIndex++];
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
        getline(is, line);
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

        cout << correct_ans << " " << num_penal << "\n";

    } catch (exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
// End of Code
