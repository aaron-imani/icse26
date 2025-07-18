#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct IntegralRect {
    int height, width;
    IntegralRect(int h, int w) : height(h), width(w) {}
    int diagonal() const {
        if (height >= width) return numeric_limits<int>::max();
        return height * height + width * width;
    }
    bool operator<(const IntegralRect& other) const {
        int d1 = diagonal();
        int d2 = other.diagonal();
        if (d1 != d2) return d1 < d2;
        return height < other.height;
    }
};

int main() {
    vector<IntegralRect> rects(40000);
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200; ++j) {
            int idx = i * 200 + j;
            rects[idx] = IntegralRect(i + 1, j + 1);
        }
    }
    sort(rects.begin(), rects.end());

    int h, w;
    while (cin >> h >> w) {
        if (h == 0 && w == 0) break;
        IntegralRect tmp(h, w);
        for (size_t i = 0; i < rects.size(); ++i) {
            if (tmp < rects[i]) {
                cout << rects[i].height << " " << rects[i].width << endl;
                break;
            }
        }
    }
    return 0;
}
// End of Code
