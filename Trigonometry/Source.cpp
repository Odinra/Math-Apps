/* CK King
Section 1041
Lab on the Metry of Tri-Gons
There is a 90 degree angle, a Hypotonuse, a Side A a Side B, an Angle alpha and beta
can give any 2 sides or one side and one angle*/
#include <iostream>
#include <cmath>

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define DegToRad (PI / 180.0)
#define RadToDeg (180.0 / PI)

using namespace std;

double getNumber();

class AngleofThree
{
public:
	AngleofThree()
	{
		H = A = B = alpha = beta = -1;
	}
	double H;
	double A;
	double B;
	double alpha;
	double beta;
};

AngleofThree triangleatorHA(AngleofThree triangle);
AngleofThree triangleatorHalpha(AngleofThree triangle);
AngleofThree triangleatorAalpha(AngleofThree triangle);
AngleofThree triangleatorAB(AngleofThree triangle);
using namespace std;

int main()
{
	double number;
	AngleofThree tri;
	double choice;
	double choice2;
	do
	{
		do
		{
			cout << "\nPlease select an option from the following menu:\n"
				<< "1.\tConvert from Degrees to Radians.\n"
				<< "2.\tConvert from Radians to Degrees.\n"
				<< "3.\tGive two parts of a triangle to find the rest of it \n\t\t(either side and angle or 2 sides).\n"
				<< "4.\tEnd the program\n";
			choice = getNumber();

		} while (choice < 1 || choice > 4);

		if (choice == 1)
		{
			cout << "Please enter the value for Degrees:\n\t";
			number = getNumber();

			number *= (PI / 180.0);

			cout << "That is equal to " << number << " Radians\n";
		}
		if (choice == 2)
		{
			cout << "Please enter the value for Radians:\n\t";
			number = getNumber();

			number *= (180.0 / PI);

			cout << "That is equal to " << number << " Degrees\n";
		}
		if (choice == 3)
		{
			do
			{
				cout << "\nPlease selectwhat information you wish to give\n"
					<< "1.\tHypotenuse and a side (A)\n"
					<< "2.\tHypotenuse and an angle (alpha)\n"
					<< "3.\tSide(A) and an angle (alpha)\n"
					<< "4.\tSide(A) and side(B)\n";
				choice2 = getNumber();
			} while (choice2 < 1 || choice2 >4);


			if (choice2 == 1)
			{
				cout << "Please enter the length of the Hypotenuse\n";
				tri.H = getNumber();
				cout << "Please enter the length of side A\n";
				tri.A = getNumber();
				tri = triangleatorHA(tri);
			}
			if (choice2 == 2)
			{
				cout << "Please enter the length of the Hypotenuse\n";
				tri.H = getNumber();
				cout << "Please enter the angle of alpha\n";
				tri.alpha = getNumber();
				tri = triangleatorHalpha(tri);
			}
			if (choice2 == 3)
			{
				cout << "Please enter the length of side A\n";
				tri.A = getNumber();
				cout << "Please enter the angle of alpha\n";
				tri.alpha = getNumber();
				tri = triangleatorAalpha(tri);
			}

			if (choice2 == 4)
			{
				cout << "Please enter the length of side A\n";
				tri.A = getNumber();
				cout << "Please enter the length of side B\n";
				tri.B = getNumber();
				tri = triangleatorAB(tri);
			}

			cout << "The Triangle sides and angles are:\n"
				<< "Hypotenuse:\t" << tri.H << "\nSide A:\t\t" << tri.A
				<< "\nSide B:\t\t" << tri.B << "\nAngle alpha:\t" << tri.alpha
				<< "\nAngle beta:\t" << tri.beta << "\n";

		}

		system("pause");
		system("cls");

	} while (choice != 4);
	return 0;
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
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return number;
}

AngleofThree triangleatorHA(AngleofThree triangle)
{
	triangle.B = sqrt((triangle.H * triangle.H) - (triangle.A * triangle.A));
	triangle.alpha = atan2(triangle.B, triangle.A) * (180 / PI);
	triangle.beta = 90 - triangle.alpha;
	if (triangle.beta < 0)
	{
		triangle.beta *= -1;
	}

	return triangle;
}
AngleofThree triangleatorHalpha(AngleofThree triangle)
{
	triangle.A = triangle.H * sin(triangle.alpha * (PI / 180.0));
	triangle.B = triangle.H * cos(triangle.alpha * (PI / 180.0));
	triangle.beta = 90 - triangle.alpha;
	if (triangle.beta < 0)
	{
		triangle.beta *= -1;
	}

	return triangle;
}
AngleofThree triangleatorAalpha(AngleofThree triangle)
{
	triangle.H = triangle.A / sin(triangle.alpha * (PI / 180.0));
	triangle.B = triangle.H * cos(triangle.alpha * (PI / 180.0));
	triangle.beta = 90 - triangle.alpha;
	if (triangle.beta < 0)
	{
		triangle.beta *= -1;
	}

	return triangle;
}

AngleofThree triangleatorAB(AngleofThree triangle)
{
	triangle.H = sqrt((triangle.B * triangle.B) + (triangle.A * triangle.A));
	triangle.alpha = atan2(triangle.B, triangle.A)  * (180 / PI);
	triangle.beta = 90 - triangle.alpha;
	if (triangle.beta < 0)
	{
		triangle.beta *= -1;
	}

	return triangle;
}