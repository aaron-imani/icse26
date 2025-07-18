#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    vector<IntegralRect> rects(40000);
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200; ++j) {
            rects[i * 200 + j] = IntegralRect(i + 1, j + 1);
        }
    }
    sort(rects.begin(), rects.end());

    // Debug
    /*
    for (int i = 0; i < 100; ++i) {
        cout << rects[i].height << " " << rects[i].width << " " << rects[i].diagonal() << endl;
    }
    */

    while (true) {
        int h, w;
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        }

        IntegralRect tmpRect(h, w);
        int diag = tmpRect.diagonal();

        for (const auto& rect : rects) {
            if (rect < tmpRect) {
                continue;
            }
            cout << rect.height << " " << rect.width << endl;
            break;
        }
    }

    return 0;
} // End of Code
