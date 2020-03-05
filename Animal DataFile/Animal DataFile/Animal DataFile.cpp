// Alexander Burbank
// 3/24/17
// CST_116 -- Introduction to C++ programming
// Assignment 5

// This assignment reads animal data from a file,
// then uses a menu that prompts a user for the choice they want,
// then the menu calls different functions to calculate and display the animal data
// based on the input from the user

#include <iostream>
#include <fstream>
#include <iomanip>

using std::ifstream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::setw;
using std::left;

#define MAX_FILE_NAME 32
#define MAX_NAME_LENGTH 21
#define MAX_TYPE_LENGTH 11
#define MAX_NUMBER_OF_ANIMALS 25

struct animalInfo
{
	char name[MAX_NAME_LENGTH];
	char type[MAX_TYPE_LENGTH];
	int age;
};

// Gets the file name
char* GetFileName(char filename[])
{
	cout << "Enter filename: ";
	cin >> filename;

	return filename;
}

// Formats output by displaying a blank line
void SkipLine()
{
	cout << endl;
}

// Displays the column headings of the animal data
void DisplayHeader()
{
	SkipLine();
	cout << "  Name                  Type        Age" << endl;
	cout << "  --------------------  ----------  ---" << endl;
}

// Displays the animal name, type, and age under the appropriate columns under the headers in DisplayHeader()
void DisplayAnimal(animalInfo animal)
{
	cout << "  ";
	cout << left << setw(20) << animal.name << "  ";
	cout << left << setw(10) << animal.type << "  ";
	cout << left << setw(3) << animal.age << endl;
}

// Displays the animal data in the order that it is seen in the data file
void DisplayInOriginalOrder(animalInfo originalListOfAnimals[], int numberOfAnimalsInFile)
{
	for (int i = 0; i < numberOfAnimalsInFile; i++)
	{
		DisplayAnimal(originalListOfAnimals[i]);
	}
}

// Displays the animal data opposite of that of the DisplayInOriginalOrder function
void DisplayInReverseOrder(animalInfo originalListOfAnimals[], int numberOfAnimalsInFile)
{
	for (int i = numberOfAnimalsInFile - 1; i >= 0; i--)
	{
		DisplayAnimal(originalListOfAnimals[i]);
	}
}

// Sorts the animals by age
void SortByAge(animalInfo listOfAnimalsToManipulate[], int numberOfAnimalsInFile)
{
	for (size_t i = 0; i < numberOfAnimalsInFile; i++)
	{
		for (size_t j = i + 1; j < numberOfAnimalsInFile; j++)
		{
			if (listOfAnimalsToManipulate[i].age > listOfAnimalsToManipulate[j].age)
			{
				animalInfo temp = listOfAnimalsToManipulate[i];
				listOfAnimalsToManipulate[i] = listOfAnimalsToManipulate[j];
				listOfAnimalsToManipulate[j] = temp;
			}
		}
	}
}

// Displays the animal data based by age
void DisplaySortedByAge(animalInfo listOfAnimalsToManipulate[], int numberOfAnimalsInFile)
{
	for (int i = 0; i < numberOfAnimalsInFile; i++)
	{
		DisplayAnimal(listOfAnimalsToManipulate[i]);
	}
}

// Calculates the average age of the animals
float CalculateAverageAge(int numberOfAnimalsInFile, int sumOfAges)
{
	return (float)sumOfAges / (float)numberOfAnimalsInFile;
}

// Displays the average age
void DisplayAverageAge(float averageAge)
{
	cout << "  The average animal age is " << setprecision(3) << averageAge << " years.";
}

// Displays the oldest animal in the file
void DisplayOldest(char* oldestAnimal)
{
	cout << oldestAnimal << " is the oldest.";
}

// Displays the youngest animal in the file
void DisplayYoungest(char* youngestAnimal)
{
	cout << youngestAnimal << " is the youngest.";
}

// Displays a menu of options that a user can choose
void DisplayMenu(animalInfo  originalListOfAnimals[], animalInfo listOfAnimalsToManipulate[], int numberOfAnimalsInFile,
	char oldestAnimal[], char youngestAnimal[], int sumOfAges)
{
	const char firstCase = '1';
	const char secondCase = '2';
	const char thirdCase = '3';
	const char fourthCase = '4';
	const char fifthCase = '5';
	const char sixthCase = '6';
	const char quitCase = 'q';
	char menuOption = ' ';

	while (menuOption != 'q')
	{
		if (!(menuOption > '6'))
		{
			cout << endl << "Menu:" << endl;
			cout << "  1 - display all the animals in forward order" << endl;
			cout << "  2 - display all the animals in reverse order" << endl;
			cout << "  3 - display all animals sorted by age(youngest first)" << endl;
			cout << "  4 - determine the average animal age" << endl;
			cout << "  5 - determine which animal is oldest" << endl;
			cout << "  6 - determine which animal is youngest" << endl;
			cout << "  q - quit the program" << endl;
		}
		cout << "Choice: ";
		cin >> menuOption;

		switch (menuOption)
		{
		case firstCase:
		{
			DisplayHeader();
			DisplayInOriginalOrder(originalListOfAnimals, numberOfAnimalsInFile);
			break;
		}
		case secondCase:
		{
			DisplayHeader();
			DisplayInReverseOrder(originalListOfAnimals, numberOfAnimalsInFile);
			break;
		}
		case thirdCase:
		{
			DisplayHeader();
			SortByAge(listOfAnimalsToManipulate, numberOfAnimalsInFile);
			DisplaySortedByAge(listOfAnimalsToManipulate, numberOfAnimalsInFile);
			break;
		}
		case fourthCase:
		{
			float averageAge = CalculateAverageAge(numberOfAnimalsInFile, sumOfAges);
			SkipLine();
			DisplayAverageAge(averageAge);
			SkipLine();
			break;
		}
		case fifthCase:
		{
			SkipLine();
			DisplayOldest(oldestAnimal);
			SkipLine();
			break;
		}
		case sixthCase:
		{
			SkipLine();
			DisplayYoungest(youngestAnimal);
			SkipLine();
			break;
		}
		case quitCase:
		{
			return;
		}
		default:
		{
			cout << "    " << "Error: Invalid Option" << endl << endl;
		}
		}
	}
}

// Character by Character assignment of animal's name into cString
void AssignAnimalName(char destinationName[], char sourceName[])
{
	for (int i = 0; i < MAX_NAME_LENGTH; i++)
	{
		destinationName[i] = sourceName[i];
	}
}

// Reads the file to get the animal data and stores it into two identical arrays
int ReadTheFileToGetTheData(char filename[], animalInfo  originalListOfAnimals[], animalInfo  ListOfAnimalsToManipulate[],
	char oldestAnimal[], char youngestAnimal[], int & sumOfAges)
{
	int numberOfAnimalsInFile = 0;

	ifstream animalFile;
	animalFile.open(filename);

	if (animalFile.is_open())
	{
		int elementCounter = 0;
		int oldestAge = 0;
		int youngestAge = 0;
		bool firstAnimal = true;

		// numberOfAnimalsInFile needs to be 0 based in case there are no animals in the file
		while (!animalFile.eof() && numberOfAnimalsInFile < 25)
		{
			numberOfAnimalsInFile++;

			animalInfo animalData;
			animalFile >> animalData.name >> animalData.type >> animalData.age;

			originalListOfAnimals[elementCounter] = animalData;
			ListOfAnimalsToManipulate[elementCounter] = animalData;

			if (firstAnimal)
			{
				AssignAnimalName(oldestAnimal, animalData.name);
				oldestAge = animalData.age;

				AssignAnimalName(youngestAnimal, animalData.name);
				youngestAge = animalData.age;
			}
			else
			{
				if (animalData.age > oldestAge)
				{
					AssignAnimalName(oldestAnimal, animalData.name);
					oldestAge = animalData.age;
				}
				if (animalData.age < youngestAge)
				{
					AssignAnimalName(youngestAnimal, animalData.name);
					youngestAge = animalData.age;
				}
			}

			sumOfAges += animalData.age;

			firstAnimal = false;
			elementCounter++;
		}
	}
	else
	{
		cout << "The file " << "'" << filename << "'" << " does not exist" << endl;
	}

	return numberOfAnimalsInFile;
}

// Acts as the main controller of the program
int main()
{
	int sumOfAges = 0;
	char oldestAnimal[MAX_NAME_LENGTH];
	char youngestAnimal[MAX_NAME_LENGTH];
	char filename[MAX_FILE_NAME];
	GetFileName(filename);

	animalInfo originalListOfAnimals[MAX_NUMBER_OF_ANIMALS];
	animalInfo ListOfAnimalsToManipulate[MAX_NUMBER_OF_ANIMALS];

	int numberOfAnimalsInFile = ReadTheFileToGetTheData(filename, originalListOfAnimals, ListOfAnimalsToManipulate,
		oldestAnimal, youngestAnimal, sumOfAges);

	if (numberOfAnimalsInFile > 0)
	{
		DisplayMenu(originalListOfAnimals, ListOfAnimalsToManipulate, numberOfAnimalsInFile, oldestAnimal, youngestAnimal,
			sumOfAges);
	}

	return 0;
}