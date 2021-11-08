// cppAssignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
//Nedim Basic
//7th of October, 2021
//Assignment 3

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

//setup the constants
const int rowWidth = 50;
const int rowWidthAlt = 40;
const char rowFill = '.';
const float fragileShippingCost = 2.0f;
const string fileName = "Order.txt";

int main()
{
	//setup the variables
	string itemName;
	float orderTotal = 0.0f;
	float shippingCost = 0.0f;
	char fragile = ' ';
	string destination;

	//open the order.txt file
	ofstream fileOut;
	fileOut.open(fileName);

	//welcoming message
	cout << "ITCS 2530 - Assignment 3 / Week 3" << endl << endl;


	cout << setw(rowWidth) << setfill(rowFill); //set the width of each row, as well as the fill character
	cout << left << "Please enter the item name (no spaces)" << ":"; //prompt the user to enter their item name
	cin >> itemName;

	//transforms all characters in the string to uppercase
	transform(itemName.begin(), itemName.end(), itemName.begin(), toupper);

	//prompt the user if the item is fragile or not
	cout << setw(rowWidth) << setfill(rowFill);
	cout << left << "Is the item fragile? ( y=yes / n=no )" << ":";
	cin >> fragile;

	//using a switch statement, determine if the fragile shipping cost should be added to the shipping cost;
	switch (fragile) {
	case 'y':
	case 'Y':
		shippingCost += fragileShippingCost; //add the fragile shipping cost if the user entered y or Y
		break;
	case 'n':
	case 'N':
		break; //do not add anything if the user selects no
	default:
		cout << "Illegal entry, the program will exit" << endl;
		return 0; //return the main function if the user enters an illegal input
	}

	//prompt the user to enter their order total
	cout << setw(rowWidth) << setfill(rowFill);
	cout << left << "Please enter your order total" << ":";
	cin >> orderTotal;

	cout << setw(rowWidth) << setfill(rowFill);
	cout << left << "Please enter destination. (usa/can/aus/rus)" << ":";
	cin >> destination;

	//transform all characters in the string to uppercase
	transform(destination.begin(), destination.end(), destination.begin(), toupper);

	//implement the cost tables using an if else chain.
	if (!destination.compare("USA")) { //table for the USA
		if (orderTotal <= 50.0f) {
			shippingCost += 6.0f;
		}
		else if (orderTotal <= 100.0f) {
			shippingCost += 9.0f;
		}
		else if (orderTotal <= 150.0f) {
			shippingCost += 12.0f;
		}
	}
	else if (!destination.compare("CAN")) { //table for Canada
		if (orderTotal <= 50.0f) {
			shippingCost += 8.0f;
		}
		else if (orderTotal <= 100.0f) {
			shippingCost += 12.0f;
		}
		else if (orderTotal <= 150.0f) {
			shippingCost += 15.0f;
		}
	}
	else if (!destination.compare("AUS") || !destination.compare("RUS")) { //table for Australia and Russia
		if (orderTotal <= 50.0f) {
			shippingCost += 10.0f;
		}
		else if (orderTotal <= 100.0f) {
			shippingCost += 14.0f;
		}
		else if (orderTotal <= 150.0f) {
			shippingCost += 17.0f;
		}
	}
	else { //if the user enters an illegal country, exit the program.
		cout << "Illegal country, exiting the program" << endl;
	}

	cout << endl;

	//dispaly the item name
	cout << setw(rowWidthAlt) << setfill(rowFill);
	cout << "Your item is" << itemName << endl;

	fileOut << left << setw(rowWidthAlt) << setfill(rowFill);
	fileOut << "Your item is" << itemName << endl;
	
	//display the shipping cost
	cout << setw(rowWidthAlt) << setfill(rowFill);
	cout << "Your shipping cost is" << "$" << shippingCost << endl;

	fileOut << setw(rowWidthAlt) << setfill(rowFill);
	fileOut << "Your shipping cost is" << "$" << shippingCost << endl;

	//display their shipping destination
	cout << setw(rowWidthAlt) << setfill(rowFill);
	cout << "You are shipping to" << destination << endl;

	fileOut << setw(rowWidthAlt) << setfill(rowFill);
	fileOut << "You are shipping to" << destination << endl;

	//display their total cost
	cout << setw(rowWidthAlt) << setfill(rowFill);
	cout << "Your total shipping costs are" << "$" << orderTotal + shippingCost << endl; //add the ordertotal and shipping cost together

	fileOut << setw(rowWidthAlt) << setfill(rowFill);
	fileOut << "Your total shipping costs are" << "$" << orderTotal + shippingCost << endl;

	//print the goodbye message
	cout << endl;
	cout << setw(rowWidthAlt) << setfill('-');
	cout << "" << "Thank you!" << endl;

	fileOut << endl;
	fileOut << setw(rowWidthAlt) << setfill('-');
	fileOut << "" << "Thank you!" << endl;

	fileOut.close(); //Close the file to save the output
}


