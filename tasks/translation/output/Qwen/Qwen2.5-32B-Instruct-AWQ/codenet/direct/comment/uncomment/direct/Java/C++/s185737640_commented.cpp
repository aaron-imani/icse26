#include <iostream>
#include <string>

bool isEvenString(const std::string& s) {
    std::string a = s.substr(0, s.size() / 2);
    std::string b = s.substr(s.size() / 2);
    return a == b;
}

int main() {
    std::string S;
    std::getline(std::cin, S);

    if (S.size() % 2 == 1) {
        S = S.substr(0, S.size() - 1);
    } else {
        S = S.substr(0, S.size() - 2);
    }

    while (!S.empty()) {
        if (isEvenString(S)) {
            break;
        }
        S = S.substr(0, S.size() - 2);
    }

    std::cout << S.size() << std::endl;
    // End of Code
}
