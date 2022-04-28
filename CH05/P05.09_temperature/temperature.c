/* convert temperatures in Faberenheit to Celsius and Kelvin */
#include <stdio.h>
const double CON_1 = 5.0;
const double CON_2 = 9.0;
const double CON_3 = 32.0;
const double CON_4 = 273.6;

void Temperatures(double F_temp);

int main(void) {

    double Fah_temp;
    int status;     //remember the specifier for double type is "%lf"

    printf("Please enter a Fahrenheit temperature: ");
    status = scanf("%lf", &Fah_temp);

    while (status == 1){
        Temperatures(Fah_temp);
        printf("Please enter next Fahrenheit temperature(enter q to quit):");
        status = scanf("%lf", &Fah_temp);
    }
    printf("Done!");

    return 0;
}

void Temperatures(double F_temp) {
    double C_temp, K_temp;
    C_temp = CON_1 / CON_2 * (F_temp - CON_3);
    K_temp = C_temp + CON_4;
    printf("The temperatures are: %.2f Fahrenheit, %.2f Celsius, %.2f Kelvin\n", F_temp, C_temp, K_temp);
}
