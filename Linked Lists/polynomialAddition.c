/*

# have two pointers pointing to expression1 and expression2 
  as 'ptr1' and 'ptr2'

# There are three distinct cases,

  - ptr1.exponent > ptr2.exponent 
      add ptr1 to result
      ptr1 <- ptr1.next

  - ptr1.exponent < ptr2.exponent
      add ptr2 to result
      ptr2 <- ptr2.next

  - ptr1.exponent == ptr2.exponent
      # Add the coeffecients of ptr1 & ptr2 and append to result
      ptr1 <- ptr1.next
      ptr2 <- ptr2.next


*/
#include <stdio.h>
#include <stdlib.h>

// Structure definition for a polynomial term
struct expression {
    int coefficient;
    int exponent;
    struct expression* next;
};

// Function declarations
void getInput(struct expression** exp);
void printLL(struct expression* expression);
struct expression* addPolynomials(struct expression* expr1, struct expression* expr2);

// Main function
int main() {
    struct expression* expression1 = NULL;
    struct expression* expression2 = NULL;
    struct expression* result = NULL;

    printf("Input for first polynomial:\n");
    getInput(&expression1);
    printf("Input for second polynomial:\n");
    getInput(&expression2);

    result = addPolynomials(expression1, expression2);

    printf("Resultant polynomial: ");
    printLL(result);

    return 0;
}

// Function to get input for the polynomial terms
void getInput(struct expression** exp) {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    struct expression* temp = NULL;
    struct expression* last = NULL;

    for (int i = 0; i < n; i++) {
        temp = (struct expression*)malloc(sizeof(struct expression));
        printf("Enter the coefficient: ");
        scanf("%d", &temp->coefficient);
        printf("Enter the exponent: ");
        scanf("%d", &temp->exponent);
        temp->next = NULL;

        // Add to the linked list
        if (*exp == NULL) {
            *exp = temp;  // First node
        } else {
            last->next = temp;  // Link previous node to new node
        }
        last = temp;  // Move last to new node
    }
}

// Function to print the polynomial linked list
void printLL(struct expression* expression) {
    while (expression != NULL) {
        printf("%dx^%d", expression->coefficient, expression->exponent);
        if (expression->next != NULL) {
            printf(" + ");
        }
        expression = expression->next;
    }
    printf("\n");
}
// Function to add two polynomials
struct expression* addPolynomials(struct expression* expr1, struct expression* expr2) {
    struct expression* result = NULL;
    struct expression* tail = NULL;

    while (expr1 != NULL || expr2 != NULL) {
      
        struct expression* temp = (struct expression*)malloc(sizeof(struct expression));

        if (expr1 != NULL && (expr2 == NULL || expr1->exponent > expr2->exponent)) {
            // Case 1: expr1 exponent is greater
            temp->coefficient = expr1->coefficient;
            temp->exponent = expr1->exponent;
            expr1 = expr1->next;
        } else if (expr2 != NULL && (expr1 == NULL || expr1->exponent < expr2->exponent)) {
            // Case 2: expr2 exponent is greater
            temp->coefficient = expr2->coefficient;
            temp->exponent = expr2->exponent;
            expr2 = expr2->next;
        } else {
            // Case 3: exponents are equal
            temp->coefficient = expr1->coefficient + expr2->coefficient;
            temp->exponent = expr1->exponent;
            expr1 = expr1->next;
            expr2 = expr2->next;
        }

        temp->next = NULL;

        if (result == NULL) {
            result = temp;  // First node in the result list
        } else {
            tail->next = temp;  // Link previous node to new node
        }
        tail = temp;  // Move tail to new node
    }

    return result;
}