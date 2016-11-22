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


bool binary_search(int target, int values[], int left_index, int right_index) {
    int middle_index = (right_index + left_index) / 2;

    if (target == values[middle_index]) {
        // found it :)
        return true;
    } else if (right_index == left_index) {
        // not gonna find it :(
        return false;
    } else if (target < values[middle_index]) {
        // recurse with the left half
        return binary_search(target, values, left_index, middle_index - 1);
    } else if (target > values[middle_index]) {
        // recurse with the right half
        return binary_search(target, values, middle_index+1, right_index);
    }
    return false;
}

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
    return binary_search(value, values, 0, n-1);
}

void sort(int values[], int n) {
    return insertion_sort(values, n);
}
