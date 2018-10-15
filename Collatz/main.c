/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kyle
 *
 * Created on October 14, 2018, 8:25 PM
 */

#include <stdio.h>
#include <stdlib.h>
int termination(int);
/*
 * 
 */
int main(int argc, char** argv) {
    int input;
    printf("Give an integer for Collatz conjecture check\n");
    scanf("%d", &input);
    printf("%d iterations are executed for this input", termination(input));
    return (EXIT_SUCCESS);
}

int termination(int input)
{
    int iterations = 0;
    
    while(input != 1)
    {
        if(input % 2 == 0)
        {
            input = input / 2;
        }
        else
        {
            input = (3*input) +1;
        }
        iterations++;
    }
    
    return iterations;
}

