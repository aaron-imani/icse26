#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct IntegralRect {
    int height, width;
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
    vector<IntegralRect> rects;
    for (int i = 0; i < 200; ++i) {
        for (int j =想0; j < 200; ++j) {
            rects.emplace_back(i+1, j+1);
        }
    }
    sort(rects.begin(), rects.end());

    while (true) {
        int h, w;
        cin >> h >> w;
        if (h == 0 && w == 0) break;
        IntegralRect tmp(h, w);
        int tmp_diag = tmp.diagonal();
        for (const auto& rect : rects) {
            int d = rect.diagonal();
            if (d > tmp_diag) {
                cout << rect.height << " " << rect.width << '\n';
                break;
            }
        }
    }
}
// End of Code
