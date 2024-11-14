#include <stdio.h>

#define MAX_DEGREE 100

// Structure to represent a polynomial
typedef struct {
    int degree;
    int coeff[MAX_DEGREE];
} Polynomial;

// Function to print a polynomial
void printPolynomial(Polynomial p) {
    for (int i = p.degree; i >= 0; i--) {
        if (p.coeff[i] != 0) {
            if (i < p.degree &amp;&amp; p.coeff[i] > 0) printf("+");
            if (p.coeff[i] != 1 || i == 0) printf("%d", p.coeff[i]);
            if (i > 0) printf("x^%d", i);
        }
    }
    printf("\n");
}

// Function to calculate the GCD of two polynomials using Euclidean algorithm
Polynomial polynomialGCD(Polynomial p1, Polynomial p2) {
    Polynomial remainder;
    while (p2.degree >= 0) {
        remainder = polynomialDivision(p1, p2);
        p1 = p2;
        p2 = remainder;
    }
    return p1;
}

// Function to perform polynomial division (Implementation needed)
Polynomial polynomialDivision(Polynomial p1, Polynomial p2){
    Polynomial result;
    //Implementation needed
    return result;
}


int main() {
    Polynomial p1, p2, gcd_poly;
    int i;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &amp;p1.degree);
    printf("Enter the coefficients of the first polynomial:\n");
    for (i = p1.degree; i >= 0; i--) {
        scanf("%d", &amp;p1.coeff[i]);
    }

    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &amp;p2.degree);
    printf("Enter the coefficients of the second polynomial:\n");
    for (i = p2.degree; i >= 0; i--) {
        scanf("%d", &amp;p2.coeff[i]);
    }

    gcd_poly = polynomialGCD(p1, p2);
    printf("GCD of the polynomials is: ");
    printPolynomial(gcd_poly);

    return 0;
}
