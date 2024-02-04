#include "q8_polynomial.h"

int main() {
    struct Node *poly1 = NULL; // initialize a pointer to a polynomial
    struct Node *poly2 = NULL; // initialize a pointer to a polynomial
    // i add terms not in increasing order of exponent on purpose
    addTerm(&poly1, 2, 0);
    addTerm(&poly1, 5, 1);
    addTerm(&poly1, 4, 4);
    addTerm(&poly1, 4, 3);
    addTerm(&poly1, 2, 3); // repeat the exponent 3 to test consisteny
    printf("Polynomial 1: ");
    printPolynomial(poly1);
    // create a second polynomial
    addTerm(&poly2, 3, 1);
    addTerm(&poly2, 1, 3);
    addTerm(&poly2, 2, 2);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    // add & subtract the two polynomials
    struct Node *poly3 = addPolynomial(poly1, poly2);
    printf("Polynomial 1 + Polynomial 2:");
    printPolynomial(poly3);
    struct Node *poly4 = subtractPolynomial(poly1, poly2);
    printf("Polynomial 1 - Polynomial 2:");
    printPolynomial(poly4);
    printf("Polynomial 1 * Polynomial 2:");
    struct Node *poly5 = multiplyPolynomial(poly1, poly2);
    printPolynomial(poly5);
    printf("Polynomial 1 value at x = 2 : %f\n", evaluate_horner(poly1, 3));
    return 0;
}