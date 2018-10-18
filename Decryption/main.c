/**
 * This program sorts strings according to numeric characters
 * in their 0th place. Additionally, it loops over the strings
 * and decrypts all characters (excluding 1st and null term.) 
 * by adding a defined offset.
 *
 * Completion time: (1.5 hr)
 *
 * @author (Kyle Jeffreys), (Ruben Acuna)
 * @version (1.0)
 */

////////////////////////////////////////////////////////////////////////////////
//INCLUDES
#include <stdio.h>
#include <string.h>

//macros: constants
#define CHUNK_LENGTH (20+1)  //each chunk has twenty characters, we add 1 so
//there is space for the null terminator.
#define NUMBER_OF_CHUNKS 4 //the message is spread across 4 chunks.
#define DECRYPTION_SHIFT 5 //this is the ASCII table shift used for decryption.

//forward declarations
void sort_chunks();
void decrypt_chunks();
void display_chunks();

char chunks[NUMBER_OF_CHUNKS][CHUNK_LENGTH];

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv) {

    //copy message into memory.
    strcpy(chunks[0], "2i1%fsi%fs%jstwrtzx%");
    strcpy(chunks[1], "1'H%nx%vznwp~1%kqf|j");
    strcpy(chunks[2], "4R3%Wnyhmnj%%%%%%%%%");
    strcpy(chunks[3], "3xzhhjxx3'%2%Ijssnx%");

    //the format of a chunk is a single number indicating its order in overall
    //message followed by twenty encrypted characters.


    //reorder chunks in message by sorting them based on the first digital
    //they contain. looking above, one can see they are currently in the order
    //2, 1, 4, 3 but should be ordered 1, 2, 3, 4.
    sort_chunks();

    //shift the characters in the message to produce the original characters.
    decrypt_chunks();

    //display the decrypted message.
    display_chunks();


    return 0;
}

//given two strings, swaps their contents in memory.

void swap_strings(char* x, char* y) {
    //create a temporary holding place for the data so we don't lose it.
    char temp[CHUNK_LENGTH];

    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}

//sorts the strings the global chunks variable by the first character they contain.

void sort_chunks() {
    //TODO: Implement sort_chunks(). Using your favorite sorting algorithm (we
    //      suggest selection sort), sort the array containing the message chunks.
    //      Sort based on the first character in the chunk - it will always be a
    //      number. We provide a swap_strings function that you may use. Example
    //      usage: swap_strings(chunks[0], chunks[1]) will swap the contents of
    //      the first and second string.
    int min, i, j, *p, *q;

    for (i = 0; i < NUMBER_OF_CHUNKS - 1; i++) {
        min = i; //set current index as minimum to compare against

        for (j = i + 1; j < NUMBER_OF_CHUNKS; j++) {
            if (chunks[j][0] < chunks[i][0]) {
                min = j;
                
            }

        }

        if (min != i) {
            swap_strings(chunks[i], chunks[min]);
        }
        
    }

}

//for each string in the global chunks variable, shifts the characters in it by
//DECRYPTION_SHIFT.

void decrypt_chunks() {
    //TODO: Implement decrypt_chunks(). Loop over each string in the array
    //      and shift the characters in it by subtracting DECRYPTION_SHIFT value
    //		from them. Use pointer arithmetic to access individual characters but
    //		array access to the strings. Remember that C-style strings have a null
    //		terminator at the end. Do not apply the shift to the terminator.
    //		(Hint: to avoid doing double pointer arithmetic, save a char* pointer
    //		to the active chunk[?] in the outer loop but before the inner loop.
    //		Then the inner loop is only concerned with a single array of
    //		characters rather than an array of strings.)
    char* p;
    int i, num;
    for (i = 0; i < NUMBER_OF_CHUNKS; i++) {
        p = &chunks[i][0];
        p++;
        int i = 0;
        for(; i < CHUNK_LENGTH-2;i++)   //-2 : ignoring first char and '/0'
        {
            *p = *p + 5;
            p++;
        }
    }
}


//displays the strings in the global chunks variable

void display_chunks() {
    //TODO: Implement display_chunks(). Loop over each string in the array of
    //      message chunks (strings) and print it. Do not print the first
    //      character in each string since it is only used to store the order of
    //      the chunks. (Hint: use pointer arithmetic to skip a character.)
    char* p;
    int i;
    for (i = 0; i < NUMBER_OF_CHUNKS; i++) {
        p = &chunks[i][0];
        p++;
        while (*p) {
            printf("%c", *p);
            p++;
        }
        printf("\n");
    }
}

