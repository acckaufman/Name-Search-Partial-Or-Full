//This program contains an array of names and phone numbers, stored as strings,
//and allows the user to search the list for a full or partial name.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	const int NUM_PEOPLE = 15;
	char again;

	//Initialize two arrays of strings containing names and phone numbers, based on the list provided in the assignment guidelines.
	string names[NUM_PEOPLE] = { "Renee Javens", "Joe Looney", "Geri Palmer", "Lynn Presnell," "Bill Wolfe", "Sam Wiggins," "Bob Kain",
									"Tim Haynes", "John Johnson", "Jean James", "Ron Palmer", "George Prescott", "Tim Johnston", "Bob Jameson", "Sam White" };
	string numbers[NUM_PEOPLE] = { "678-1223", "586-0097", "223-8787", "887-1212", "223-8878", "486-0998", "586-8712", "586-7676", "223-9037", 
									"678-4939", "486-2783", "223-8723", "875-2353", "235-5620", "876-9875" };
	string searchName;	//To hold the user's search criteria

	do {
		//Ask the user to enter a name or a partial name to search for.
		cout << "Please enter a name (or part of a name) that you would like to search for." << endl;
		cout << "(Note: case sensitive):" << endl;
		cout << "Search: ";
		getline(cin, searchName);

		//Use a loop to cycle through each element in the names[] array, searching for the sequence of characters the user entered.
		//Each time the sequence is found, display the element of the names[] array and the corresponding element in the numbers[] array.

		//Set output formatting
		cout << setw(20) << left << "Name";
		cout << setw(20) << left << "Phone Number" << endl;
		cout << "****************************************" << endl;

		bool found = false;	//Flag (to inform the user in case no results were found)

		for (int index = 0; index < NUM_PEOPLE; index++)
		{
			//Use the .find() member function of the C++ string class to search each array element for the contents that the user input into searchName.
			if (names[index].find(searchName) != string::npos)	//If the search returned a result
			{
				found = true;
				cout << setw(20) << left << names[index] << setw(20) << left << numbers[index] << endl;
			}
		}

		cout << endl;

		//If the flag is still set to false, indicating that no matches were found, inform the user that their search returned no results.
		if (!found)
			cout << "Your search returned no matches." << endl << endl;

		cout << "Would you like to do another search? (y/n): ";
		cin >> again;
		cin.ignore();

	} while(again == 'y' || again == 'Y');
	
	cout << endl << "Thank you for using this program!" << endl;
	cout << "Press any key to continue..." << endl;
	char ch;
	cin.get(ch);

	return 0;
}