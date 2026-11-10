#include <stdio.h>

#define RUPEES_TO_PAISE(x) ((x) * 100)
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

static inline int square(int x)
{
    return x * x;
}

static inline int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int main(void)
{
    int a = 5;
    int b = 10;
    int i = 3;
    int j = 7;

    printf("Rupees to Paise: %d\n", RUPEES_TO_PAISE(a));

    printf("Square of a: %d\n", SQUARE(a));

    printf("Square of (a+1): %d\n", SQUARE(a + 1));

    printf("Maximum of a and b: %d\n", MAX(a, b));

    printf("Maximum using function: %d\n", maximum(a, b));

    printf("Square using inline function: %d\n", square(a));

    printf("Before increment: i = %d, j = %d\n", i, j);

    printf("Maximum of i and j: %d\n", MAX(i, j));

    printf("After maximum: i = %d, j = %d\n", i, j);

    return 0;
}