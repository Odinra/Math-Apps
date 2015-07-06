/*
CK King
*/

#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

#define DegToRad 0.0174532925
#define GRAVITY 9.81
#define timemodifier .01

double Velocity, xVelocity, yVelocity, angle, xPos, yPos, initialyVelocity, time = 0, timesSquare;

void Mathamaticization();
double getNumber();
int main()
{
	Mathamaticization();
	system("pause");
	return 0;
}

void Mathamaticization()
{
	printf("Please enter the Velocity:\n");
	Velocity = getNumber();
	printf("Please enter the Angle:\n");
	angle = getNumber();

	angle *= DegToRad;

	yVelocity = Velocity * (sin(angle));

	initialyVelocity = yVelocity;

	xVelocity = sqrt((Velocity * Velocity) - (yVelocity * yVelocity));

	printf("Time\tX Velocity\tX Position\tY Velocity\tY Position\n");

	while (yPos >= 0)
	{
		timesSquare = time * time;

		yPos = (initialyVelocity * time) - (.5 * GRAVITY * timesSquare);

		yVelocity = initialyVelocity - (GRAVITY * time);

		xPos = xVelocity * time;

		if (yPos > 0)
		{
			printf("%g\t%f\t%f\t%f\t%f\n", time, xVelocity, xPos, yVelocity, yPos);
		}
		else
		{
			printf("%g\t%f\t%f\t%f\t%f\n", time, xVelocity, xPos, yVelocity, yPos);
		}

		time += timemodifier;;
		Sleep(1000 * timemodifier);

	}

}

//used to get only number data
double getNumber()
{
	double number;
	//while loop to make sure that only numbers are input into the number variables
	while (!(cin >> number))
	{
		cout << "Invalid entry: please enter a number:\n";
		cin.clear();
		//		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}

	return number;
}