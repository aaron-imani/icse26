#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IntegralRect {
public:
    int height, width;
    IntegralRect(int h, int w) : height(h), width(w) {}
    
    int diagonal() const {
        if (height >= width) return INT_MAX;
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
            if (rects[i] > tmp) {
                cout << rects[i].height << " " << rects[i].width << endl;
                break;
            }
        }
    }
}
// End of Code
