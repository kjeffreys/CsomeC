/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kyle
 *
 * Created on October 13, 2018, 11:17 PM
 */

#include <stdio.h>
#include <stdlib.h>
/*
 * 
 */

void toupper(char* str)
{
    char* ptr = str;
    
    while(*ptr)
    {
        if(*ptr >= 97 && *ptr <= 122)
        *ptr = *ptr - 32;
        ptr++;
    }
}

void main()
{
    char text[] = "Some sample text";
    
    toupper(text);
    
    printf("%s", text);
}



