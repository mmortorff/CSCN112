// Implementation file for the menuItem class 
// Includes all function definitions for the function protypes created in the menuItem class

#include "menuItem.h" // Link the two files together first
#include <iostream>
#include <iomanip>

// Constructors and Destructor 
// This is the default constructor - used to initialize the object's variables when we don't have any information
// Remember that we're going to use the variable names but NOT the types here - we don't want to create MORE space, we want to change the existing space
// We also need to remember to include the scope resolution operator before the name of the function so that the prototype and definition match up
menuItem::menuItem()
{
	name = "";
	price = 0.00;
	quantity = 0;
}

// For the three argument constructor, we are setting the object's private member variables to the values that were passed in 
// Hint:  You're going to want to name your parameters something DIFFERENT from your private member variables so that the program knows which you are referring to
menuItem::menuItem(std::string n, float p, int q)
{
	name = n;
	price = p;
	quantity = q;
}

// This is the destructor, which is called when the memory for your object is destroyed. 
// The compiler will create one for you by default if you don't, but for the moment we're getting in the habit and practice of creating one 
menuItem::~menuItem()
{
	// Nothing to do here because there is no dynamic memory being allocated by this class! 
}

// Get and set functions - also known as accessor and mutator functions
// Set functions are used to CHANGE the value of the private member variable to the value passed into the function 
void menuItem::setName(std::string n)
{
	name = n;
}

// Get functions are used to RETURN the value of the private member variable back to main, WITHOUT being able to change it
std::string menuItem::getName() const
{
	return name;
}

void menuItem::setPrice(float p)
{
	price = p;
}

float menuItem::getPrice() const
{
	return price;
}

void menuItem::setQuantity(int q)
{
	quantity = q;
}

int menuItem::getQuantity() const
{
	return quantity;
}

// Other functions 
// The only other function that we really need for this class is a function that will allow us to print out the item's details 
void menuItem::printItem() const
{
	// Prints out each field with appropriate formatting to print decimals and align columns 
	std::cout << std::fixed << std::setprecision(2);
	std::cout << std::setfill('*') << std::setw(50) << "*" << std::endl << std::setfill(' ');
	std::cout << std::left << std::setw(10) << "Name: " << std::right << std::setw(40) << getName() << std::endl;
	std::cout << std::left << std::setw(10) << "Price ($):" << std::right << std::setw(40) << getPrice() << std::endl;
	std::cout << std::left << std::setw(10) << "Quantity:" << std::right << std::setw(40) << getQuantity() << std::endl;
}

void menuItem::menuPrint() const
{
	std::cout << std::left << std::setw(20) << getName() << std::setw(10) << std::right << getPrice() << std::endl;
}