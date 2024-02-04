#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void SieveOfEratosthenes(int n){
    bool prime[n+1]; // initialize array to store prime [0,...,n]
    memset(prime,true,sizeof(prime)); // store every entry as true at first
    for (int p = 2; p * p <= n; p++){
        if (prime[p]){ // if number p is not marked, then marked all multiples
            for (int i = p * p; i<=n; i+=p){ // start with its square since all multiples smaller than its square have been marked
                prime[i] = false; // mark it
            }
        }
    }
    // print all unmarked integer
    for (int p = 2; p<= n; p++){
        if (prime[p]){
            printf("%d\n",p);
        }
    }
}

void SieveOfEratosthenes_Improved(int n){
    if (n >= 2)
    printf("%d\n",2); // include 2 back
    bool prime[n/2]; // initialize array to store prime [1,3,5...,n]
    memset(prime,true,sizeof(prime)); // store every entry as true at first
    for (int p = 3; p * p <= n; p+=2){ // skip multiples of 2
        if (prime[p/2 - 1]){ // if number p is not marked, then marked all multiples
            for (int i = p * p; i <= n; i += 2*p){ // start with its square since all multiples smaller than its square have been marked
                prime[i/2 -1] = false; // mark it
            }
        }
    }
    // print all unmarked integer
    for (int p = 3; p <= n; p+=2){
        if (prime[p/2 - 1]){
            printf("%d\n",p);
        }
    }
}
int main(){
    int N;
    printf("Please input your integer: ");
    scanf("%d", &N);
    printf("All primes up to %d are: \n", N);
    SieveOfEratosthenes_Improved(N); // either original or improved version
    return 0;
}