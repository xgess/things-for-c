#include <stdio.h>
#include <string.h>
#include <cs50.h>


#define NOT_A_LETTER -999


int char_to_int(char character) {
    int value;

    if (character >= 'a' && character <= 'z') {
        // lowercase
        value = character - 'a';
    } else if (character >= 'A' && character <= 'Z'){
        // uppercase
        value = character - 'A';
    } else {
        value = NOT_A_LETTER;
    }
    return value;
}


char encrypt_character(char key_character, char input) {
    char output;

    int k_value = char_to_int(key_character);

    if (input >= 'a' && input <= 'z') {
        // lowercase
        output = ((input - 'a') + k_value) % 26 + 'a';
    } else if (input >= 'A' && input <= 'Z'){
        // uppercase
        output = ((input - 'A') + k_value) % 26 + 'A';
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

    string keyword = argv[1];

    for (int i = 0; i < strlen(keyword); i++) {
        char c = keyword[i];
        if (char_to_int(c) == NOT_A_LETTER) {
            printf("Please try again with a key that includes only letters.\n");
            return 1;
        }
    }

    string input_string = GetString();

    int length_of_keyword = strlen(keyword);
    int length_of_input = strlen(input_string);
    int index_of_keyword = 0;

    for (int i = 0; i < length_of_input; i++) {
        char key_letter = keyword[index_of_keyword % length_of_keyword];
        char unencrypted_character = input_string[i];
        char encrypted_character = encrypt_character(key_letter, unencrypted_character);
        if (unencrypted_character == ' ' || unencrypted_character == ',' || unencrypted_character == '!') {
            // don't advance the key
        } else {
            index_of_keyword++;
        }
        printf("%c", encrypted_character);
    }

    printf("\n");
}
