#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SER,
    EGR,
    CSE,
    EEE,
} SUBJECT;


// Structure of a course node
typedef struct CourseNode {
    SUBJECT subject;
    int courseCode;
    char teacher[1024];
    int creditHours;
    // this stores the address of next course node in the linked list
    struct CourseNode *next;
} CourseNode;


// maps number to subject
// used to print subject
const char* getSubject(SUBJECT subject)
{
   switch (subject)
   {
      case SER: return "SER";
      case EGR: return "EGR";
      case CSE: return "CSE";
      case EEE: return "EEE";
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
void course_insert(struct CourseNode** head, int subjectCode, int courseNumber, int credits, char *teacher){

    struct CourseNode *newNode, *current;
    newNode = (struct CourseNode*)malloc(sizeof(struct CourseNode));

    newNode->subject = subjectCode;
    newNode->courseCode = courseNumber;
    // newNode->teacher = malloc(1024);
    strcpy(newNode->teacher, teacher);
    newNode->creditHours = credits;

    // special case to insert data at head
    if (*head == NULL || (*head)->courseCode >= newNode->courseCode)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        // Locate node before the point of insertion
        current = *head;
        while (current->next!=NULL &&
               current->next->courseCode < newNode->courseCode)
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
    if (temp != NULL && temp->courseCode == courseNumber)
    {
        // head is changed
        *head = temp->next;
        free(temp);             
        return;
    }
  
    // keep track of previous node and search for the course to be deleted
    while (temp != NULL && temp->courseCode != courseNumber)
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
        printf("%s%d\t%d\t%s\n", getSubject(temp->subject), temp->courseCode, temp->creditHours, temp->teacher);
        temp = temp->next;
    }
}


int main(void) {


    int quit = 0;
    int subjectCode;
    int courseNumber;
    int credits;
    char teacher[1024];
    struct CourseNode *course_collection = NULL;
    // head = (struct CourseNode*)malloc(sizeof(struct CourseNode));

    while(quit == 0){


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
        char choice;
        scanf(" %c", &choice);


      
        switch (choice){

            case 'a':
                do{
                    printf("What is the subject? (SER=0, EGR=1, CSE=2, EEE=3)?\n");
                    scanf("%d", &subjectCode);
                    if (subjectCode <0 || subjectCode > 3)
                        printf("Enter number in range 0-3\n");
                    else
                        break;
                }while(1);
                printf("\n");
                printf("What is the number (e.g. 240)?\n");
                scanf("%d", &courseNumber);
                printf("\n"); printf("How many credits is the class (e.g. 3)?\n");
                scanf("%d", &credits);
                printf("\n"); printf("What is the name of the teacher?\n");
                scanf("%s", teacher);
                printf("\n");
                // printf("%d %d %d %s", subjectCode, courseNumber, credits, teacher);

                course_insert(&course_collection, subjectCode, courseNumber, credits, teacher);

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
                quit = 1;
                break;
            default:
                printf("ERROR! No such choice. PleaseEnter a valid choice.\n");
                break;
        }
    }
    // no memory leaks at the end
    free(course_collection);
    return 0;
}