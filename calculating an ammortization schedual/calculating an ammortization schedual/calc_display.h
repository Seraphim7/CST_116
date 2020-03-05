//
// CST 116 - Assignment 3
//
// File : calc_display.h
//
// This file contains function prototypes that calculate loan monthly
// payments and display a row of an amortization table.
//

#ifndef CALC_DISPLAY_H
#define CALC_DISPLAY_H


static const int MONTHS_PER_YEAR = 12;


// Given the annual rate, return the monthly interest rate
double calc_monthly_rate(double annual_rate);


// Returns a monthly payment value calculated from values for
// principal, interest rate, (e.g. 5.8%), and loan duration (in years)
double calc_monthly_payment(double principal, double annual_rate, int num_years);


// Displays a row of the amortization schedule given the month number,
// principal amount for the month, interest due for the months, and
// the balance remaining.  The intent is for this function to be
// called for each loan payment made.
//
// The month number is a sequential number that tracks the number
// of payments:
//    1 - designates the first monthly payment
//    2 - designates the second monthly payment
//    3 - designates the third monthly payment
//    ...
//
// If the month number is one, the header for the table is
// displayed.
void display_month(unsigned month_num, double amt_principal, double amt_interest, double balance);


#endif
