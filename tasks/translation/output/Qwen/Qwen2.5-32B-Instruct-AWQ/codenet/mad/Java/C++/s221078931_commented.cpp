#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

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
    vector<IntegralRect> rects(40000);
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects[i * 200 + j] = IntegralRect(i + 1, j + 1);
        }
    }
    sort(rects.begin(), rects.end(), compareRects);

    // debug
    // for (int i = 0; i < 100; i++) {
    //     cout << rects[i].height << " " << rects[i].width << " " << rects[i].diagonal() << endl;
    // }

    while (true) {
        int h, w;
        cin >> h >> w;

        if (h == 0 && w == 0) {
            break;
        }

        IntegralRect tmpRect(h, w);
        int diag = tmpRect.diagonal();
        // cout << diag << endl;
        for (int i = 0; i < rects.size(); i++) {
            // cout << rects[i].diagonal() << endl;
            if (rects[i].compareTo(tmpRect) > 0) {
                cout << rects[i].height << " " << rects[i].width << endl;
                break;
            }
        }
    }
}

// End of Code
