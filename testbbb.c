#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void led_set(int led, int state)
{
    char path[100];
    FILE *fp;

    snprintf(path, sizeof(path),
             "/sys/class/leds/beaglebone:green:usr%d/brightness",
             led);

    fp = fopen(path, "w");

    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fprintf(fp, "%d", state);
    fclose(fp);
}

int main(void)
{
    while (1)
    {
        /* ON */
        led_set(0, 1);
        led_set(1, 1);
        led_set(2, 1);
        led_set(3, 1);

        sleep(1);

        /* OFF */
        led_set(0, 0);
        led_set(1, 0);
        led_set(2, 0);
        led_set(3, 0);

        sleep(1);
    }

    return 0;
}