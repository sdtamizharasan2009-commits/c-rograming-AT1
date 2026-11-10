#include <stdio.h>

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
    char category[] = "Domestic";

    int units = currentReading - previousReading;

    long bill = compute_bill(units);
    long energyCharge = bill - FIXED_CHARGE_PAISE;

    printf("===== ELECTRICITY BILL =====\n");
    printf("Household Number : %d\n", householdNumber);
    printf("Previous Reading : %d\n", previousReading);
    printf("Current Reading  : %d\n", currentReading);
    printf("Category         : %s\n", category);
    printf("Units Consumed   : %d\n", units);

    printf("Energy Charge    : Rs. %ld.%02ld\n",
           energyCharge / 100, energyCharge % 100);

    printf("Fixed Charge     : Rs. %ld.%02ld\n",
           FIXED_CHARGE_PAISE / 100,
           FIXED_CHARGE_PAISE % 100);

    printf("Total Bill       : Rs. %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}

