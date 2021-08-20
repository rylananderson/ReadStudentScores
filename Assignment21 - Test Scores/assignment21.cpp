#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int S = 3; // S = students
const int T = 4; // T = tests

// function prototypes
void getTests(double [][T]);
double totalTests(double [][T]);
double averageTest(double);
void averageEachTest(double [][T]);
void averageEachStudent(double [][T]);
double getHighest(double [][T]);
void getHighestOfEachTest(double [][T]);
void getLowestOfEachStudent(double [][T]);
void report(double [][T]);


int main()
{
	// declare array
	double scores[S][T];

	// function calls
	getTests(scores);
	report(scores);


	return 0;
}

//*****************************************************************************************************
// Open file and read in data. Store data in the scores array
void getTests(double scores[][T])
{
	fstream inFile;
	inFile.open("test.txt");

	// check to see if file is open
	if (!inFile)
	{
		cout << "Error: Can't open file" << endl;
		exit(1);
	}

	for (int stu = 0; stu < S; stu++)
	{
		for (int test = 0; test < T; test++)
		{
			inFile >> scores[stu][test];
		}
	}
}

//*****************************************************************************************************
// add up all of the scores and return the total
double totalTests(double scores[][T])
{
	double total = 0;

	for (int stu = 0; stu < S; stu++)
	{
		for (int test = 0; test < T; test++)
		{
			total += scores[stu][test];
		}
	}
	return total;
}

//*****************************************************************************************************
// Find the average and return it. Must take total as an argument
double averageTest(double tol)
{
	double average = tol / (S * T);
	return average;

}

//*****************************************************************************************************
// Average each score from each test 
void averageEachTest(double scores[][T])
{
	double average = 0,
		   total = 0;

	for (int test = 0; test < T; test++)
	{
		total = 0; // for each test
		for (int stu = 0; stu < S; stu++)
		{
			total += scores[stu][test];
			average = total / S;
		}
		cout << "Average for Test # " << test + 1 << ": ";
		cout << average << endl;
	}
	cout << "Press Enter to Continue..." << endl;
	cin.get();

}

//*****************************************************************************************************
// Find each student's average from the 4 test scores
void averageEachStudent(double scores[][T])
{
	double average,
		   total = 0;

	for (int stu = 0; stu < S; stu++)
	{
		total = 0;
		for (int test = 0; test < T; test++)
		{
			total += scores[stu][test];
			average = total / T;
		}
		cout << "Average for Student # " << stu + 1 << ": ";
		cout << average << endl;
	}
	cout << "Press Enter to Continue..." << endl;
	cin.get();
}

//*****************************************************************************************************
// Find the highest score
double getHighest(double scores[][T])
{
	double highest = 0;
	highest = scores[0][0];

	for (int stu = 0; stu < S; stu++)
	{
		for (int test = 0; test < T; test++)
		{
			if (scores[stu][test] > highest)
			{
				highest = scores[stu][test];
			}
		}
	}
	return highest;
}

//*****************************************************************************************************
// From each test column, find the highest score
void getHighestOfEachTest(double scores[][T])
{
	double highest = scores[0][0];

	for (int test = 0; test < T; test++)
	{
		highest = scores[0][test];
		for (int stu = 0; stu < S; stu++)
		{
			if (scores[stu][test] > highest)
			{
				highest = scores[stu][test];
			}
		}
		cout << "The highest Score for Test # " << test + 1 << ": ";
		cout << highest << endl;
	}
	cout << "Press Enter to Continue..." << endl;
	cin.get();
}

//*****************************************************************************************************
// From each row of students, find the lowest for each student
void getLowestOfEachStudent(double scores[][T])
{
	double lowest = scores[0][0];
	for (int stu = 0; stu < S; stu++)
	{
		lowest = scores[stu][0];
		for (int test = 0; test < T; test++)
		{
			if (scores[stu][test] < lowest)
			{
				lowest = scores[stu][test];
			}
		}
		cout << "The lowest Score for Student # " << stu + 1 << ": ";
		cout << lowest << endl;
	}
	cout << "Press Enter to Continue..." << endl;
	cin.get();

}

//*****************************************************************************************************
// Report all of the data collected in this program
void report(double scores[][T])
{
	double total,
		average,
		highest;

	cout << fixed << showpoint << setprecision(2);

	total = totalTests(scores);
	cout << "Total of all tests is: " << total << endl;
	cout << "Press Enter to Continue..." << endl;
	cin.get();

	average = averageTest(total);
	cout << "Average of all tests is: " << average << endl;
	cout << "Press Enter to Continue..." << endl;
	cin.get();

	averageEachTest(scores);

	averageEachStudent(scores);

	highest = getHighest(scores);
	cout << "Highest of all tests is: " << highest << endl;
	cout << "Press Enter to Continue..." << endl;
	cin.get();

	getHighestOfEachTest(scores);

	getLowestOfEachStudent(scores);

}
/*
Total of all tests is: 955.00
Press Enter to Continue...

Average of all tests is: 79.58
Press Enter to Continue...

Average for Test # 1: 78.33
Average for Test # 2: 86.67
Average for Test # 3: 76.67
Average for Test # 4: 76.67
Press Enter to Continue...

Average for Student # 1: 78.75
Average for Student # 2: 78.75
Average for Student # 3: 81.25
Press Enter to Continue...

Highest of all tests is: 90.00
Press Enter to Continue...

The highest Score for Test # 1: 85.00
The highest Score for Test # 2: 90.00
The highest Score for Test # 3: 90.00
The highest Score for Test # 4: 80.00
Press Enter to Continue...

The lowest Score for Student # 1: 70.00
The lowest Score for Student # 2: 60.00
The lowest Score for Student # 3: 75.00
Press Enter to Continue...


C:\Users\rylan\Desktop\College Year 1\COSC1550 - Fall\Assignment21 - Test Scores\Debug\Assignment21 - Test Scores.exe (process 14828) exited with code 0.
Press any key to close this window . . .


*/