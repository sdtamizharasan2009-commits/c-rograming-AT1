#include <stdio.h>

int main()
{
    int householdNumber = 101;
    int previousReading = 1530;
    int currentReading = 1850;
    int units;

    char category = 'D';

    double energyRate, fixedCharge;
    double energyCharge, totalBill;

    units = currentReading - previousReading;

    if (category == 'D' || category == 'd')
    {
        energyRate = 5.0;
        fixedCharge = 50.0;
    }
    else if (category == 'C' || category == 'c')
    {
        energyRate = 8.0;
        fixedCharge = 100.0;
    }
    else
    {
        printf("Invalid Category!");
        return 0;
    }

    energyCharge = units * energyRate;
    totalBill = energyCharge + fixedCharge;

    printf("===== ELECTRICITY BILL =====\n");
    printf("Household Number: %d\n", householdNumber);
    printf("Previous Reading: %d\n", previousReading);
    printf("Current Reading: %d\n", currentReading);
    printf("Category: %c\n", category);
    printf("Units Consumed: %d\n", units);
    printf("Energy Charge: Rs. %.2f\n", energyCharge);
    printf("Fixed Charge: Rs. %.2f\n", fixedCharge);
    printf("Total Bill: Rs. %.2f\n", totalBill);

    return 0;
}