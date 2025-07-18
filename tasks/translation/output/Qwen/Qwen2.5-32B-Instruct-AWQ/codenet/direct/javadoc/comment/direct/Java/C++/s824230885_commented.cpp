#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::string> inputLines;
size_t index = 0;

void initializeInput() {
    std::string line;
    while (std::getline(std::cin, line)) {
        inputLines.push_back(line);
    }
}

bool hasNext() {
    return index < inputLines.size();
}

std::string next() {
    if (hasNext()) {
        return inputLines[index++];
    } else {
        throw std::out_of_range("There is no more input");
    }
}

int nextInt() {
    return std::stoi(next());
}

std::vector<int> nextIntArray() {
    std::vector<int> result;
    std::string line = next();
    std::stringstream ss(line);
    int value;
    while (ss >> value) {
        result.push_back(value);
    }
    return result;
}

void solve() {
    size_t N = nextInt();
    std::vector<int> list = nextIntArray();
    int max = 0;
    int output = 0;
    for(size_t i = 0; i < N; i++) {
        if(max <= list[i]) {
            max = list[i];
            output++;
        }
    }
    std::cout << output << std::endl;
}

int main() {
    initializeInput();
    solve();
    return 0;
}
// End of Code
