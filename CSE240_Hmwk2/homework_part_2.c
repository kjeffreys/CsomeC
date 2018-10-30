/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   homework_part_2.c
 * Author: kyle
 *
 * Created on October 29, 2018, 2:51 PM
 */

#include <stdio.h>
#include <stdlib.h>

struct student
{
    char last_name[30];
    char first_name[30];
};

struct examination_seating
{
    struct student seating[][];
    int rows, cols;
};

void student_init_default(struct student *p)
{    
    strcpy(p->last_name, "###");
    strcpy(p->first_name, "###");
}

void student_init(struct student *p, char *info)
{
    char *token = strtok(info, "/");
    strcpy(p->first_name, token);
    token = strtok(NULL, "/");
    strcpy(p->last_name, token);
}

void student_to_string(struct student *p)
{
    printf("%c.%c. ", p->first_name[0], p->last_name[0]);
}

void examination_seating_init(int rowNum, int columnNum, struct examination_seating *t)
{
    
}

/*
 * 
 */
int main(int argc, char** argv)
{
    
    return (EXIT_SUCCESS);
}

