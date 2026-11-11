#include <stdio.h>
#include <limits.h>

#define MAX_BILLS 800000
#define MAX_METER_READING 65535
#define TARIFF_SLAB1 100
#define TARIFF_SLAB2 200

#define RATE1 200
#define RATE2 500
#define RATE3 800

#define PAISA_RATE1 20000
#define PAISA_RATE2 50000
#define PAISA_RATE3 80000

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
    int units;
    int bill;
    int i;

    long long districtTotal = 0;

    int previousReading;
    int currentReading;

    printf("===== CO-OPERATIVE ELECTRICITY BILLING SYSTEM =====\n");

    printf("Maximum Bills: %d\n", MAX_BILLS);
    printf("Meter Maximum: %d\n", MAX_METER_READING);

    printf("\n===== TARIFF DETAILS =====\n");
    printf("First 100 units  : Rs.%d per unit\n", RATE1);
    printf("Next 100 units   : Rs.%d per unit\n", RATE2);
    printf("Above 200 units  : Rs.%d per unit\n", RATE3);

    printf("\n===== ENTER BILL DETAILS =====\n");

    printf("Enter number of bills to calculate: ");
    if (scanf("%d", &units) != 1 || units < 1 || units > MAX_BILLS)
    {
        printf("Invalid number of bills!\n");
        return 1;
    }

    for (i = 1; i <= units; i++)
    {
        printf("\nBill %d\n", i);

        printf("Enter previous meter reading: ");
        if (scanf("%d", &previousReading) != 1 ||
            previousReading < 0 || previousReading > MAX_METER_READING)
        {
            printf("Invalid previous reading!\n");
            return 1;
        }

        printf("Enter current meter reading: ");
        if (scanf("%d", &currentReading) != 1 ||
            currentReading < 0 || currentReading > MAX_METER_READING)
        {
            printf("Invalid current reading!\n");
            return 1;
        }

        if (currentReading >= previousReading)
        {
            units = currentReading - previousReading;
        }
        else if (previousReading > 60000 && currentReading < 1000)
        {
            units = (MAX_METER_READING + 1 - previousReading)
                    + currentReading;
        }
        else
        {
            printf("Invalid meter reading sequence!\n");
            return 1;
        }

        bill = calculateBill(units);

        districtTotal += bill;

        printf("Units Consumed: %d\n", units);
        printf("Bill Amount: Rs.%d\n", bill);
    }

    printf("\n===== FINAL DISTRICT REPORT =====\n");
    printf("Total Bills Processed: %d\n", i - 1);
    printf("District Total: Rs.%lld\n", districtTotal);

    printf("\n===== DESIGN RECOMMENDATION =====\n");
    printf("int: Meter readings and individual units.\n");
    printf("long long: District-wide total amount.\n");
    printf("Macros: Tariff rates and fixed limits.\n");
    printf("Functions: Separate billing calculation.\n");
    printf("Arrays: Can store tariff slabs when required.\n");

    printf("\n===== ALTERNATIVE CONCEPT =====\n");
    printf("Tariff values can be stored in a configuration file.\n");
    printf("The program reads tariff values during startup.\n");
    printf("Changing tariffs does not require recompilation.\n");
    printf("Reading t tariff values takes O(t) time.\n");
    printf("Storing tariff values requires O(t) extra space.\n");

    printf("\n===== LIMITATIONS =====\n");
    printf("Tariff changes require updating configuration values.\n");
    printf("Invalid configuration files must be rejected.\n");
    printf("Long long has a maximum storage limit.\n");
    printf("Input validation is required for reliable billing.\n");

    return 0;
}