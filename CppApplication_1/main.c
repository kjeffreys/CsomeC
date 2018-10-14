/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kyle
 *
 * Created on October 13, 2018, 7:45 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int n1 = 4, n2 = 8;
    
    int *pn1 = &n1, *pn2 = &n2;
    
    char c1 = 65, c2 = 66;
    
    char *pc1 = &c1, *pc2 = &c2;
    
    printf("n1 address = %d, n1 value = %d\n", pn1, *pn1);
    pn1 = pn1 + 1;
    printf("n1 address = %d, n1 value = %d\n", pn1, *pn1);
    
    
    printf("n2 address = %d, n2 value = %d\n", pn2, *pn2);
    
    printf("c1 address = %d, c1 value = %c\n", pc1, *pc1);
    pc1 = pc1 + 1;
    printf("c1 address = %d, c1 value = %c\n", pc1, *pc1);
    
    printf("c2 address = %d, c2 value = %c\n", pc2, *pc2);
    
    
    return (EXIT_SUCCESS);
}

