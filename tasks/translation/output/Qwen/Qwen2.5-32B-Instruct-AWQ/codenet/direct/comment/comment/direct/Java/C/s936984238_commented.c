#include <stdio.h>

int number;
int score[1000]; // Assuming the maximum number of elements is 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort() {
    for (int i = 0; i < number - 1; i++) {
        for (int j = 0; j < number - i - 1; j++) {
            if (score[j] > score[j + 1]) {
                swap(&score[j], &score[j + 1]);
            }
        }
    }
}

int read() {
    scanf("%d", &number);
    if (number == 0) return 0;

    for (int i = 0; i < number; i++) {
        scanf("%d", &score[i]);
    }
    return 1;
}

void solve() {
    sort();
    int sum = 0;
    for (int i = 1; i < number - 1; i++) {
        sum += score[i];
    }
    printf("%d\n", sum / (number - 2));
}

int main() {
    while (read()) {
        solve();
    }
    // End of Code
}
