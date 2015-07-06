/*CK King
Section 1041
Matrixification*/
//including my stuff
#include <iostream>
#include <vector>
//does nothing. I should probably comment this out
//void makeMatrix(double** M, int R, int C);

using namespace std;

double getNumber();


int main()
{
	//variables

	//menu selectionatorification
	double choice;
	//store the number of rows and columns
	double m1Rows, m2Rows, m1Columns, m2Columns;
	//inititalizing of a trash number used to input the data into the places, and as an accumulator
	double trash = 0;
	//the matrixes (vectors are easier and automagical)
	vector<vector<double> > Matrix1, Matrix2, MatrixMultiplied;
	//clear the vectors, just in case
	Matrix1.clear();
	Matrix2.clear();
	MatrixMultiplied.clear();

	//menu loop
	do
	{
		//input validation loop
		do
		{
			//menu options
			cout << "\nPlease select an option from the following menu:\n"
				<< "1.\tCalculate the transposition of a matrix of arbitrary size\n"
				<< "2.\tCalculate the Matrix Multiplication of 2 matricies\n"
				<< "3.\tEnd the program\n";
			choice = getNumber();

		} while (choice < 1 || choice > 3);
		//if selection 1 do the trasposification
		if (choice == 1)
		{
			//get the number of rows and columns the matrix has
			cout << "How many rows does the Matrix Have?\n";
			m1Rows = getNumber();
			cout << "How many columns does the Matrix have?\n";
			m1Columns = getNumber();

			//get the values that go in the corrosponding locations
			for (int r = 0; r < m1Rows; r++)
			{
				//make the vector bigger
				Matrix1.push_back(vector<double>());
				for (int c = 0; c < m1Columns; c++)
				{
					cout << "What is the Value for location " << r << " x " << c << "\n";
					trash = getNumber();
					Matrix1[r].push_back(trash);
				}
			}
			//display the original matrix1
			cout << "The original Matrix looks like\n";

			for (int r = 0; r < m1Rows; r++)
			{
				cout << "|";
				for (int c = 0; c < m1Columns; c++)
				{
					cout << " " << Matrix1[r][c] << " ";
				}
				cout << "|\n";
			}

			cout << "The Transposed Matrix looks like\n\n";
			//transposition
			for (int r = 0; r < m1Columns; r++)
			{
				cout << "|";
				//make bigger
				Matrix2.push_back(vector<double>());
				for (int c = 0; c < m1Rows; c++)
				{
					//put the stuff in the places
					Matrix2[r].push_back(Matrix1[c][r]);
					cout << " " << Matrix1[c][r] << " ";
				}
				cout << "|\n";
			}



		}
		//multiplication menu option
		else if (choice == 2)
		{
			//get matrix 1 infor
			cout << "How many rows does the Matrix 1 Have?\n";
			m1Rows = getNumber();
			cout << "How many columns does the Matrix 1 have?\n";
			m1Columns = getNumber();


			for (int r = 0; r < m1Rows; r++)
			{
				Matrix1.push_back(vector<double>());
				for (int c = 0; c < m1Columns; c++)
				{
					cout << "What is the Value for location " << r << " x " << c << "\n";
					trash = getNumber();
					Matrix1[r].push_back(trash);
				}
			}
			//display matrix 1
			cout << "The original Matrix looks like\n";
			for (int r = 0; r < m1Rows; r++)
			{
				cout << "|";
				for (int c = 0; c < m1Columns; c++)
				{
					cout << " " << Matrix1[r][c] << " ";
				}
				cout << "|\n";
			}
			//oh hey, we need to know about matrix 2
			cout << "How many rows does the Matrix 2 Have?\n";
			m2Rows = getNumber();
			cout << "How many columns does the Matrix 2 have?\n";
			m2Columns = getNumber();


			for (int r = 0; r < m2Rows; r++)
			{
				Matrix2.push_back(vector<double>());
				for (int c = 0; c < m2Columns; c++)
				{
					cout << "What is the Value for location " << r << " x " << c << "\n";
					trash = getNumber();
					Matrix2[r].push_back(trash);
				}
			}
			//DISPLAY IT NOW
			cout << "The original Matrix looks like\n";
			for (int r = 0; r < m2Rows; r++)
			{
				cout << "|";
				for (int c = 0; c < m2Columns; c++)
				{
					cout << " " << Matrix2[r][c] << " ";
				}
				cout << "|\n";
			}
			//tells the user they are an idiot, if in fact they are one
			if (m1Columns != m2Rows)
			{
				cout << "That multiplication is undefined\n";
			}
			else
			{
				//reset the trash veraible because I used it earler like an idiot and couldn't find why it was giving me wrong numbers
				trash = 0;
				//a whole bunch of for loops, I honestly didn't expect ti to work right, but amazingly it did. I will try to explain it, maybe.
				//this one sets the new matrix number of rows equal to the m1 rows. because thats what it will be.
				for (int newr = 0; newr < m1Rows; newr++)
				{
					//increase the row size
					MatrixMultiplied.push_back(vector<double>());
					//this one sets the new matrix number of columns equal to the nimber of columns from m2. because that's what it will be.
					for (int newc = 0; newc < m2Columns; newc++)
					{
						//ummm
						//uhhh
						//huuh
						//this one, uses the middle number (m1 columns or m2 rows) to do the loopage for the actual math?
						for (int m1c = 0; m1c < m1Columns; m1c++)
						{
							//mutiply m1 and m2, using the correct positions that need to multiply to gether.
							//then increment the trash
							trash += Matrix1[newr][m1c] * Matrix2[m1c][newc];
						}
						//push and emtpy the trash.
						MatrixMultiplied[newr].push_back(trash);
						trash = 0;
					}
				}
			}

			//display the final matrix
			cout << "The Multiplied Matrix looks like\n\n";

			for (int r = 0; r < m1Rows; r++)
			{
				cout << "|";
				for (int c = 0; c < m2Columns; c++)
				{
					cout << " " << MatrixMultiplied[r][c] << " ";
				}
				cout << "|\n";
			}

		}
		//clear, clear, clear, re-initialize
		Matrix1.clear();
		Matrix2.clear();
		MatrixMultiplied.clear();
		trash = 0;
		//pause so that you can see the screen before clearing it.
		system("pause");
		system("cls");
		//if the menu three is selected exit.
	} while (choice != 3);
	//return the error code of 0. because thats what error happend. 
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
