/*
	BMI Calculator - Challenge 21
	This program is designed to calculate the BMI of a person's
	Height and Weight.

*/

#include <iostream>

using namespace std;

int main()
{
	
	void getInput();
	
	getInput();
	
	
	
	
	return 0;
}

void getInput()
{
	int choice = 0;
	float weight = 0.0f;
	float height = 0.0f;
	while(choice != 1 && choice != 2)
	{
		cout << "Are you using English Measurements or SI Measurements?" << endl;
		cout << "1. English" << endl;
		cout << "2. SI Units" << endl;
		cout << "->";
		cin  >> choice;
		cout << "\n\n\n\n";
	}
	
	while(weight <= 0.0f)
	{
		if(choice == 1)
			cout << "What is your weight in Pounds? \n-> ";
		else
			cout << "What is your weight in Kilograms? \n-> ";
		cin >> weight;
	}
	while(height <= 0.0f)
	{
		if (choice == 2)
		{
			cout << "What is your Height in Meters?\nEx [1.2] 1.2 Meters\n-> ";
			cin >> height;	
		}
		else
		{
			int feet;
			int inches;
			cout << "What is your height? \nEx: [5 11] 5ft 11in \n-> ";
			cin >> feet >> inches;
			if (inches == 0)
				height = 0;
			height = (feet * 12) + inches;
		}
	}
	cout << "\n\n\n\n";
	
	float BMI = (weight/(height * height));
	if(choice == 1)
		BMI *= 703;
		
	cout << "Your BMI Calculation is " << BMI << ".  ";
	if (choice == 1)
		cout << "Weight: " << weight << "lbs | Height: " << height << " in^2" << endl;
	if (choice == 2)
		cout << "Weight: " << weight << "kg | Height: " << height << " m^2" << endl;
		
}
