#include <iostream>
#include <string>

bool isEvenString(const std::string& s) {
    std::size_t mid = s.length() / 2;
    std::string a = s.substr(0, mid);
    std::string b = s.substr(mid);
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

    for (; S.length() > 0; S = S.substr(0, S.length() - 2)) {
        if (isEvenString(S)) {
            break;
        }
    }
    std::cout << S.length() << '\n';

    return 0;
}
// End of Code
