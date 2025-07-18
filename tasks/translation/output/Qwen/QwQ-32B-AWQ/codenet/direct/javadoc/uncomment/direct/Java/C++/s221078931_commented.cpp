#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct IntegralRect {
    int height;
    int width;
    IntegralRect(int h, int w) : height(h), width(w) {}
    int diagonal() const {
        if (height >= width) return INT_MAX;
        return height * height + width * width;
    }
    bool operator<(const IntegralRect& other) const {
        int d1 = diagonal(), d2 = other.diagonal();
        if (d1 != d2) return d1 < d2;
        return height < other.height;
    }
};

int main() {
    IntegralRect rects[40000];
    int idx = 0;
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200; ++j) {
            rects[idx++] = IntegralRect(i+1, j+1);
        }
    }
    sort(rects, rects + 40000);

    while (true) {
        int h, w;
        if (!(cin >> h >> w)) break;
        if (h == 0 && w == 0) break;
        IntegralRect tmp(h, w);
        for (int i = 0; i < 40000; ++i) {
            if (tmp < rects[i]) {
                cout << rects[i].height << " " << rects[i].width << '\n';
                break;
            }
        }
    }
    return 0;
}
// End of Code
