#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;

    std::cin.ignore(); // To ignore the newline character after the integer input

    std::string s;
    std::getline(std::cin, s);

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

    if (sha > dot) {
        ans += sha;
    }

    std::cout << ans + dot << std::endl;

    return 0;
}
// End of Code
