#include <stdio.h>
#include <cs50.h>


int main(void) {
    int height, width;

    do {
        printf("Height: ");
        height = GetInt();
    } while (height < 0 || height > 23);

    width = height + 1;

    for (int row = 1; row <= height; row++) {
        int number_of_spaces = width - row;
        int number_of_hashes = width - number_of_spaces + 1;

        for (int space=2; space <= number_of_spaces; space++) {
            printf(" ");
        }

        for (int hash = 1; hash <= number_of_hashes; hash++) {
            printf("#");
        }
        printf("\n");
    }
}
