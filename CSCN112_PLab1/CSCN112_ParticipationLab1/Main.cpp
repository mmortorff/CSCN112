// CSCN 112 Participation Lab #1
// Learning how to create class objects, header files, and implementation files 

/* 
	INSTRUCTIONS

	Learning Objectives 
	 - Practice proper programming form
	 - Demonstrate the ability to work in a group
	 - Learn how to successfully create a class using header and implementation files 
	 - Implement class objects and use them in a program successfully

	 Overview: Your team is starting up a new bakery (you may be creative with your bakery name). You need to create a program that will automate
	   the ordering system, allowing your patrons to purchase various items from the menu before printing out an overall total. This system will
	   be created through several labs throughout the semester, but your initial goal is to be able to create menu items. Use the following steps
	   to guide your process:

	 1.)  Create your header and implementation files for a class named menuItem
	 2.)  The menuItem class should be used to store the name of the item, the price of the item, and how many of that specific item has been ordered
	 3.)  Your class should include appropriate functions - accessor and mutator functions and a print function
	 4.)  In main, confirm that you can create an object of the menuItem class
	 5.)  Next, you need to be able to bring in an item that your bakery is going to sell (using a text file and function(s)). For now, your code should focus on being able to bring in a SINGLE menu item
	 6.)  Once you’ve brought in the menu item, you should then demonstrate the ability to print it off successfully! 
*/

// Include Statements 
#include <iostream>
#include "menuItem.h" // This allows main to see the class definition for menu items 
#include <fstream> // used to bring in the menu
#include <iomanip> // used for print formatting 

using namespace std;

// Global Constants 
const int NUM_ITEMS = 3;
const string MENU_FILE_NAME = "menu.txt";

// Function Prototypes 
// Function to load in the menu from a file 
void loadItem(menuItem& item);

// Function to print out the menu
void print(const menuItem item);

int main()
{
	cout << "CSCN 112 - Fall 2024 - Participation Lab #1" << endl << endl;

	// Create a menu item
	menuItem item1;

	// Load the array full of items using the loadMenu function
	loadItem(item1);

	// Print out the menu for the user's review
	print(item1);

	system("pause");
	return 0;
}

// Function Definitions
// This function loads the menu items from an associated file into the menu array. 
void loadItem(menuItem& item)
{
	// Create local variables 
	ifstream in;
	string temp_name = "";
	float temp_price = 0.0;

	// Open the input file using the file name 
	in.open(MENU_FILE_NAME);

	// Confirm that the file has been opened successfully
	while (!in)
	{
		cout << "There was an error opening the file successfully! Please re-enter the file name: ";
		in.close();

		getline(cin, temp_name);
		in.open(temp_name);
	}

	// Read in the values in the file. Since we're dealing with an array, we're going to do that with a loop
	// Bring the values in from the file
	getline(in, temp_name);
	in >> temp_price;

		// Store them in the array using the set functions 
	item.setName(temp_name);
	item.setPrice(temp_price);

	in.ignore(1); // ignore the hanging newline in the file before the next item 

	// Once the values have been brought in successfully, close out the file 
	in.close();
}

// This function is going to print out the menu item (it will eventually be used to print the whole menu, hence the added formatting) 
void print(menuItem item)
{
	/*cout << fixed << setprecision(2);
	cout << setfill('*') << setw(50) << "*" << endl << setfill(' ');
	cout << "          Welcome to the CSCN 112 Bakery!" << endl;
	cout << "     Please select from the following options: " << endl << endl;*/

	cout << " " << 1 << left << setw(5) << ".";
	item.menuPrint();

	cout << endl; 
}