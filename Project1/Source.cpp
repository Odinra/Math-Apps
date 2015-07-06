/*CK King
Section 1041
Lines Lab*/
#include <iostream>
using namespace std;

struct point
{
	double x;
	double y;
	point(double x1, double y1)
	{
		x = x1; y = y1;
	}
	point() {}
};

double getNumber();
point interLines(double m1, double m2, double b1, double b2);
void lineEquation(double x1, double y1, double x2, double y2);


int main()
{
	int choice;

	double m1;
	double m2;
	double b1;
	double b2;
	point P;

	do
	{
		cout << "Please make a selection from the following menu\n"
			<< "1.\tGet the equation of a line by giving 2 x and y coordinates\n"
			<< "2.\tGet the point of intersection by giving 2 slopes and y intercepts\n"
			<< "3.\tExit the program\n";

		do
		{
			cin >> choice;
			/*choice = getNumber();*/
		} while (choice < 1 && choice > 3);

		if (choice == 1)
		{
			cout << "Please enter the x value of point 1:\n";
			m1 = getNumber();

			cout << "Please enter the y value of point 1:\n";
			b1 = getNumber();

			cout << "Please enter the x value of point 2:\n";
			m2 = getNumber();

			cout << "Please enter the y value of point 2:\n";
			b2 = getNumber();

			lineEquation(m1, b1, m2, b2);
		}

		else if (choice == 2)
		{
			cout << "Please enter the slope of line 1:\n";
			m1 = getNumber();

			cout << "Please enter the Y intercept of line 1:\n";
			b1 = getNumber();

			cout << "Please enter the slope of line 2:\n";
			m2 = getNumber();

			cout << "Please enter the Y intercept of line 2:\n";
			b2 = getNumber();

			P = interLines(m1, m2, b1, b2);

			cout << "The Two lines intersect at:\n";
			cout << "( " << P.x << " , " << P.y << " ) \n";

		}

		system("pause");
		system("cls");

	} while (choice != 3);
	return 0;
}

double getNumber()
{
	double number;

	while (!(cin >> number))
	{
		cout << "Invalid entry: please enter a number:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return number;
}

point interLines(double m1, double m2, double b1, double b2)
{
	if (m1 == m2)
		return point(NULL, NULL);

	double x = (b2 - b1) / (m1 - m2);
	double y = x * m1 + b1;
	point p = point(x, y);
	return p;
}

void lineEquation(double x1, double y1, double x2, double y2)
{
	if (x1 == x2)
	{
		cout << "That line has an infinite slope";
		if (x1 == 0)
			cout << " and crosses the Y axis at all points\n";
		else
			cout << " and never crosses the Y axis\n";
	}

	double m = (y2 - y1) / (x2 - x1);

	double b = y1 - (m * x1);

	cout << "The slope of the line is " << m << " and it crosses the Y axis at " << b << "\n"
		<< "for an equation of:\n"
		<< "y = " << m << "x + " << b;
}