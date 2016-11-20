#include <stdio.h>
#include <string.h>
#include <cs50.h>


char encrypt(int k, char input) {
    char output;

    if (input >= 'a' && input <= 'z') {
        // lowercase
        output = ((input - 'a') + k) % 26 + 'a';
    } else if (input >= 'A' && input <= 'Z'){
        // uppercase
        output = ((input - 'A') + k) % 26 + 'A';
    } else {
        output = input;
    }
    return output;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("please rerun with a k.\n");
        return 1;
    }
    int k = atoi(argv[1]);
    string input_string = GetString();

    for (int i = 0, n = strlen(input_string); i < n; i++) {
        char encrypted_character = encrypt(k, input_string[i]);
        printf("%c", encrypted_character);
    }

    printf("\n");
    return 0;
}
