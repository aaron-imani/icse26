#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class IntegralRect {
public:
    int height, width;
    IntegralRect(int h, int w) : height(h), width(w) {}
    int diagonal() const {
        if (height >= width) {
            return numeric_limits<int>::max();
        }
        return height * height + width * width;
    }
    bool operator<(const IntegralRect& other) const {
        int d1 = diagonal();
        int d2 = other.diagonal();
        if (d1 != d2) {
            return d1 < d2;
        }
        return height < other.height;
    }
};

int main() {
    vector<IntegralRect> rects;
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200; ++j) {
            rects.emplace_back(i + 1, j + 1);
        }
    }
    sort(rects.begin(), rects.end());

    int h, w;
    while (cin >> h >> w) {
        if (h == 0 && w == 0) break;
        IntegralRect tmp(h, w);
        for (const auto& rect : rects) {
            if (rect.diagonal() > tmp.diagonal() || 
                (rect.diagonal() == tmp.diagonal() && rect.height > tmp.height)) {
                cout << rect.height << " " << rect.width << endl;
                break;
            }
        }
    }
    return 0;
}
// End of Code
