// Alexander Burbank
// 3/8/17
// CST_116
// This program reads a student data from a file and then displays them

#include <iostream>
#include <fstream>
#include <iomanip>

using std::ifstream;
using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::setfill;
using std::ios;
using std::setprecision;

static const int FILENAME_LEN = 32;
static const int MAX_NAME_LEN = 16;

void DisplayHeader()
{
	cout << "Student          Gender  Percentage   Grade" << endl;
	cout << "---------------  ------  ----------   -----" << endl;
}

void GetFileName(char fileName[])
{
	cout << "enter the filename: ";
	cin >> fileName;
}

void DisplayInformation(char name[], char gender, double percentage, char grade)
{
	int male = 0;
	int female = 0;

	if (gender == 'M')
	{
		cout << setiosflags(ios::left) << setw(MAX_NAME_LEN) << name << " " << "Male" << setiosflags(ios::left) << "         " << setprecision(3) << percentage << "%" << "       " << grade << endl;
		male += male;
	}
	else
	{
		cout << setiosflags(ios::left) << setw(MAX_NAME_LEN) << name << " " << "Female" << setiosflags(ios::left) << "       " << setprecision(3) << percentage << "%" << "       " << grade << endl;
	}
}

double DetermineStudentPercentage(double studentGrades[], int students)
{
	double percentage = (studentGrades[0] + studentGrades[1] + studentGrades[2] + studentGrades[3] + studentGrades[4] + studentGrades[5]) / 6;

	return percentage;
}

char DetermineStudentGrade(double percentage)
{
	char grade = ' ';

	if (percentage >= 90 && percentage <= 100)
	{
		grade = 'A';
	}

	else if (percentage >= 80 && percentage < 90)
	{
		grade = 'B';
	}

	else if (percentage >= 70 && percentage < 80)
	{
		grade = 'C';
	}

	else if (percentage >= 60 && percentage < 70)
	{
		grade = 'D';
	}

	else
	{
		grade = 'F';
	}

	return grade;
}

void ProcessFileOpenError()
{
	cout << "failed" << endl;
}

void Gender(int genders)
{
	cout << "There are " << genders << endl;
}

void displayBottom(int males, int females, int students, double maleAVG, double femaleAVG, int numOfBoys, int numOfGirls)
{
	double percentageOfMales = 0.0;
	double percentageOfFemales = 0.0;
	double classAVG = 0.0;

	classAVG = (maleAVG + femaleAVG) / students;

	maleAVG = maleAVG / numOfBoys;
	femaleAVG = femaleAVG / numOfGirls;

	percentageOfMales = ((double)males / (double)students) * 100;
	percentageOfFemales = ((double)females / (double)students) * 100;

	cout << endl << "    # (%) Males: " << males << " (" << setprecision(3) << percentageOfMales << "%)" << endl << "  # (%) Females: " << females << " (" << setprecision(3) << percentageOfFemales << "%)" << endl;
	cout << endl << setprecision(3) << "    Male average: " << maleAVG << "%" << endl << setprecision(3) << "  Female average: " << femaleAVG << "%" << endl << setprecision(3) << "   Class average: " << classAVG << "%" << endl;
	cout << endl;
}

int main()
{
	int numOfMales = 0;
	int numOfFemales = 0;
	int i = 0;
	double maleAverage = 0;
	double femaleAverage = 0;
	double classAverage = 0;

	//Get the file name
	char fileName[FILENAME_LEN];
	GetFileName(fileName);

	ifstream classInformation;
	classInformation.open(fileName);

	if (classInformation.is_open())
	{
		cout << endl;

		//Get values from first line of file
		int numberOfStudents = 0;
		int numberOfGrades = 0;
		int totalScoreAvailable = 0;

		classInformation >> numberOfStudents
			>> numberOfGrades
			>> totalScoreAvailable;

		//Display the header of the output so each student piece of information can be displayed later

		DisplayHeader();

		//Declare accumulators

		while (i < numberOfStudents)
		{
			//Declare variables to be filled when reading a student record
			char studentName[MAX_NAME_LEN];
			char studentGender = ' ';
			double studentGrades[6]{ 0 };

			//Read student record and fill variables
			classInformation >> studentName
				>> studentGender
				>> studentGrades[0]
				>> studentGrades[1]
				>> studentGrades[2]
				>> studentGrades[3]
				>> studentGrades[4]
				>> studentGrades[5];

			//Display student information
			totalScoreAvailable = 600;

			double percentage = DetermineStudentPercentage(studentGrades, numberOfStudents);
			char grade = DetermineStudentGrade(percentage);
			DisplayInformation(studentName, studentGender, percentage, grade);

			//Tallies for percentages (accumulation)

			if (studentGender == 'M')
			{
				numOfMales = 1 + numOfMales;
				maleAverage = maleAverage + percentage;
			}
			if (studentGender == 'F')
			{
				numOfFemales = 1 + numOfFemales;
				femaleAverage = femaleAverage + percentage;
			}

			i++;
		}
		displayBottom(numOfMales, numOfFemales, numberOfStudents, maleAverage, femaleAverage, numOfMales, numOfFemales);
	}
	else
	{
		ProcessFileOpenError();
	}

	classInformation.close();

	return 0;
}