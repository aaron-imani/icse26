#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class IntegralRect {
public:
    int height;
    int width;
    IntegralRect(int h, int w) : height(h), width(w) {}

    int diagonal() {
        if (height >= width) {
            return INT_MAX;
        }
        return height * height + width * width;
    }

    bool operator<(const IntegralRect& o) const {
        int d1 = diagonal();
        int d2 = o.diagonal();
        return d1 == d2 ? height < o.height : d1 < d2;
    }
};

int main() {
    IntegralRect rects[40000];
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects[i * 200 + j] = IntegralRect(i + 1, j + 1);
        }
    }
    sort(rects, rects + 40000);

    while (true) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int h, w;
        ss >> h >> w;

        if (h == 0 && w == 0) {
            break;
        }

        IntegralRect tmpRect(h, w);
        int diag = tmpRect.diagonal();
        for (int i = 0; i < 40000; i++) {
            if (rects[i] < tmpRect) {
                cout << rects[i].height << " " << rects[i].width << endl;
                break;
            }
        }
    }
    // End of Code
}
