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

    static bool compare(const IntegralRect& a, const IntegralRect& b) {
        int d1 = a.diagonal();
        int d2 = b.diagonal();
        return d1 == d2 ? a.height < b.height : d1 < d2;
    }
};

int main() {
    vector<IntegralRect> rects(40000);
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects[i * 200 + j] = IntegralRect(i + 1, j + 1);
        }
    }
    sort(rects.begin(), rects.end(), IntegralRect::compare);

    while (true) {
        int h, w;
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        }
        IntegralRect tmpRect(h, w);
        int diag = tmpRect.diagonal();
        for (int i = 0; i < rects.size(); i++) {
            if (IntegralRect::compare(rects[i], tmpRect)) {
                cout << rects[i].height << " " << rects[i].width << endl;
                break;
            }
        }
    }
    // End of Code
}
