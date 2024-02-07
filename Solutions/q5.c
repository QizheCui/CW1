#include <stdio.h>
#include <stdlib.h>
#include "q5_sleepy.h"

int main()
{
    printf("Valid fractions includes:\n");
    for (int top = 10; top < 100; top++)
    {
        for (int bot = top + 1; bot < 100; bot++)
        {
            if (simplificationCheck(top, bot))
            {
                printf("(%d / %d)\n", top, bot);
                printf("(%d / %d)\n", bot, top);
            }
        }
    }
    return EXIT_SUCCESS;
}
