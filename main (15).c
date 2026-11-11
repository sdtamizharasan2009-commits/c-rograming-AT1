#include <stdio.h>
#include <limits.h>

#define MAX_BILLS 800000
#define MAX_METER_READING 65535
#define TARIFF_SLAB1 100
#define TARIFF_SLAB2 200

#define RATE1 200
#define RATE2 500
#define RATE3 800

int calculateBill(int units)
{
    int bill;

    if (units <= TARIFF_SLAB1)
    {
        bill = units * RATE1;
    }
    else if (units <= TARIFF_SLAB2)
    {
        bill = (TARIFF_SLAB1 * RATE1) +
               ((units - TARIFF_SLAB1) * RATE2);
    }
    else
    {
        bill = (TARIFF_SLAB1 * RATE1) +
               ((TARIFF_SLAB2 - TARIFF_SLAB1) * RATE2) +
               ((units - TARIFF_SLAB2) * RATE3);
    }

    return bill;
}

int main()
{
    int numberOfBills;
    int previousReading;
    int currentReading;
    int consumedUnits;
    int bill;
    int i;

    long long districtTotal = 0;

    printf("===== CO-OPERATIVE ELECTRICITY BILLING SYSTEM =====\n");

    printf("Maximum Bills: %d\n", MAX_BILLS);
    printf("Maximum Meter Reading: %d\n", MAX_METER_READING);

    printf("\n===== TARIFF DETAILS =====\n");
    printf("First 100 units : Rs.%d per unit\n", RATE1);
    printf("Next 100 units  : Rs.%d per unit\n", RATE2);
    printf("Above 200 units : Rs.%d per unit\n", RATE3);

    printf("\nEnter number of bills: ");

    if (scanf("%d", &numberOfBills) != 1 ||
        numberOfBills < 1 || numberOfBills > MAX_BILLS)
    {
        printf("Invalid number of bills!\n");
        return 1;
    }

    for (i = 1; i <= numberOfBills; i++)
    {
        printf("\n===== BILL %d =====\n", i);

        printf("Enter previous reading: ");

        if (scanf("%d", &previousReading) != 1 ||
            previousReading < 0 ||
            previousReading > MAX_METER_READING)
        {
            printf("Invalid previous reading!\n");
            return 1;
        }

        printf("Enter current reading: ");

        if (scanf("%d", &currentReading) != 1 ||
            currentReading < 0 ||
            currentReading > MAX_METER_READING)
        {
            printf("Invalid current reading!\n");
            return 1;
        }

        if (currentReading >= previousReading)
        {
            consumedUnits = currentReading - previousReading;
        }
        else if (previousReading > 60000 && currentReading < 1000)
        {
            consumedUnits = (MAX_METER_READING + 1 - previousReading)
                            + currentReading;
        }
        else
        {
            printf("Invalid meter reading sequence!\n");
            return 1;
        }

        bill = calculateBill(consumedUnits);

        districtTotal += bill;

        printf("Units Consumed: %d\n", consumedUnits);
        printf("Bill Amount: Rs.%d\n", bill);
    }

    printf("\n===== FINAL DISTRICT REPORT =====\n");

    printf("Total Bills Processed: %d\n", numberOfBills);
    printf("District Total: Rs.%lld\n", districtTotal);

    printf("\n===== FINAL DESIGN RECOMMENDATION =====\n");

    printf("1. int is used for meter readings and units.\n");
    printf("2. long long is used for district total.\n");
    printf("3. #define is used for tariff constants.\n");
    printf("4. Functions simplify billing calculations.\n");
    printf("5. Input validation prevents invalid readings.\n");

    printf("\n===== ALTERNATIVE CONCEPT =====\n");

    printf("Tariff values can be stored in a configuration file.\n");
    printf("The program reads tariff values during startup.\n");
    printf("Tariff changes do not require recompilation.\n");
    printf("Reading t tariff values requires O(t) time.\n");
    printf("Extra storage required is O(t).\n");

    printf("\n===== LIMITATIONS =====\n");

    printf("Tariff changes require updating constants.\n");
    printf("Configuration files must be validated.\n");
    printf("Long long has a maximum storage limit.\n");
    printf("Incorrect input must be rejected.\n");

    printf("\n===== COMPLEXITY ANALYSIS =====\n");

    printf("Time complexity per bill: O(1)\n");
    printf("Total time complexity: O(n)\n");
    printf("Extra space complexity: O(1)\n");

    printf("\n===== PROGRAM COMPLETED SUCCESSFULLY =====\n");

    return 0;
}