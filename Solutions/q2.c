#include <stdio.h>
#include <stdlib.h>
int main(){
    int counta=0, countb=0, countc=0, countd=0, i;
    // for (initialization, condition, update), update is executed at the end of each loop
    for (i=10; i<=10; i++){ // execute when i<=10 and terminate when condition not met, so execute once
        counta += 1;
    }
    printf("(a): %d \n", counta);
    
    for (i=10; i<10; i++){ // never execute since condition not met
        countb += 1;
    }
    printf("(b): %d \n", countb);

    for (i=10; i>=1; i-=4){ // execute 3 times: 10->6->2
        countc += 1;
    }
    printf("(c): %d \n", countc);

    for (i=10; i==1; i-=4){ // never execute sinec i!=1
        countd += 1;
    }
    printf("(d): %d \n", countd);
    return EXIT_SUCCESS;
}