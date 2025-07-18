#include <stdio.h>
#include <math.h>

int main() {
    // Scanner equivalent in C
    // Using stdin for input
    int intA;
    scanf("%d", &intA);

    // Calculate power and cast to int
    double dbAncer = pow(intA, 3);
    int intAncer = (int)dbAncer;
    printf("%d\n", intAncer);
    return 0;
}
// End of Code
