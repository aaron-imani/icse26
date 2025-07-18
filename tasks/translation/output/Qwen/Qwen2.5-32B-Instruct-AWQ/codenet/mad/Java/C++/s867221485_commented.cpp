#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore(); // Ignore the newline character after reading N

    std::string s;
    std::getline(std::cin, s); // Read the entire line into s

    bool first = true;
    int ans = 0;
    int sha = 0;
    int dot = 0;

    for (int i = 0; i < N; i++) {
        if (s[i] == '#') {
            first = false;
            if (sha <= dot) {
                ans += sha;
                sha = 0;
                dot = 0;
                first = true;
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
