// Alexander Burbank
// Due date 2/11/17
// CST-116
// Number Guessing Game

#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// variables
	double maximumNumber;
	int guess;
	int numberOfGuesses = 1;
	char playAgain;
	int close;
	int higherClose;
	int howManyGuessesAreAllowed;

	cout << "What's the maximum random number value: ";
	cin >> maximumNumber;	// stores the answer

	guess = (int)maximumNumber / 10;	// calculates what variable guess is
	close = 7 - guess;	// calculates what close is when refered to the low
	higherClose = 7 + guess;	// calculates what close is when refered to the high
	howManyGuessesAreAllowed = (int)log2(maximumNumber);	// calculates the number of guesses a user can make based from the maximum number

	if (howManyGuessesAreAllowed == 1)
	{
		cout << "You can do it in " << howManyGuessesAreAllowed << " guess\n";
	}
	else
	{
		cout << "You can do it in " << howManyGuessesAreAllowed << " guesses\n";
	}

	while (numberOfGuesses <= howManyGuessesAreAllowed)	// runs the loop the closest power of 2 to the maximum number Note: The program will not run this number of times if some conditions at the bottom of the program are not met.
	{
		cout << "Enter your guess: ";
		cin >> guess;	// stores the answer

		if (guess < close)
		{
			cout << "Too low." << endl;
		}
		else if (guess >= close && guess < 7)
		{
			cout << "Too low, but you're real close!" << endl;
		}
		else if (guess == 7)
		{
			if (numberOfGuesses == 1)
			{
				cout << "Correct. You got it in " << numberOfGuesses << " guess." << endl;
			}
			else
			{
				cout << "Correct. You got it in " << numberOfGuesses << " guesses." << endl;
			}
			cout << "Do you want to play again (y/n): ";
			cin >> playAgain;

			if (playAgain != 'n')
			{
				continue;
			}
			else
			{
				cout << "Thanks for playing." << endl;
				break;
			}
		}
		else if (guess > 7 && guess <= higherClose)
		{
			cout << "Too high, but you're real close!" << endl;
		}
		else if (guess > higherClose && guess <= maximumNumber)
		{
			cout << "Too high." << endl;
		}
		else
		{
			cout << "N/A" << endl; // If you put any values greater than the maximum value, you will get N/A
		}
		numberOfGuesses++;
	}
}