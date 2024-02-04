#include "q8_polynomial.h"

struct Node *createNode(float coeff, int exp){
    /* return a pointer to a new node with the given coefficient and exponent */
    // initialize a pointer to Node called newNode 
    // then allocate memory for the new node as size of Node
    // the (struct Node*) is a type cast to tell the compiler that the memory allocated is for a Node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL; // initialize the next pointer to NULL
    return newNode;
}

/*
legacy code for adding term to polynomial, doesn't insert in right place, not used in this implementation
void addTerm(struct Node** poly, int coeff, int exp){
    // we need a pointer to a pointer so that we can change the head of the list
    struct Node* newNode = createNode(coeff, exp); // create a pointer to newNode with the given coefficient and exponent
    newNode->next = *poly; // the pointer inside newNode now points to the current Node
    *poly = newNode; // what poly point to, i.e. current Node, now becomes the newNode
}
*/

void addTerm(struct Node** poly, int coeff, int exp){
    // we add a term and insert it in the right place based on the exponent
    // so the polynomial will always be sorted in decreasing order of exponent
    struct Node* newNode = createNode(coeff, exp); // create a pointerto newNode
    struct Node* current;
    // if the current list is empty or exponent of new term has higher order, insert newNode in the beginning
    if (*poly == NULL || exp > (*poly)->exp){
        newNode->next = *poly;
        *poly = newNode;
    }
    else { // locate the newnode in the right place
        current = *poly; // current become a copy of where poly points to, which is the original linked list
        // we use current to traverse the linked list
        while (current->next !=NULL && current->next->exp > exp){
            current = current->next;
        }
        if (current->next != NULL && current->next->exp == exp){
            // if the exponent already exist, just add the coefficient
            current->next->coeff += coeff;
            free(newNode); // free the memory allocated for newNode
        }
        else{
        newNode->next = current->next; 
        current->next = newNode;
        // this also modify the linked list that *poly(level1) points to, which is the original linked list (level0)
        }
    }
}

struct Node* multiplyPolynomial(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* tempPoly2 = poly2;
    // Multiply each term of poly1 with each term of poly2
    while (poly1 != NULL){
        while (poly2!=NULL){
            // fix term of poly1 and traverse through all terms of poly2
            addTerm(&result, poly1->coeff * poly2->coeff, poly1->exp + poly2->exp);
            poly2 = poly2->next;
        }
        poly1 = poly1->next;
        poly2 = tempPoly2; // reset poly2 to the beginning
    }
    return result;
}

/*
legacy code for evaluating polynomial term by term, not used in this implementation
float evaluate(struct Node* poly, float x){
    // evaluate polynomial term by term
    float result = 0;
    while (poly != NULL){ // while the current node not null
        result += poly->coeff * pow(x, poly->exp); // add the current term to the result
        poly = poly->next; // evaluate the next term
    }
    return result;
}
*/

float evaluate_horner(struct Node* poly, float x){
    // adjusted version so that it can handle polynomial with some zero coefficients
    // need to assume terms in decreasing order of exponent, which is handled by sortPolynomial
    float result = 0;
    // initialize current_exp to the exponent of the first term
    int current_exp = poly->exp;
    while (current_exp >= 0){
        if (poly != NULL && poly->exp == current_exp) {
            // if current exponent is the same as the the current term
            result = result * x + poly->coeff;
            poly = poly->next;
        } else {
            // else just multiply by x
            result = result * x;
        }
        current_exp--; // assume it is in decreasing order
    }
    return result;
}

/*
legacy code for sorting polynomial, not used in this implementation
void sortPolynomial(struct Node** poly) {
    // sort the polynomial in decreasing order of exponent
    // need a pointer to a pointer so that we can change where each node points to
    struct Node *ptr1, *ptr2;
    int tempCoeff, tempExp;

    ptr1 = *poly;
    while(ptr1 != NULL) {
        ptr2 = ptr1->next;
        while(ptr2 != NULL) {
            if(ptr1->exp < ptr2->exp) {
                tempCoeff = ptr1->coeff;
                tempExp = ptr1->exp;
                ptr1->coeff = ptr2->coeff;
                ptr1->exp = ptr2->exp;
                ptr2->coeff = tempCoeff;
                ptr2->exp = tempExp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
*/

struct Node* addPolynomial(struct Node* poly1, struct Node* poly2){
    // add two polynomials term by term and create a pointer to new polynomial
    struct Node* result = NULL; // initialize the result to NULL
    while (poly1 != NULL && poly2 != NULL){
        // if current node for poly1 has higher exponent then add its term to result
        if (poly1->exp>poly2->exp){
            addTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp<poly2->exp){
            addTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        else { // equal exponent
            addTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    // handle remaining term for poly1 & poly2
    while (poly1 != NULL){
        addTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL){
        addTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    //sortPolynomial(&result); // sort the result
    return result;
}

struct Node* subtractPolynomial(struct Node* poly1, struct Node* poly2){
    // subtract poly2 from poly1 by similar method as addPolynomial
    struct Node* result = NULL; // initialize the result to NULL
    while (poly1 != NULL && poly2 != NULL){
        // if current node for poly1 has higher exponent then add its term to result
        if (poly1->exp>poly2->exp){
            addTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp<poly2->exp){
            addTerm(&result, -poly2->coeff, poly2->exp); // minus poly2 term
            poly2 = poly2->next;
        }
        else { // equal exponent
            addTerm(&result, poly1->coeff - poly2->coeff, poly1->exp); // difference of poly1 and poly2 term
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    // handle remaining term for poly1 & poly2
    while (poly1 != NULL){
        addTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL){
        addTerm(&result, -poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    //sortPolynomial(&result); // sort the result
    return result;
}

void printPolynomial(struct Node *poly) {
    while(poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if(poly != NULL){ // if the next term is not null
            printf(" + ");
        }
    }
    printf("\n");
}