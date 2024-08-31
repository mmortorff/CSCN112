#pragma once

// menuItem class declaration file - used to create menuItem objects 

#include <string>

class menuItem
{
public:
	// Constructors and Destructor 
	menuItem();
	menuItem(std::string, float, int);
	~menuItem();

	// Get and set functions - also known as accessor and mutator functions
	void setName(std::string);
	std::string getName() const;
	void setPrice(float);
	float getPrice() const;
	void setQuantity(int);
	int getQuantity() const;

	// Other functions 
	void printItem() const;
	void menuPrint() const;

private:
	std::string name;
	float price;
	int quantity;

	// No helper functions necessary for this class 
};