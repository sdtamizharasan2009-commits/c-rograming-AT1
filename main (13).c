#include <stdio.h>
#include <limits.h>
#include <float.h>

#define RATE 250
#define PAISA_RATE 25000

int main()
{
    int bills[] = {4000, 60000, 800000};
    int i;

    int int_total = 0;
    long long_total = 0;
    long long long_long_total = 0;

    float float_total = 0.0f;
    double double_total = 0.0;
    long long paise_total = 0;

    printf("===== ELECTRICITY BILLING TYPE COMPARISON =====\n");

    printf("\n===== DATA TYPE SIZES =====\n");
    printf("Size of int       : %zu bytes\n", sizeof(int));
    printf("Size of long      : %zu bytes\n", sizeof(long));
    printf("Size of long long : %zu bytes\n", sizeof(long long));
    printf("Size of float     : %zu bytes\n", sizeof(float));
    printf("Size of double    : %zu bytes\n", sizeof(double));

    printf("\n===== DATA TYPE RANGES =====\n");
    printf("INT_MAX       : %d\n", INT_MAX);
    printf("LONG_MAX      : %ld\n", LONG_MAX);
    printf("LLONG_MAX     : %lld\n", LLONG_MAX);
    printf("FLT_DIG       : %d\n", FLT_DIG);
    printf("DBL_DIG       : %d\n", DBL_DIG);

    for (i = 0; i < 3; i++)
    {
        int_total = 0;
        long_total = 0;
        long_long_total = 0;
        float_total = 0.0f;
        double_total = 0.0;
        paise_total = 0;

        int_total = bills[i] * RATE;
        long_total = (long long)bills[i] * RATE;
        long_long_total = (long long)bills[i] * RATE;

        float_total = (float)bills[i] * RATE;
        double_total = (double)bills[i] * RATE;
        paise_total = (long long)bills[i] * PAISA_RATE;

        printf("\n===== %d BILLS =====\n", bills[i]);

        printf("Integer Total       : %d\n", int_total);
        printf("Long Total          : %ld\n", long_total);
        printf("Long Long Total     : %lld\n", long_long_total);

        printf("Float Total         : %.2f\n", float_total);
        printf("Double Total        : %.2f\n", double_total);
        printf("Paise Total         : %lld\n", paise_total);

        printf("Paise in Rupees     : %.2f\n",
               (double)paise_total / 100.0);

        printf("Float Difference    : %.2f\n",
               (double)float_total -
               ((double)paise_total / 100.0));
    }

    printf("\n===== ALTERNATIVE CONCEPT =====\n");
    printf("Double uses floating-point representation.\n");
    printf("Long long stores whole-number totals.\n");
    printf("Paise calculation avoids decimal rounding.\n");
    printf("Integer types can overflow beyond their maximum range.\n");
    printf("Double can represent larger values but may lose precision.\n");

    return 0;
}