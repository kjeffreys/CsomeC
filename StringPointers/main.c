/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kyle
 *
 * Created on October 13, 2018, 9:41 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    char *p = "hello", *s = "A better string!";
    
    p = s;
    
    printf("%c\n", p[2]);
    printf("%s\n", p);
    return (EXIT_SUCCESS);
}

