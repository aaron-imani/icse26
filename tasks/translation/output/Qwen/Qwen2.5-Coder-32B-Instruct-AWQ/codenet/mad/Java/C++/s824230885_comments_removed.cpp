// Corrected and improved C++ code
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>

class InputIterator {
    std::vector<std::string> inputLine;
    size_t index = 0;
    size_t max;
public:
    InputIterator() {
        std::string read;
        while (std::getline(std::cin, read)) {
            inputLine.push_back(read);
        }
        max = inputLine.size();
    }

    bool hasNext() { return index < max; }

    std::string next() {
        if (hasNext()) {
            return inputLine[index++];
        } else {
            throw std::out_of_range("There is no more input");
        }
    }
};

std::map<int, std::string> CONVSTR;
InputIterator ii;

void flush() { std::cout.flush(); }
void myout(const std::string& t) { std::cout << t << std::endl; }
void myerr(const std::string& t) { std::cerr << "debug:" << t << std::endl; }
std::string next() { return ii.next(); }
bool hasNext() { return ii.hasNext(); }
int nextInt() {
    try {
        return std::stoi(next());
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Invalid integer input");
    }
}
long long nextLong() {
    try {
        return std::stoll(next());
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Invalid long input");
    }
}
double nextDouble() {
    try {
        return std::stod(next());
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Invalid double input");
    }
}

std::vector<std::string> myconv(const std::string& str, int no) {
    std::string splitString = CONVSTR[no];
    std::vector<std::string> result;
    size_t start = 0, end;
    while ((end = str.find(splitString, start)) != std::string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + splitString.length();
    }
    result.push_back(str.substr(start));
    return result;
}

std::vector<int> nextIntArray() {
    std::vector<std::string> input = myconv(next(), 8);
    std::vector<int> ret;
    for (const auto& s : input) {
        ret.push_back(nextInt());
    }
    return ret;
}

void solve() {
    int N = nextInt();
    std::vector<int> list = nextIntArray();
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (max <= list[i]) {
            max = list[i];
            output++;
        }
    }
    myout(std::to_string(output));
}

int main() {
    CONVSTR[8] = " ";
    CONVSTR[9] = "\n";
    CONVSTR[0] = "";
    solve();
    flush();
    return 0;
}
// End of Code
