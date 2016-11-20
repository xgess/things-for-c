#include <stdio.h>
#include <cs50.h>

// how to build: cc water.c -lcs50 -o water

int main(void) {
    printf("minutes: ");
    int length = GetInt();
    int minutes = length * 12;
    printf("That's %d bottles.\n", minutes);
}
