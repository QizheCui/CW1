#include "q5_sleepy.h"
#include <math.h>

int simplificationCheck(int top, int bot)
{
    int topFirstDigit = top / 10;
    int topSecondDigit = top % 10;
    int botFirstDigit = bot / 10;
    int botSecondDigit = bot % 10;
    
    int top_new = -1; 
    int bot_new = -1;

    if (topFirstDigit == botFirstDigit)
    {
        top_new = topSecondDigit;
        bot_new = botSecondDigit;
    } else if (topSecondDigit == botSecondDigit)
    {
        top_new = topFirstDigit;
        bot_new = botFirstDigit;
    } else if (topFirstDigit == botSecondDigit)
    {
        top_new = topSecondDigit;
        bot_new = botFirstDigit;
    } else if (topSecondDigit == botFirstDigit)
    {
        top_new = topFirstDigit;
        bot_new = botSecondDigit;
    }

    if (top_new != -1 && bot_new != -1 && bot_new != 0)  // There are valid digits to cancel
    {
        float result_new = (float)top_new / bot_new;
        float result = (float)top / bot;
        return fabs(result - result_new) < 0.0000001;
    } else
    {
        return 0;
    }
}
