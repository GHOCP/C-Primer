// pe12-2a.c
// compile with pe12-2b.c
#include <stdio.h>
#include "pe12-2a.h"

static int mode = 0;
static double distance;
static double fuel_consumed;

void set_mode(int mode_inp) {
    if (mode_inp == 1)
        mode = 1;
    else if (mode_inp == 0)
        mode = 0;
    else {
        if (mode == 0)
            printf("Invalid mode specified. Mode 0(Metric) used.\n");
        else
            printf("Invalid mode specified. Mode 1(US) used.\n");
    }
}

void get_info() {
    if (mode == 0) {
        printf("Enter distance traveled in kilometers: ");
        // scanf("%lf", &distance);
        distance = get_double();
        printf("Enter fuel consumed in liters: ");
        // scanf("%lf", &fuel_consumed);
        fuel_consumed = get_double();
    }
    else {
        printf("Enter distance traveled in miles: ");
        // scanf("%lf", &distance);
        distance = get_double();
        printf("Enter fuel consumed in gallons: ");
        // scanf("%lf", &fuel_consumed);
        fuel_consumed = get_double();
    }
}

void show_info() {
    if (mode == 0)
        printf("Fuel consumption is %0.2lf liters per 100 km.\n", fuel_consumed / distance * 100);
    else
        printf("Fuel consumption is %0.2lf miles per gallon.\n", distance / fuel_consumed);
}

double get_double() {
    double n;
    while (scanf("%lf", &n) != 1) {
        while (getchar() != '\n')
            continue;
        printf("Wrong input! Please enter a number again:");
    }
    return n;
}

