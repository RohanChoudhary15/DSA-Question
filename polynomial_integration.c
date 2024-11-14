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

Polynomial polynomialIntegration(Polynomial p) {
    Polynomial integral;
    integral.degree = p.degree + 1;
    for (int i = integral.degree; i > 0; i--) {
        integral.coeff[i] = p.coeff[i - 1] / i;
    }
    integral.coeff[0] = 0; // Constant of integration is 0
    return integral;
}

int main() {
    Polynomial p, integral_p;
    int i;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &amp;p.degree);
    printf("Enter the coefficients of the polynomial:\n");
    for (i = p.degree; i >= 0; i--) {
        scanf("%d", &amp;p.coeff[i]);
    }

    integral_p = polynomialIntegration(p);
    printf("The indefinite integral of the polynomial is: ");
    printPolynomial(integral_p);

    return 0;
}
