/**
 * Program that emulates interaction with courses
 * (e.g. Adding, deleting, viewing schedule)
 *
 * Completion time: (~2 hours)
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
    SER, EGR, CSE, EEE
} Subject;

typedef struct CourseNode {
    Subject subject;
    int courseNumber;
    char teacher[1024];
    int creditHours;
    struct CourseNode *next;
} CourseNode;


////////////////////////////////////////////////////////////////////////////////
//GLOBAL VARIABLES

//place to store course information
CourseNode *course_collection = NULL;

int subjectEnum;
int courseNumber;
char teacher[1024];
int creditHours;


////////////////////////////////////////////////////////////////////////////////
//FORWARD DECLARATIONS
void branching(char option);
const char* getSubject(Subject subject);
int totalCredits(struct CourseNode *head);
void course_insert(struct CourseNode** head, int subjectEnum, int courseNumber,
	int creditHours, char* teacher);

//main entry point. Starts the program by displaying a welcome and beginning an 
//input loop that displays a menu and processes user input. Pressing q quits.      

int main() {
    char input_buffer;
	

    printf("\n\nWelcome to ASU Class Schedule\n");

    //menu and input loop
    do {
        printf("\nMenu Options\n");
        printf("------------------------------------------------------\n");
        printf("a: Add a class\n");
        printf("d: Drop a class\n");
        printf("s: Show your classes\n");
        printf("q: Quit\n");
        //printf("\nTotal Credits: %d\n\n", totalCredits(course_collection));
        printf("Please enter a choice ---> ");

        scanf(" %c", &input_buffer);

        branching(input_buffer);
    } while (input_buffer != 'q');

    //free(course_collection);
    return 0;
}

//takes a character representing an inputs menu choice and calls the appropriate
//function to fulfill that choice. display an error message if the character is
//not recognized.

void branching(char option) {
    switch (option) {
        case 'a':
            printf("What is the subject? (SER=0, EGR=1, CSE=2, EEE=3)?\n");
            scanf("%d", &subjectEnum); 
            printf("\n");
			
            printf("What is the number (e.g. 240)?\n");
            scanf("%d", &courseNumber);
            printf("\n");
			
            printf("How many credits is the class (e.g. 3)?\n");
            scanf("%d", &creditHours);
            printf("\n");
			
            printf("What is the name of the teacher?\n");
            scanf("%s", teacher);
            printf("\n");
            // printf("%d %d %d %s", subjectEnum, courseNumber, creditHours, teacher);

            course_insert(&course_collection, subjectEnum, courseNumber, creditHours,
                    teacher);
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
            // main loop will take care of this.
            break;

        default:
            printf("\nError: Invalid Input.  Please try again...");
            break;
    }
}

//Using a switch statement to map
//from an enumeration to a printf
char* getSubject(Subject subject)
{
   switch (subject)
   {
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

//calculate total credits
int totalCredits(struct CourseNode *head)
{
    int totalCredits = 0;
    struct CourseNode *temp = head;
    while(temp != NULL)
    {
        totalCredits += temp->creditHours;
        temp = temp->next;
    }
    return totalCredits;
}

// insert course into linked list
void course_insert(struct CourseNode** head, int subjectEnum, int courseNumber, 
int creditHours, char *teacher){

    struct CourseNode *newNode, *current;
    newNode = (struct CourseNode*)malloc(sizeof(struct CourseNode));

    newNode->subject = subjectEnum;
    newNode->courseNumber = courseNumber;
    // newNode->teacher = malloc(1024);
    strcpy(newNode->teacher, teacher);
    newNode->creditHours = creditHours;

    // special case to insert data at head
    if (*head == NULL || (*head)->courseNumber >= newNode->courseNumber)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        // Locate node before the point of insertion
        current = *head;
        while (current->next!=NULL &&
               current->next->courseNumber < newNode->courseNumber)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void course_drop(struct CourseNode **head, int courseNumber){

    // Store head node
    struct CourseNode* temp = *head, *prev;

    // If head node itself holds the courseNumber to be deleted
    if (temp != NULL && temp->courseNumber == courseNumber)
    {
        // head is changed
        *head = temp->next;
        free(temp);             
        return;
    }
  
    // keep track of previous node and search for the course to be deleted
    while (temp != NULL && temp->courseNumber != courseNumber)
    {
        prev = temp;
        temp = temp->next;
    }

    // If course not found
    if (temp == NULL){
        printf("ERROR! Course %d doesn't exist\n", courseNumber);
        return;
    }
    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
    return;
}

void schedule_print(struct CourseNode *head){

    struct CourseNode *temp = head;
    printf("Class Schedule:\n");
    while(temp != NULL)
    {
        printf("%s%d\t%d\t%s\n", getSubject(temp->subject), 
			temp->courseNumber, temp->creditHours, temp->teacher);
        temp = temp->next;
    }
}

