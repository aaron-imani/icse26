#include <stdio.h>

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) {
        // Handle input error if necessary
        return 1;
    }
    
    int hb = b / 2;
    // 文字列の入力
    // 出力
    printf("%d\n", a + hb);
    
    return 0;
}
// End of Code
