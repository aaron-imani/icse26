#include <iostream>
#include <vector>
#include <algorithm>

struct IntegralRect {
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
        if (d1 < d2) return true;
        if (d1 > d2) return false;
        return height < other.height;
    }
};

int main() {
    std::vector<IntegralRect> rects(40000);
    int index = 0;
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            rects[index] = IntegralRect(i + 1, j + 1);
            index++;
        }
    }
    std::sort(rects.begin(), rects.end());
    
    while (true) {
        int h, w;
        std::cin >> h >> w;
        if (h == 0 && w == 0) break;
        
        IntegralRect tmpRect(h, w);
        for (int i = 0; i < 40000; i++) {
            if (rects[i] > tmpRect) {
                std::cout << rects[i].height << " " << rects[i].width << std::endl;
                break;
            }
        }
    }
    return 0;
}
// End of Code
