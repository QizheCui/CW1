#include <stdio.h>
#include <stdlib.h>
int main(){ // equivalent to void
    printf("Input the two character: \n");
    char c1, c2;
    scanf(" %c %c", &c1, &c2); // put space before %c to consume any leading whitespace
    char temp = c1; // don't need to use the pointer since we don't need to modify the original input
    c1 = c2;
    c2 = temp;
    printf("the reversed output: %c %c \n",c1,c2);
    return EXIT_SUCCESS;
}