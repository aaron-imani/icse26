#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int cnt = 0;
    bool flag = true;
    while(true) {
        flag = true;
        for(int i = 0; i < n; i++) {
            if(arr[i] % 2 != 0) {
                flag = false;
                break;
            } else {
                arr[i] = arr[i] / 2;
            }
        }
        if(flag == true)
            cnt++;
        else
            break;
    }
    printf("%d\n", cnt);
    return 0;
}
// End of Code
