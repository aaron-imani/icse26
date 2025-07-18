#include <stdio.h>
#include <math.h>

int main() {
    int inputNumber;
    scanf("%d", &inputNumber);

    double doubleCubed = pow(inputNumber, 3);
    int intCubed = (int)floor(doubleCubed);
    printf("%d\n", intCubed);

    return 0;
}
// End of Code
