/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"


bool linear_search(int value, int values[], int n) {
    for (int i = 0; i < n; i++) {
        if (values[i] == value) {
            return true;
        }
    }
    return false;
}

void insertion_sort(int values[], int n) {
    for (int i = 1; i < n; i++) {
        int insertable_value = values[i];

        for (int j = i; j >= 0; j--) {
            if (insertable_value < values[j]) {
                //slide the value at j to the right and plop in insertable_value
                values[j+1] = values[j];
                values[j] = insertable_value;
            }
        }
    }
}


bool search(int value, int values[], int n) {
    return linear_search(value, values, n)
}

void sort(int values[], int n)
{
    return insertion_sort(values, n);
}
