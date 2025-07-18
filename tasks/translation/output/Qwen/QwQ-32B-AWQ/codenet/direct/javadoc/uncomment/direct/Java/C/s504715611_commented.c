#include <stdio.h>

int main() {
    char str[10];
    fgets(str, sizeof(str), stdin);
    if (str[2] == str[3] && str[4] == str[5]) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
// End of Code
