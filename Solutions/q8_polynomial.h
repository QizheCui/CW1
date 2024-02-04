#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int coeff; // could be a float but we use int for simplicity
    int exp;
    struct Node* next; // a pointer to the next node
};

struct Node *createNode(float coeff, int exp);
void addTerm(struct Node** poly, int coeff, int exp);
float evaluate_horner(struct Node* poly, float x);
struct Node* addPolynomial(struct Node* poly1, struct Node* poly2);
struct Node* subtractPolynomial(struct Node* poly1, struct Node* poly2);
struct Node* multiplyPolynomial(struct Node* poly1, struct Node* poly2);
void printPolynomial(struct Node *poly);