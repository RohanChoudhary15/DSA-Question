#include <stdio.h>

#define MAX_DEGREE 100

typedef struct {
    int degree;
    int coeff[MAX_DEGREE];
} Polynomial;

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

Polynomial polynomialDerivative(Polynomial p) {
    Polynomial derivative;
    derivative.degree = p.degree -1;
    for (int i = derivative.degree; i >= 0; i--) {
        derivative.coeff[i] = p.coeff[i+1] * (i+1);
    }
    return derivative;
}

int main() {
    Polynomial p, derivative_p;
    int i;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &amp;p.degree);
    printf("Enter the coefficients of the polynomial:\n");
    for (i = p.degree; i >= 0; i--) {
        scanf("%d", &amp;p.coeff[i]);
    }

    derivative_p = polynomialDerivative(p);
    printf("The derivative of the polynomial is: ");
    printPolynomial(derivative_p);

    return 0;
}
