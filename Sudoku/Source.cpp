#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<process.h>
using namespace std;
//This will set the position of the cursor

void gotoXY(int x, int y) {

	//Initialize the coordinates

	COORD coord = { x, y };

	//Set the position

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	return;

}


void randm(int[][9], int[][9]);
void display(int[][9]);
int st();
void strt();
void rules(void);
void win(void);
void lose(void);

void main()												//Main function//
{
	int saved_sudoku[9][9] = {				           //Saved 2d Array//
		{ 1,7,4,2,8,5,3,9,6 },
		{ 3,9,6,4,1,7,5,2,8 },
		{ 8,5,2,9,6,3,1,7,4 },
		{ 4,1,7,5,2,8,6,3,9 },
		{ 6,3,9,7,4,1,8,5,2 },
		{ 2,8,5,3,9,6,4,1,7 },
		{ 7,4,1,8,5,2,9,6,3 },
		{ 9,6,3,1,7,4,2,8,5 },
		{ 5,2,8,6,3,9,7,4,1 }
	};

	int sudoku[9][9];
menu:
	system("cls");
	randm(sudoku, saved_sudoku);
	st();
	display(sudoku);
	goto menu;

	system("pause");


}
void randm(int sudoku[][9], int saved_sudoku[][9])  //Generates randomized 2d array form saved 2d array//
{
	int random, a;
	srand(time(0));					//Seeding for rand function through Computer Time//
	random = rand() % 9;				//rand()%9 Generates random numbers below 9 as sudoku is of 9X9 Grid//
	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<9; j++)
		{
			a = random + saved_sudoku[i][j];
			if (a>9)
				a = a - 9;
			sudoku[i][j] = a;
		}
	}
}
void display(int sudoku[][9])    //Arranges the randomized 2d array to look like a Sudoku Box//
{
	int my_sudoku[9][9], r1, r2, i, j, x = 2, y = 1, chance = 3;
	int key, ii[70], jj[70], blanks = 0, total_blanks = 0;
	int xx, yy;
	int a = 0, b = 0;

	srand((unsigned)time);
	for (i = 0; i<9; i++)
	{
		srand(time(0));
		//Generating two random numbers for creating a condition to display blank boxes//  
		r1 = rand() % 9 + 1;
		r2 = rand() % 9 - 1;
		//Loop for counting blank boxes// 
		for (j = 0; j<9; j++)
		{

			my_sudoku[i][j] = sudoku[i][j];
			//condition
			if (r1 == j || r1 == i || r2 == i || r2 == j || r1 + 2 == j || r2 + 2 == j)
			{
				my_sudoku[i][j] = 10;
				ii[a] = i; jj[b] = j;
				a++; b++;
				total_blanks++;
			}
		}
	}

	gotoXY(0, 0);

	for (i = 0; i<9; i++)
	{
		cout << "+---+---+---+---+---+---+---+---+---+\n";
		cout << "|";
		for (j = 0; j<9; j++)
		{

			if (my_sudoku[i][j] == 10)
				cout << "   |";

			else
				cout << " " << my_sudoku[i][j] << " |";
			// if(j==2||j==5)
			//	 cout<<
			"|";
		}
		cout << endl;
		// if(i==2||i==5)
		//	cout<<"+---+---+---++---+---+---++---+---+---+\n";
	}
	cout << "+---+---+---+---+---+---+---+---+---+\n";
	cout << "\n You have 3 Chance";
	gotoXY(2, 1);
	blanks = total_blanks;

	while (1)
	{

		kbhit();
		key = getch();
		switch (key)
		{
		case 0x48:
		{
			if (y <= 2)
			{
				break;
			}
			y -= 2;
			gotoXY(x, y);
			break;
		}
		case  0x50:
		{
			if (y >= 17)
			{
				break;
			}
			y += 2;
			gotoXY(x, y);
			break;
		}
		case 0x4B:
		{
			if (x <= 4)
			{
				break;
			}
			x -= 4;
			gotoXY(x, y);
			break;
		}
		case 0x4D:
		{
			if (x >= 34)
			{
				break;
			}
			x += 4;
			gotoXY(x, y);
			break;
		}
		int number;
		case 49:
		case 50:
		case 51:
		case 52:
		case 53:
		case 54:
		case 55:
		case 56:
		case 57:
		case 58:
		case 59:
		{
			if (key == 49)
				number = 1;
			if (key == 50)
				number = 2;
			if (key == 51)
				number = 3;
			if (key == 52)
				number = 4;
			if (key == 53)
				number = 5;
			if (key == 54)
				number = 6;
			if (key == 55)
				number = 7;
			if (key == 56)
				number = 8;
			if (key == 57)
				number = 9;
			xx = (x / 4);
			yy = (y / 2);


			for (int v = 0; v<blanks; v++)
			{

				if (ii[v] == yy&&jj[v] == xx)
				{

					if (number == sudoku[yy][xx])
					{
						jj[v] = 600;
						ii[v] = 600;
						cout << number;
						gotoXY(x, y);
						total_blanks--;
						if (total_blanks <= 0)
						{
							win();
							return;
						}
					}

					else
					{
						gotoXY(0, 20);
						chance--;
						if (chance == 0)
						{
							lose();
							return;
						}
						cout << "You Have " << chance << " Chances Left ";
						gotoXY(x, y);
						cout << " ";
						gotoXY(x, y);


					}
				}

			}
		}
		}
	}


}





//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


int st()
{

	int x, y;
	int key;
	strt();

back:

	x = 25, y = 10;
	gotoXY(x, y);
	cout << "Enter Game";
	gotoXY(x, 11);
	cout << "Rules";
	gotoXY(x, 12);
	cout << "Exit";
	x = 24; y = 10;
	gotoXY(x, y);
	do
	{
		kbhit();
		key = getch();
		switch (key)
		{
		case 0x48:
		{
			if (y <= 10)
			{
				break;
			}
			y--;
			gotoXY(x, y);
			break;
		}
		case  0x50:
		{
			if (y >= 12)
			{
				break;
			}
			y++;
			gotoXY(x, y);
			break;
		}
		case'\r':
		{
			if (y == 10)
			{

				return(0);
				break;
			}
			else
			{
				if (y == 11)
				{
					gotoXY(0, 0);
					rules();
					getch();
					system("cls");
					goto back;
					break;
				}
				else
					exit(0);
			}
		}

		}
	} while (1);

	return 0;

}

void rules(void)
{
	system("cls");
	cout << "A sudoku puzzle is a grid of nine by nine squares, that is subdivided into nine subgrids of three by three cells.\n";


	cout << "The objective of sudoku is to enter a digit from 1 through 9 in each cell, in   such a way that:"
		; cout << "\n\n~Each horizontal row contains each digit (from 1 to 9) exactly once"
		; cout << "\n\n~Each vertical column contains each digit (from 1 to 9) exactly once"
		; cout << "\n\n~Each subgrid or region contains each digit (from 1 to 9) exactly once";
	;
}

void strt(void)
{
	gotoXY(0, 9);
	cout << "                       --          |      |\n";
	Sleep(100);
	cout << "                      |  |         |      |\n";
	Sleep(100);
	cout << "                       \\   |  |  --|  --  | / |  |\n";
	Sleep(100);
	cout << "                        \\  |  | |  | |  | |/  |  |\n";
	Sleep(105);
	cout << "                      |  | |  | |  | |  | | \\ |  |\n";
	Sleep(105);
	cout << "                       --   --   --   --       --\n";
	Sleep(105);
	cout << "                      ____________________________ ";
	Sleep(1800);
	system("cls");
}
void win(void)
{
	system("cls");
	cout << "\n"
		<< " oo   oo  o   o  oo  ooo     o  ooooo o  o o     o  ooooo o  oo  o   o\n"
		<< "o  o o  o oo  o o  o o  o   o o   o   o  o o    o o   o   o o  o oo  o\n"
		<< "o    o  o o o o o    ooo   ooooo  o   o  o o   ooooo  o   o o  o o o o\n"
		<< "o  o o  o o  oo o oo o  o  o   o  o   o  o o   o   o  o   o o  o o  oo\n"
		<< " oo   oo  o   o  oo  o   o o   o  o   oooo ooo o   o  o   o  oo  o   o\n\n"
		; Sleep(1200);

	cout << "           @   @  @@  @  @    @      @@      @ @ @   @\n";
	Sleep(100);
	cout << "            @ @  @  @ @  @     @    @  @    @  @ @@  @\n";
	Sleep(100);
	cout << "             @   @  @ @  @      @  @    @  @   @ @ @ @\n";
	Sleep(100);
	cout << "             @   @  @ @  @       @@      @@    @ @  @@\n";
	Sleep(100);
	cout << "             @    @@  @@@@        @      @     @ @   @\n";
	Sleep(1500);
}
void lose(void)
{
	system("cls");

	cout << "\n"
		<< "     ppp     p   p       p ppppp     ppp  p      p pppp pppp\n"
		<< "    p   p   p p  pp     pp p        p   p  p    p  p    p   p\n"
		<< "    p      ppppp p p   p p ppp      p   p   p  p   ppp  pppp\n"
		<< "    p  ppp p   p p  p p  p p        p   p    pp    p    p   p\n"
		<< "     ppp   p   p p   p   p ppppp     ppp     p     pppp p    p\n";

	Sleep(1000);
}