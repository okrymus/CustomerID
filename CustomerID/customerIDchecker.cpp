// This program tests a customer number to determine whether
// it is in the proper format.
#include <iostream>
#include <cctype>
using namespace std;

// Function prototype
bool testNum(char[], int);

int main()
{
	const int SIZE = 9;                     // Array size
	char customer[SIZE];                    // To hold a customer number
	int count;                              // Loop counter variable

	cout
		<< endl
		<< "\t\t          ------Customer ID ------ " << endl
		<< "\tThe program checks that input is matched with the format or not " << endl
		<< "\t\t             By Lee. Panupong" << endl << endl;

	// Get the customer number.
	cout << "Enter a customer number in the form ";
	cout << " LLLNNNNN\n";
	cout << "(LLL = letters and NNNNN = numbers): ";
	cin.getline(customer, SIZE);                                                // Get the ID from the user and store it in customer array

	while (!testNum(customer, SIZE))                                              // Calling testNum() function to test that, and while the input is not proper format, process it                                           
	{
		cout << "That is not the proper format of the customer number. " << endl;
		cout << "Enter a customer number in the form again ";
		cout << "LLLNNNNN\n";
		cout << "(LLL = letters and NNNNN = numbers): ";
		cin.getline(customer, SIZE);                                              // Get the ID from the user and store it in customer array
	}

	// Determine whether it is valid.
	if (testNum(customer, SIZE))
	{
		cout << "That's a valid customer number.\n";

		for (count = 0; count < 3; count++)
		{
			if (islower(customer[count]))                                         // Change the lower case letter to be upper case
				customer[count] = toupper(customer[count]);
		}

		cout << "The costomer ID is: ";
		for (count = 0; count < SIZE; count++)                                    // Print out the ID number with whole letters are upper case
		{
			cout << customer[count];
		}
	}

	cout << endl;
	system("pause");
	return 0;
}

//**********************************************************
// Definition of function testNum.                         *
// This function determines whether the custNum parameter  *
// holds a valid customer number. The size parameter is    *
// the size of the custNum array.                          *
//**********************************************************

bool testNum(char custNum[], int size)
{
	int count;  // Loop counter

	// Test the first three characters for alphabetic letters.
	for (count = 0; count < 3; count++)
	{
		if (!isalpha(custNum[count]))
			return false;
	}

	// Test the remaining characters for numeric digits.
	for (count = 3; count < size - 1; count++)
	{
		if (!isdigit(custNum[count]))
			return false;
	}
	return true;
}

