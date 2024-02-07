#include <stdio.h>
#include <stdlib.h>

void inputAndPrintReverse(int count)
{
    if (count > 0)
    {
        char x;
        scanf("%c", &x);
        inputAndPrintReverse(count - 1);
        printf("%c", x);
    }
}

int main()
{
    int n = 200;
    printf("Enter %d characters.\n", n);
    inputAndPrintReverse(n);
    printf("\n");
    return EXIT_SUCCESS;
}
