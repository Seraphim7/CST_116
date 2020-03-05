// Alexander Burbank 
//	1/21/17
//	CST 116 - C++ Programming I
// Assignment 1 - Car Trip Calculations

#include <iostream>

using namespace std;

int main()
{
	int milesTotal;
	int milesTraveledPerGallon;
	double costPerGallon;
	int milesPerHour;
	int durationTraveled;
	int milesTraveledBetweenBreaks;
	double gallonsOfGasUsed;
	double totalFuelCost;
	int numberOfBreaksTaken;

	// get cost per gallon

	cout << "Enter the cost for a gallon of gas: $";
	cin >> costPerGallon;

	// get mpg

	cout << "Enter the miles per gallon of gas for the car: ";
	cin >> milesTraveledPerGallon;

	// get mph

	cout << "Enter the speed traveled (miles/hour): ";
	cin >> milesPerHour;

	// get duration

	cout << "Enter the time it took to get there (hours): ";
	cin >> durationTraveled;

	// get miles driven

	cout << "Enter the distance (miles) between breaks: ";
	cin >> milesTraveledBetweenBreaks;


	// calculate distance traveled
	milesTotal = milesPerHour * durationTraveled;

	// calculate gallons consumed
	gallonsOfGasUsed = milesTotal / milesTraveledPerGallon;

	// calculate cost for fuel of the trip
	totalFuelCost = gallonsOfGasUsed * costPerGallon;

	// calculate the number of breaks taken
	numberOfBreaksTaken = milesTotal / milesTraveledBetweenBreaks;


	// display seperation
	cout << endl;
	cout << "---" << endl;
	cout << endl;

	// display distance traveled
	// display cost of fuel consumed for the whole trip
	cout << "The car traveled " << milesTotal << " miles and required " << gallonsOfGasUsed << " gallons of gas." << endl;

	// display gallons consumed
	cout << "The total fuel cost for the trip was $" << totalFuelCost << "." << endl;

	// display the number of breaks taken
	cout << numberOfBreaksTaken << " breaks were taken." << endl;

	return 0;
}