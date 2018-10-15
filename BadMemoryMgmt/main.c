/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: kyle
 *
 * Created on October 14, 2018, 2:34 PM
 */

#include <stdio.h>
#include <stdlib.h>

int badfunction(int* num) {
    printf("num: %d\n", *num);
    *(num + 1) = 7;
}

/*
 *
 */
int main(int argc, char** argv) {
    int dont = 1;
    int attempt = 2;
    int thisWay = 3;
    printf("#1 dont : %d , do : %d , t h i s : %d\n", dont, attempt, thisWay);
    badfunction(&attempt);
    printf("#2 dont : %d , do : %d , t h i s : %d\n", dont, attempt,thisWay);
    return (EXIT_SUCCESS);
}
    

