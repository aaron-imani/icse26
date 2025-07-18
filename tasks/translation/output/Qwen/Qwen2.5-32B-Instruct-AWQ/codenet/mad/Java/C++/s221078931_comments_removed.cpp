#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class IntegralRect {
public:
    int height;
    int width;

    IntegralRect(int h, int w) : height(h), width(w) {}

    int diagonal() const {
        if (height >= width) {
            return std::numeric_limits<int>::max();
        }
        return height * height + width * width;
    }

    int compareTo(const IntegralRect& other) const {
        int d1 = diagonal();
        int d2 = other.diagonal();
        if (d1 == d2) {
            return height - other.height;
        }
        return d1 - d2;
    }
};

bool compareRects(const IntegralRect& rect1, const IntegralRect& rect2) {
    return rect1.compareTo(rect2) < 0;
}

int main() {
    std::vector<IntegralRect> rects(40000);
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects[i * 200 + j] = IntegralRect(i + 1, j + 1);
        }
    }
    std::sort(rects.begin(), rects.end(), compareRects);

    while (true) {
        int h, w;
        std::cin >> h >> w;
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
    // End of Code
}
