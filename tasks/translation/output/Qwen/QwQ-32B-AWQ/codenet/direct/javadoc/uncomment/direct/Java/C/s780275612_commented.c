#include <stdio.h>
#include <math.h>

int main() {
    int intA;
    scanf("%d", &intA);
    double dbAncer = pow((double)intA, 3);
    int intAncer = (int)dbAncer;
    printf("%d\n", intAncer);
    return 0;
}

// End of Code
