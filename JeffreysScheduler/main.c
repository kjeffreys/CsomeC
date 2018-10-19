/**
 * This program represents a scheduler for college students.
 *
 * Completion time: (~4 hours)
 *
 * @author (Kyle Jeffreys), (Ruben Acuna)
 * @version (1.0)
 */

////////////////////////////////////////////////////////////////////////////////
//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
//DATA STRUCTURES

typedef enum {
    SER,
    EGR,
    CSE,
    EEE,
} Subject;


// Structure of a course node

typedef struct CourseNode {
    Subject subject;
    int courseCode;
    char teacher[1024];
    int creditHours;
    // this stores the address of next course node in the linked list
    struct CourseNode *next;
} CourseNode;

////////////////////////////////////////////////////////////////////////////////
//GLOBAL VARIABLES
int subjectID;
int courseNumber;
int credits;
char teacher[1024];
//place to store course information
struct CourseNode *course_collection = NULL;
////////////////////////////////////////////////////////////////////////////////

// Use a switch statement to map
// from an enumeration to a printf

const char* getSubject(Subject subject) {
    switch (subject) {
        case SER:
            return "SER";
        case EGR:
            return "EGR";
        case CSE:
            return "CSE";
        case EEE:
            return "EEE";
    }
}

int totalCredits(struct CourseNode *head) {
    int totalCredits = 0;
    struct CourseNode *temp = head;
    while (temp != NULL) {
        totalCredits = totalCredits + temp->creditHours;
        temp = temp->next;
    }
    return totalCredits;
}

void course_insert(struct CourseNode** head, int subjectCode, int courseNumber, int credits, char *teacher) {

    struct CourseNode *newNode, *current;
    newNode = (struct CourseNode*) malloc(sizeof (struct CourseNode));

    newNode->subject = subjectCode;
    newNode->courseCode = courseNumber;

    strcpy(newNode->teacher, teacher);
    newNode->creditHours = credits;


    if (*head == NULL || (*head)->courseCode >= newNode->courseCode) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        while (current->next != NULL &&
                current->next->courseCode < newNode->courseCode) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void course_drop(struct CourseNode **head, int courseNumber) {

    // Store head node
    struct CourseNode* temp = *head, *prev;

    // If head node itself holds the courseNumber to be deleted
    if (temp != NULL && temp->courseCode == courseNumber) {
        // head is changed
        *head = temp->next;
        free(temp);
        return;
    }

    // keep track of previous node and search for the course to be deleted
    while (temp != NULL && temp->courseCode != courseNumber) {
        prev = temp;
        temp = temp->next;
    }

    // If course not found
    if (temp == NULL) {
        printf("ERROR! Course %d doesn't exist\n", courseNumber);
        return;
    }
    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
    return;
}

void schedule_print(struct CourseNode *head) {

    struct CourseNode *temp = head;
    printf("Class Schedule:\n");
    while (temp != NULL) {
        printf("%s%d\t%d\t%s\n", getSubject(temp->subject), temp->courseCode, temp->creditHours, temp->teacher);
        temp = temp->next;
    }
}

int main(void) {
    char input_buffer;
    do {
        printf("\n\n");
        printf("Welcome to ASU Class Schedule\n\n");
        printf("Menu Options\n");
        printf("----------------------------------\n");
        printf("a: Add a class\n");
        printf("d: Drop a class\n");
        printf("s: Show your classes\n");
        printf("q: Quit\n\n");

        printf("Total credits: %d\n\n", totalCredits(course_collection));
        printf("Please enter a choice ---> ");
        scanf(" %c", &input_buffer);
        branching(input_buffer);

    } while (input_buffer != 'q');

    free(course_collection);
    return 0;
}

void branching(char option) {
    switch (option) {

        case 'a':
            do {
                printf("What is the subject? (SER=0, EGR=1, CSE=2, EEE=3)?\n");
                scanf("%d", &subjectID);
                if (subjectID < 0 || subjectID > 3) {
                    printf("Enter number in range 0-3\n");
                } else {
                    break;
                }
            } while (1);
            printf("\n");
            printf("What is the number (e.g. 240)?\n");
            scanf("%d", &courseNumber);
            printf("\n");
            printf("How many credits is the class (e.g. 3)?\n");
            scanf("%d", &credits);
            printf("\n");
            printf("What is the name of the teacher?\n");
            scanf("%s", teacher);
            printf("\n");

            course_insert(&course_collection, subjectID,
                    courseNumber, credits, teacher);

            break;

        case 'd':
            printf("Enter course number to delete: ");
            scanf("%d", &courseNumber);
            course_drop(&course_collection, courseNumber);
            break;
        case 's':
            schedule_print(course_collection);
            break;
        case 'q':
            printf(" Quitting the program\n\n");
            break;
        default:
            printf("ERROR! No such choice. PleaseEnter a valid choice.\n");
            break;
    }
}