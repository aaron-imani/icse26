#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

class InputIterator {
public:
    std::vector<std::string> inputLine;
    int index = 0;
    int max;
    std::string read;

    InputIterator() {
        std::string line;
        while (std::getline(std::cin, line)) {
            inputLine.push_back(line);
        }
        max = inputLine.size();
    }

    bool hasNext() { return (index < max); }
    std::string next() {
        if (hasNext()) {
            return inputLine[index++];
        } else {
            throw std::out_of_range("There is no more input");
        }
    }
};

std::unordered_map<int, std::string> CONVSTR;
InputIterator ii;
std::ostream& out = std::cout;

void flush() { out.flush(); }
void myout(const std::string& t) { out << t << std::endl; }
void myerr(const std::string& t) { std::cerr << "debug:" << t << std::endl; }
std::string next() { return ii.next(); }
bool hasNext() { return ii.hasNext(); }
int nextInt() { return std::stoi(next()); }
long long nextLong() { return std::stoll(next()); }
double nextDouble() { return std::stod(next()); }
std::vector<std::string> nextStrArray() { return myconv(next(), 8); }
std::vector<std::string> nextCharArray() { return myconv(next(), 0); }
std::vector<int> nextIntArray() {
    std::vector<std::string> input = nextStrArray();
    std::vector<int> ret;
    for (const auto& str : input) {
        ret.push_back(std::stoi(str));
    }
    return ret;
}
std::vector<long long> nextLongArray() {
    std::vector<std::string> input = nextStrArray();
    std::vector<long long> ret;
    for (const auto& str : input) {
        ret.push_back(std::stoll(str));
    }
    return ret;
}
std::string myconv(const std::vector<std::string>& list, int no) {
    std::string joinString = CONVSTR[no];
    std::ostringstream oss;
    for (size_t i = 0; i < list.size(); ++i) {
        if (i != 0) {
            oss << joinString;
        }
        oss << list[i];
    }
    return oss.str();
}
std::vector<std::string> myconv(const std::string& str, int no) {
    std::string splitString = CONVSTR[no];
    std::vector<std::string> ret;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, splitString[0])) {
        ret.push_back(token);
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
} // End of Code
