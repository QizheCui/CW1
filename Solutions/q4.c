#include <stdio.h>
#include <stdlib.h>
void reversePrint() {
    char c = getchar(); // read single character from standard input
    if (c != '\n') { // check if c is not a newline character
        reversePrint(); // recursively call reversePrint() to keep reading next characters
        putchar(c); // print one character at a time
        // it doens't print until it reach newline chracter, then it prints reversely
    }
}

int main() {
    printf("Enter 200 characters: ");
    reversePrint();
    printf("\n");
    return 0;
}
