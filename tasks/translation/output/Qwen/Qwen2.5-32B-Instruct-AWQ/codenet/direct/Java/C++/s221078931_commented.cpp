#include <iostream>
#include <vector>
#include <algorithm>

class IntegralRect {
public:
    int height;
    int width;

    IntegralRect(int h, int w) : height(h), width(w) {}

    int diagonal() const {
        if (height >= width) {
            return INT_MAX;
        }
        return height * height + width * width;
    }

    bool operator<(const IntegralRect& other) const {
        int d1 = diagonal();
        int d2 = other.diagonal();
        if (d1 == d2) {
            return height < other.height;
        }
        return d1 < d2;
    }
};

int main() {
    std::vector<IntegralRect> rects;
    for (int i = 1; i <= 200; ++i) {
        for (int j = 1; j <= 200; ++j) {
            rects.emplace_back(i, j);
        }
    }
    std::sort(rects.begin(), rects.end());

    // Debug
    // for (int i = 0; i < 100; ++i) {
    //     std::cout << rects[i].height << " " << rects[i].width << " " << rects[i].diagonal() << std::endl;
    // }

    int h, w;
    while (std::cin >> h >> w) {
        if (h == 0 && w == 0) {
            break;
        }

        IntegralRect tmpRect(h, w);
        int diag = tmpRect.diagonal();

        for (const auto& rect : rects) {
            if (rect < tmpRect) {
                continue;
            }
            std::cout << rect.height << " " << rect.width << std::endl;
            break;
        }
    }

    return 0;
}

// End of Code
