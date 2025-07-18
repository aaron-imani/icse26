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
        return d1 == d2 ? height < other.height : d1 < d2;
    }
};

int main() {
    std::vector<IntegralRect> rects;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects.emplace_back(i + 1, j + 1);
        }
    }
    std::sort(rects.begin(), rects.end());

    // debug
    // for (int i = 0; i < 100; i++) {
    //     std::cout << rects[i].height << " " << rects[i].width << " " << rects[i].diagonal() << std::endl;
    // }

    while (true) {
        int h, w;
        std::cin >> h >> w;

        if (h == 0 && w == 0) {
            break;
        }

        IntegralRect tmpRect(h, w);
        int diag = tmpRect.diagonal();
        // std::cout << diag << std::endl;
        for (const auto& rect : rects) {
            // std::cout << rect.diagonal() << std::endl;
            if (rect > tmpRect) {
                std::cout << rect.height << " " << rect.width << std::endl;
                break;
            }
        }
    }

    return 0;
}
// End of Code
