// Alexander Burbank
// Due Date 2/25/17
// Assignment 3
// generates an amortization schedule out of given values

#include "calc_display.h"
#include <iostream>
#include  <iomanip>

using namespace std;

void DisplayAmortizationSchedule(double loanAmount, double interestRate, int years)
{
	double monthlyPrinciple;

	// sets variables to initial values
	double TotalBalance = 0, TotalInterest = 0;
	int monthsPerYear = 1;

	// calculating variables
	double monthlyInterestRate = calc_monthly_rate(interestRate);
	double balance = loanAmount;

	// for each month
	for (monthsPerYear = 1; monthsPerYear <= (MONTHS_PER_YEAR * years); monthsPerYear++)
	{
		double interestAmount = balance * monthlyInterestRate;

		TotalInterest = interestAmount + TotalInterest;

		double paymentAmount = calc_monthly_payment(loanAmount, interestRate, years);

		monthlyPrinciple = paymentAmount - interestAmount;

		balance -= monthlyPrinciple;

		if (balance < 0)
		{
			balance = 0;
		}

		TotalBalance = loanAmount + TotalInterest;

		// display row of info for a month
		display_month(monthsPerYear, monthlyPrinciple, interestAmount, balance);

		if (monthsPerYear == (MONTHS_PER_YEAR * years))
		{
			cout << "\nInterest paid  :  $" << TotalInterest; // displays the total interest paid
		}
		if (monthsPerYear == (MONTHS_PER_YEAR * years))
		{
			cout << "\n   Total paid  :  $" << TotalBalance; // displays balance paid
		}
	}
}

int main()
{
	// constants
	int const optionNumber1 = 1;
	int const optionNumber2 = 2;
	int const optionNumber3 = 3;
	int const optionNumber4 = 4;

	// variables
	int optionNumber;
	double loanAmount = 0;
	double interestRate = 0;
	int years = 0;


	cout << fixed << setprecision(2);

	while (optionNumber = 1, optionNumber <= 1)
	{
		cout << "\n\n";
		cout << "Loan Calculator" << endl;
		cout << "---------------\n\n";

		if (loanAmount != 0 && interestRate != 0 && years != 0)
		{
			cout << "\tMonthly payment  :  $" << calc_monthly_payment(loanAmount, interestRate, years) << endl;
		}
		else
		{
			cout << "\tMonthly payment  :  $" << endl;
		}
		cout << endl;

		cout << "1. Set principal        : " << "$" << loanAmount << endl;
		cout << "2. Set annual interest  : " << interestRate << "%" << endl;
		cout << "3. Set number of years  : " << years << endl;
		cout << "4. Amortization schedule" << endl;
		cout << "5. Exit" << endl;
		cout << endl;

		cout << "Enter Choice : ";
		cin >> optionNumber;

		while (optionNumber >= 6)
		{
			cout << "*** Invalid choice ***\n";

			cout << endl;

			cout << "Enter Choice : ";
			cin >> optionNumber;
		}
		if (optionNumber == 5)
		{
			break;
		}
		switch (optionNumber) // shows the menu options
		{
		case optionNumber1:
			cout << "\nEnter principal: ";
			cin >> loanAmount;
			break;

		case optionNumber2:
			cout << "\nEnter annual interest rate: ";
			cin >> interestRate;
			break;

		case optionNumber3:
			cout << "\nEnter number of years: ";
			cin >> years;
			break;

		case optionNumber4:
			DisplayAmortizationSchedule(loanAmount, interestRate, years);
			break;
		}
	}
}