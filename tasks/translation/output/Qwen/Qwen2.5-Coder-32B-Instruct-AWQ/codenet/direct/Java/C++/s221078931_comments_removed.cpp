#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

    bool operator<(const IntegralRect& o) const {
        int d1 = diagonal();
        int d2 = o.diagonal();
        return (d1 == d2) ? height < o.height : d1 < d2;
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

    int h, w;
    while (std::cin >> h >> w) {
        if (h == 0 && w == 0) {
            break;
        }

        IntegralRect tmpRect(h, w);
        auto it = std::upper_bound(rects.begin(), rects.end(), tmpRect);

        if (it != rects.end()) {
            std::cout << it->height << " " << it->width << std::endl;
        }
    }

    return 0;
}
// End of Code
