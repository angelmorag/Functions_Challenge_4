//Angel Mora Gutierrez
// 2025-09-15
// This is a C++ program that manages a single student's grades.It allows the user to input grades, calculate the average, and determine a letter grade.
#include <iostream>
#include <limits>

using namespace std;

void inputGrades(double& g1, double& g2, double& g3);
double calculateAverage(const double g1, const double g2, const double g3);
char determineLetterGrade(const double average);
// Function prototypes

int main()
{
	double grade1 = 0, grade2 = 0, grade3 = 0;
	int choice = 0;

	do {
		cout << "\n=== Student Grades Management ===\n";
		cout << "1. Input Grades\n";
		cout << "2. Calculate and Display Average\n";
		cout << "3. Assign and Display Letter Grade\n";
		cout << "4. Exit\n";
		cout << "Select an option (1-4): ";
		cin >> choice;

		while (cin.fail() || choice < 1 || choice > 4) {
			cin.clear(); // clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
			cout << "Invalid input. Please enter a number between 1 and 4: ";
			cin >> choice;
		}
		switch (choice) {
		case 1:
			inputGrades(grade1, grade2, grade3);
			break;
		case 2:
			cout << "Average: " << calculateAverage(grade1, grade2, grade3) << endl;
			break;
		case 3:
			cout << "Letter Grade: " << determineLetterGrade(calculateAverage(grade1, grade2, grade3)) << endl;
			break;
		case 4:
			cout << "Exiting program." << endl;
			break;
		}
	} while (choice != 4);

	return 0;
}

void inputGrades(double& g1, double& g2, double& g3) {
	cout << "Enter grade 1: ";
	cin >> g1;
	while (cin.fail() || g1 < 0 || g1 > 100) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please enter a grade between 0 and 100: ";
		cin >> g1;
	}
	cout << "Enter grade 2: ";
	cin >> g2;
	while (cin.fail() || g2 < 0 || g2 > 100) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please enter a grade between 0 and 100: ";
		cin >> g2;
	}
	cout << "Enter grade 3: ";
	cin >> g3;
	while (cin.fail() || g3 < 0 || g3 > 100) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please enter a grade between 0 and 100: ";
		cin >> g3;
	}
}

double calculateAverage(const double g1, const double g2, const double g3) {
	return (g1 + g2 + g3) / 3.0;
}

char determineLetterGrade(const double average) {
	if (average >= 90) return 'A';
	else if (average >= 80) return 'B';
	else if (average >= 70) return 'C';
	else if (average >= 60) return 'D';
	else return 'F';
}
	// Function definitions