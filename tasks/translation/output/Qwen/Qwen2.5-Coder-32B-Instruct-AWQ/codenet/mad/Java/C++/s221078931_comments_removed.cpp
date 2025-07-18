// Include necessary headers
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <climits>

class IntegralRect {
public:
    int height;
    int width;

    IntegralRect(int h, int w) : height(h), width(w) {}

    int diagonal() {
        if (height >= width) {
            return INT_MAX;
        }
        return height * height + width * width;
    }

    int compareTo(const IntegralRect& o) const {
        int d1 = diagonal();
        int d2 = o.diagonal();
        return d1 == d2 ? height - o.height : d1 - d2;
    }
};

int main() {
    std::vector<IntegralRect> rects(40000);
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects[i * 200 + j] = IntegralRect(i + 1, j + 1);
        }
    }
    std::sort(rects.begin(), rects.end(), [](const IntegralRect& a, const IntegralRect& b) {
        return a.compareTo(b) < 0;
    });

    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int h, w;
        iss >> h >> w;

        if (h == 0 && w == 0) {
            break;
        }

        IntegralRect tmpRect(h, w);
        int diag = tmpRect.diagonal();

        for (const auto& rect : rects) {
            if (rect.compareTo(tmpRect) > 0) {
                std::cout << rect.height << " " << rect.width << std::endl;
                break;
            }
        }
    }

    return 0;
}
// End of Code
