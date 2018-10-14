/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kyle
 *
 * Created on October 13, 2018, 9:47 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    char *p = 0;
    char ma[2][4];
    
    ma[0][0] = 'a';
    ma[0][1] = 'b';
    ma[0][2] = 'c';
    ma[0][3] = 'd';
    ma[1][0] = 'e';
    ma[1][1] = 'f';
    ma[1][2] = 'g';
    ma[1][3] = '\0';
    
    p = ma;
    
    while(*p)
    {
        printf("%c", *p);
        *p = *p + 1;    //encrypts by adding 1 to chars a to b, etc.
        p++;
    }
    
    p = ma;
    printf("\n");
    while(*p)
    {
        printf("%c", *p);
        p++;
    }
    return (EXIT_SUCCESS);
}

