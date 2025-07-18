#include <iostream>
#include <string>

bool isEvenString(const std::string& s) {
    std::string a = s.substr(0, s.length() / 2);
    std::string b = s.substr(s.length() / 2);
    return a == b;
}

int main() {
    std::string S;
    std::getline(std::cin, S);

    if (S.length() % 2 == 1) {
        S = S.substr(0, S.length() - 1);
    } else {
        S = S.substr(0, S.length() - 2);
    }

    while (S.length() > 0) {
        if (isEvenString(S)) {
            break;
        }
        S = S.substr(0, S.length() - 2);
    }

    std::cout << S.length() << std::endl;
    return 0;
}
// End of Code
