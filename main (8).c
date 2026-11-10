#include <stdio.h>

#define SLAB1_UNITS 100
#define SLAB2_UNITS 200

#define RATE1_PAISE 0
#define RATE2_PAISE 225
#define RATE3_PAISE 450

#define FIXED_CHARGE_PAISE 5000L

long compute_bill(int units)
{
    long paise = FIXED_CHARGE_PAISE;

#ifdef DEBUG
    printf("[DEBUG] Initial fixed charge: %ld paise\n", paise);
#endif

    if (units > SLAB2_UNITS)
    {
        long slab3 = (long)(units - SLAB2_UNITS) * RATE3_PAISE;
        paise += slab3;

#ifdef DEBUG
        printf("[DEBUG] Slab 3 charge: %ld paise\n", slab3);
#endif
        units = SLAB2_UNITS;
    }

    if (units > SLAB1_UNITS)
    {
        long slab2 = (long)(units - SLAB1_UNITS) * RATE2_PAISE;
        paise += slab2;

#ifdef DEBUG
        printf("[DEBUG] Slab 2 charge: %ld paise\n", slab2);
#endif
    }

    return paise;
}

int main(void)
{
    int householdNumber = 101;
    int units = 350;

    long bill = compute_bill(units);

    printf("===== ELECTRICITY BILL =====\n");
    printf("Household Number: %d\n", householdNumber);
    printf("Units Consumed: %d\n", units);
    printf("Fixed Charge: Rs. 50.00\n");
    printf("Total Bill: Rs. %ld.%02ld\n",
           bill / 100, bill % 100);

    return 0;
}

/*
INPUT:
Household Number = 101
Units Consumed = 350

OUTPUT:
===== ELECTRICITY BILL =====
Household Number: 101
Units Consumed: 350
Fixed Charge: Rs. 50.00
Total Bill: Rs. 950.00
*/