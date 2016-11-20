#include <stdio.h>
#include <string.h>
#include <cs50.h>

char upper(char character) {
    if (character >= 'a') {
        return 'A' + character - 'a';
    }
    return character;
}

int main(void) {
    string full_name = GetString();
    printf("%c", upper(full_name[0]));

    for (int i = 0; i < strlen(full_name); i++) {
        if (full_name[i] == ' ') {
            printf("%c", upper(full_name[i+1]));
        }
    }
    printf("\n");
}
