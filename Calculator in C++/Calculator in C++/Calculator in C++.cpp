#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void SumCalculate(double num1, double num2)
{
	double sumOfNums = num1 + num2;
	
	cout << endl << "The sum is " << sumOfNums << endl << endl;
}

void DifferenceCalculate(double num1, double num2)
{
	double differenceOfNums = num1 - num2;

	cout << endl << "The difference is " << differenceOfNums << endl << endl;
}

void ProductCalculate(double num1, double num2)
{
	double productOfNums = num1 * num2;
	
	cout << endl << "The product is " << productOfNums << endl << endl;
}

void DivisionCalculate(double num1, double num2)
{
	double divisionOfNums = num1 / num2;

	if (num2 == 0)
	{
		cout << endl << "undefined" << endl << endl;
	}
	else
	{
		cout << endl << "The quotient is " << divisionOfNums << endl << endl;
	}
}

int main()
{
	double num1;
	double num2;
	char operation;

	cout << "This is a Calculator" << endl << endl << endl;

	cout << "Enter the First Number: ";
	cin >> num1;

	cout << "Enter the Second Number: ";
	cin >> num2;

	cout << "Enter Operation sign (Only + - * / allowed) Note: x or X instead of * for multiply is AOK: ";
	cin >> operation;

	if (operation == '+')
	{
		SumCalculate(num1, num2);
	}
	else if (operation == '-')
	{
		DifferenceCalculate(num1, num2);
	}
	else if (operation == '*' || operation == 'x' || operation == 'X')
	{
		ProductCalculate(num1, num2);
	}
	else if (operation == '/')
	{
		DivisionCalculate(num1, num2);
	}
	else
	{
		cout << "Who knows what that was!" << endl;
	}

	return 0;
}