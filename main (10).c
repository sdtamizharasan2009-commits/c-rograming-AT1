#include <stdio.h>
#include <limits.h>

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200

#define RATE2_PAISE 225
#define RATE3_PAISE 450

#define FIXED_CHARGE_PAISE 5000L

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

    if (units > SLAB2_UNITS)
    {
        paise += (long)(units - SLAB2_UNITS) * RATE3_PAISE;
        units = SLAB2_UNITS;
    }

    if (units > SLAB1_UNITS)
    {
        paise += (long)(units - SLAB1_UNITS) * RATE2_PAISE;
    }

    return paise;
}

int main(void)
{
    int householdNumber = 101;
    int previousReading = 1530;
    int currentReading = 1880;

    int units = currentReading - previousReading;

    long bill = compute_bill(units);
    long energyCharge = bill - FIXED_CHARGE_PAISE;

    float a = 0.1f;
    float b = 0.2f;

    printf("===== ELECTRICITY BILL =====\n");

    printf("Household Number : %d\n", householdNumber);
    printf("Previous Reading : %d\n", previousReading);
    printf("Current Reading  : %d\n", currentReading);
    printf("Units Consumed   : %d\n", units);

    printf("Energy Charge    : Rs. %ld.%02ld\n",
           energyCharge / 100, energyCharge % 100);

    printf("Fixed Charge     : Rs. %ld.%02ld\n",
           FIXED_CHARGE_PAISE / 100,
           FIXED_CHARGE_PAISE % 100);

    printf("Total Bill       : Rs. %ld.%02ld\n",
           bill / 100, bill % 100);

    printf("\n===== TYPE CONVERSION EXAMPLES =====\n");

    printf("1. Integer Division: 5 / 2 = %d\n", 5 / 2);

    printf("2. Floating Division: 5.0 / 2 = %.2f\n",
           5.0 / 2);

    printf("3. Float Precision: 0.1 + 0.2 = %.10f\n",
           a + b);

    printf("4. Explicit Casting: (double)5 / 2 = %.2f\n",
           (double)5 / 2);

    printf("5. Integer Paise: 16250 / 100 = %ld\n",
           16250L / 100);

    return 0;
}

