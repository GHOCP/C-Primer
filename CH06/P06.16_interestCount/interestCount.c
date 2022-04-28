/* calculate the investment */
#include<stdio.h>
#define INT1 0.1
#define INT2 0.05
#define DAPH_INV 100
#define DEIR_INV 100

int main(void) {

    int year = 0;
    double Daph_val, Deir_val;

    Daph_val = DAPH_INV;
    Deir_val = DEIR_INV;

    do {
        Daph_val = Daph_val + DAPH_INV * INT1;
        Deir_val = Deir_val + Deir_val * INT2;
        year++;
    } while (Daph_val > Deir_val);

    printf("It takes %d years for the value of Deirdre's investment to exceed the value of Daphne's,"
           "when Deirdre has %lf dollars, and Daphne has %lf dollars.", year, Deir_val, Daph_val);

    return 0;
}
