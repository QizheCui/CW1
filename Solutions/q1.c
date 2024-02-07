#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a, b;
    printf("Please input character a and b.\n");
    scanf(" %c %c", &a, &b);
    
    printf("%c %c\n", b, a);
    return EXIT_SUCCESS;
}
