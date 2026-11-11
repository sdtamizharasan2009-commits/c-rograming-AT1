#include <stdio.h>

#define MAX_BILLS 5

int main()
{
    int previous, current;
    int units;
    int bill;
    int total = 0;
    int i;

    int test_previous[MAX_BILLS] = {1000, 2000, 3000, 4000, 5000};
    int test_current[MAX_BILLS]  = {1050, 2120, 3100, 4200, 5050};

    int limits[] = {100, 200};
    int rates[] = {2, 5, 8};
    int slabs = 3;

    printf("===== ELECTRICITY BILLING SYSTEM =====\n");

    for (i = 0; i < MAX_BILLS; i++)
    {
        previous = test_previous[i];
        current = test_current[i];

        if (current >= previous)
        {
            units = current - previous;
        }
        else if (previous > 60000 && current < 1000)
        {
            units = (65536 - previous) + current;
        }
        else
        {
            printf("Invalid meter reading!\n");
            continue;
        }

        bill = 0;

        if (units <= limits[0])
        {
            bill = units * rates[0];
        }
        else if (units <= limits[1])
        {
            bill = (limits[0] * rates[0]) +
                   ((units - limits[0]) * rates[1]);
        }
        else
        {
            bill = (limits[0] * rates[0]) +
                   ((limits[1] - limits[0]) * rates[1]) +
                   ((units - limits[1]) * rates[2]);
        }

        printf("\nBill %d\n", i + 1);
        printf("Previous Reading : %d\n", previous);
        printf("Current Reading  : %d\n", current);
        printf("Units Consumed   : %d\n", units);
        printf("Bill Amount      : Rs.%d\n", bill);

        total += bill;
    }

    printf("\n===== TOTAL COLLECTION =====\n");
    printf("Total Amount: Rs.%d\n", total);

    return 0;
}