/*
    Polar coordinates describe a vector in terms of magnitude and the counterclockwise angle
    from the x-axis to the vector. Rectangular coordinates describe the same vector in terms
    of x and y components (see Figure 16.3 ). Write a program that reads the magnitude and
    angle (in degrees) of a vector and then displays the x and y components. The relevant
    equations are these:

    x = r cos A y = r sin A

    To do the conversion, use a function that takes a structure containing the polar
    coordinates and returns a structure containing the rectangular coordinates (or use
    pointers to such structures, if you prefer).
*/

#include <stdio.h>
#include <math.h>
#define DEG_TO_RAD ((4 * atan(1))/180)

typedef struct polar_co {
    double magnitude;
    double angle;       // in degrees
} POLAR_co;

typedef struct rect_co {
    double x;
    double y;
} RECT_co;

RECT_co polar_to_rect(POLAR_co);

int main(void) {

    POLAR_co polar;
    RECT_co rect;
    puts("Enter magnitude and angle(in degrees) coordinates; enter q to quit:");
    while (scanf("%lf %lf", &polar.magnitude, &polar.angle) == 2) {
        rect = polar_to_rect(polar);
        printf("x = %0.2lf  y = %0.2lf\n", rect.x, rect.y);
    }
    puts("BYE!");

    return 0;
}

RECT_co polar_to_rect(POLAR_co plo) {
    RECT_co rect;
    rect.x = plo.magnitude * cos(plo.angle * DEG_TO_RAD);
    rect.y = plo.magnitude * sin(plo.angle * DEG_TO_RAD);
    return rect;
}
