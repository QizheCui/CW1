#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
float n = 0;
int count = 0;
float large = -INFINITY; // Initialize large to negative infinity
float small = INFINITY;  // Initialize small to positive infinity
while (n >= 0){
    printf("Please enter your input:\n"); /* update n */
    scanf("%f", &n); /* update n */
    count += 1;
    // update max and min
    if (n >= 0){
        if (n>=large){
            large = n;
        }
        if (n<=small){
            small = n;
        }
    }
}
if (count > 1){
    printf("Counts: %d\n", count-1); // need to minus 1 because start counting from 1
    printf("Largest: %f\n", large);
    printf("Smallest: %f\n", small);
    if (large == -INFINITY || small == INFINITY){ // not enough input provided
        printf("Range: 0\n");
    }
    else
    printf("Range: %f\n", large - small);
}
else{
    printf("No valid input provided.\n");
}
return EXIT_SUCCESS;
}