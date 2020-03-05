//
// CST 116 - Assignment 3
//
// File:  calc_display.cpp
//
// This file contains functions that calculate
// loan monthly payments and display a row of an
// amortization table.
//

#include <cmath>
#include <iomanip>
#include <iostream>
#include "calc_display.h"


// Returns the monthly interest rate based off of the annual rate
double calc_monthly_rate(double annual_rate)
{
    return annual_rate / (MONTHS_PER_YEAR * 100);
}

// Returns a monthly payment value calculated from values for
// principal, interest rate, (e.g. 5.8%), and loan duration (in years)
double calc_monthly_payment(double principal, double annual_rate, int num_years)
{
    double monthly_rate =  calc_monthly_rate(annual_rate);
    int    num_months   =  num_years * MONTHS_PER_YEAR;

    return (principal * monthly_rate) / (1 - std::pow(1 + monthly_rate, -num_months));
}

// Displays a row of the amortization schedule given the month number,
// principal amount for the month, interest due for the months, and
// the balance remaining.  The intent is for this function to be
// called for each loan payment made.
void display_month(unsigned month_num, double amt_principal, double amt_interest, double balance)
{
    using std::cout;
    using std::endl;
    using std::setw;

    char sep7[]  =  "-------";
    char sep11[] =  "-----------";

    if (month_num == 1) {
        cout  <<  endl  <<  endl
              <<  setw(7)   <<  "Year"
              <<  setw(7)   <<  "Month"
              <<  setw(11)  <<  "Principal"
              <<  setw(11)  <<  "Interest"
              <<  setw(11)  <<  "Balance"  <<  endl
              <<  setw(7)   <<  sep7
              <<  setw(7)   <<  sep7
              <<  setw(11)  <<  sep11
              <<  setw(11)  <<  sep11
              <<  setw(11)  <<  sep11  <<  endl;
    }

    cout  <<  setw(7)   <<  1 + (month_num-1) / 12
          <<  setw(7)   <<  1 + (month_num-1) % 12
          <<  setw(11)  <<  amt_principal
          <<  setw(11)  <<  amt_interest
          <<  setw(11)  <<  balance  <<  endl;

    ++month_num;
}
