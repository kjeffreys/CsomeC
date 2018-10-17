/**
* Computation program that computes the total volume
 * for a number of cylinders. Heights and radii are
 * prompted for from the user.
*
* Completion time: (20 min)
*
* @author Kyle Jeffreys, Rubert Acuna
* @version (1.0)
*/

////////////////////////////////////////////////////////////////////////////////
//INCLUDES
#define PI 3.1415
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float getVolume(int h, int r) {
    return (PI * h * r * r); // V = PI*r^2*h
}

/*
 * 
 */
int main(int argc, char** argv) {

    int numEntered = 0;
    //Add a prompt for the number of cylinders to sum.
    printf("Enter number of cylinders to sum.\n");
    scanf("%d", &numEntered);

    int i = 0;
    float sum = 0;

    //Create a loop based on the number of cylinders the user enters.
    //    Within the loop, prompt for height and radius parameters (allow floating
    //    point numbers), and calculate the volume for that particular cylinder
    for (; i < numEntered; ++i) {
        float height, radius;

        printf("Enter height of cylinder %d\n", i);
        scanf("%f", &height);

        printf("Enter radius of cylinder %d\n", i);
        scanf("%f", &radius);


        sum = sum + getVolume(height, radius);
    }
    //Display the total volume sum back to the user.
    printf("Total sum of cylinder volumes is %f\n", sum);
    return 0;
}

