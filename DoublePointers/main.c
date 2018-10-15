/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kyle
 *
 * Created on October 14, 2018, 3:11 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int a , *b , **c , d ;
    a = 5 ;
    d = a + 1 ;
    b = &a ;
    c = &b;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("b dereferenced = %d\n", *b);
    printf("c = %d\n", c);
    printf("c dereferenced = %d\n", *c);
    printf("c 'doubly dereferenced' = %d\n", **c);
    printf("d = %d\nEnd Part a\n", d);
    printf("Address of a = %d\n", &a);
    printf("Address of b = %d\n", &b);
    printf("Address of c = %d\n", &c);
    printf("Address of d = %d\n", &d);
    printf("END PART A\n\n\n");
    // p a r t a
    *b = 8 ;
    b = &d ;
    **c = 3;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("b dereferenced = %d\n", *b);
    printf("c = %d\n", c);
    printf("c dereferenced = %d\n", *c);
    printf("c 'doubly dereferenced' = %d\n", **c);
    printf("d = %d\nEnd Part b\n", d);
    printf("address of a = %d", &a);
    printf("address of b = %d", &b);
    printf("address of a = %d", &a);
    printf("address of d = %d", &d);
    // p a r t b
    b++;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("b dereferenced = %d\n", *b);
    printf("c = %d\n", c);
    printf("c dereferenced = %d\n", *c);
    printf("c 'doubly dereferenced' = %d\n", **c);
    printf("d = %d\nEnd Part c\n\n", d);
    printf("address of a = %d\n", &a);
    printf("address of b = %d\n", &b);
    printf("address of a = %d\n", &a);
    printf("address of d = %d", &d);
    
// p a r t c
    return (EXIT_SUCCESS);
}

