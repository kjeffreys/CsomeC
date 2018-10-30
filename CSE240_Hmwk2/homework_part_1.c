/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   homework_part_1.c
 * Author: Kyle Jeffreys
 *
 * Created on October 29, 2018, 1:56 PM
 */

#include <stdio.h>
#include <stdlib.h>

void initialize_array(int[] arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (i % 2 == 0) {
            *(arr + i) = 0;
        } else {
            *(arr + i) = 5;
        }
    }
}

void print_array(int[] arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    int a [10] = {3, 5, 6, 8, 12, 13, 16, 17, 18, 20};
    int b [6] = {18, 16, 19, 3, 14, 6};
    int c [5] = {5, 2, 4, 3, 1};

    // testing initialize_array
    print_array(a, 10); // print: 3, 5, 6, 8, 12, 13, 16, 17, 18, 20
    initialize_array(a, 10);
    print_array(a, 10); // print: 0, 5, 0, 5, 0, 5, 0, 5, 0, 5
    return (EXIT_SUCCESS);
}

