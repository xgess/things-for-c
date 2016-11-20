#include <stdio.h>
#include <cs50.h>


int main(void) {
    double total=0.0;
    int coin_count = 0;
    double adjust_for_stupid_floats = 0.001;

    printf("O hai! ");
    do {
        printf("How much change is owed?\n");
        total = GetFloat();
    } while (total <= 0.0);

    while (total >= 0.25 - adjust_for_stupid_floats) {
        coin_count++;
        total = total - 0.25;
    }

    while (total >= 0.10 - adjust_for_stupid_floats) {
        coin_count++;
        total = total - 0.10;
    }

    while (total >= 0.05 - adjust_for_stupid_floats) {
        coin_count++;
        total = total - 0.05;
    }

    while (total >= 0.01 - adjust_for_stupid_floats) {
        coin_count++;
        total = total - 0.01;
    }

    printf("%d\n", coin_count);
}
