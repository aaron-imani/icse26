#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;

    std::cin.ignore(); // Ignore the newline character left in the input buffer

    std::string s;
    std::getline(std::cin, s);

    bool first = true;
    int ans = 0;
    int sha = 0;
    int dot = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] == '#') {
            if (sha <= dot) {
                ans += sha;
                sha = 0;
                dot = 0;
            }
            sha++;
        } else {
            dot++;
        }
    }

    if (sha <= dot) {
        ans += sha;
        dot = 0;
    }

    std::cout << ans + dot << std::endl;
}
// End of Code
