#include <stdio.h>
#include <limits.h>
#include <float.h>

typedef unsigned short meter_t;

unsigned int consumption(meter_t previous, meter_t current)
{
    return (meter_t)(current - previous);
}

int main(void)
{
    meter_t previousReading = 65400;
    meter_t currentReading = 120;

    printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n",
           sizeof(meter_t), (unsigned)USHRT_MAX);

    printf("Consumption: %u units\n",
           consumption(1200, 1530));

    printf("Consumption: %u units\n",
           consumption(previousReading, currentReading));

    return 0;
}