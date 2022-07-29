/******************************************************************************************************************************
* Programmers: Hermes Obiang (LAB 12), Anthony Smith (Lab 2), Dennis Kibe (LAB 12) and Joshua Lung (LAB 5)					  *
* Class: CPTS 122																											  *
* Programming Assignment: PA 9 (Mastermind)																					  *
* Date: 4/25/2018																											  *
* Description: Mastermind is a code guessing game where the computer chooses four random colors and the user gets a certain	  *
* amount of rounds to guess the four colors. The smaller circles to the right of the board display when the user			  *
* has guessed right. A white circle means the user guessed one or more of the random colors the computer guessed,			  *
* but in wrong place. A black circle means the user guessed one or more of the right colors in the right place.				  *
*******************************************************************************************************************************/

#include "Header.h"
#include "smallCircle.h"
#include "bigCircle.h"
#include"mastermind.h"
int main(void)
{
	//declaring window to be opened to present the board to the player
	RenderWindow windows(sf::VideoMode(900, 700), "Mastermind");
	//Window window(sf::VideoMode(900, 700), "Mastermind");
	
	//declaring objects for pegs that big and ones being smaller
	//along with a text object to present to the player alongside the board
	bigCircle * PlayerPeg[4][10], *Peg[8];
	smallCircle * GuessPeg[4][10];
	mastermind game;
	int blacks = 0, whites = 0;
	string masterCod[4] = {}, guesscod[4] = {}, Copyguesscod[4] = {}, copymaster[4] = {};

	//having the strings and the char letters for the color selection
	string col[8] = { "red", "blue", "green", "yellow", "magenta", "sky_blue", "purple", "lime" };
	char letters[8] = { 'r','b', 'g', 'y', 'm', 's', 'p', 'l' };
	
	//bigCircle choice;
	//RenderWindow window;

	
	//game.guessCode();
	//window = game.gameBoard();

	Font font;
	if (!font.loadFromFile("Fonts/KendalType.ttf"))
	{
		throw("Could not load font");
	}

	Text rules, letter;

	//setting the rules object onto the board
	rules.setFont(font);
	letter.setFont(font);

	//this is what will be writen on the board on the right side
	rules.setString("OVERVIEW, OBJECTIVE AND RULES OF MASTERMIND\n\n\t\t\t\t\t\t1. OVERVIEW\n\n"
	"     Mastermind is considered the challenging game of logic\nand deduction. Mastermind will"
	" get you thinking while\nyou try to crack a four colored code set by the program\n"
	"in only 10 moves. Cryptic clues are given to help you know\nwhich color in which position.\n\n"
	"\t\t\t\t\t\t2. RULES\n\nFrom the following set of colors:\n\n\n\n\n\n\t * The program will generate a set"
	" of four colors.\n\n\t * The player(You) has to make his best guess to\n\t    match the exact colors"
	" the program generated\n\t    and their exact positions in 10 moves or fewer.\n\t * The player"
	" is allowed to pick any color more than once.\n\n\t * After each move, cryptic clues will be displayed\n"
	"<-- as follow in each of these tiny holes:\n\n\t + Each white color displayed in the tiny holes means that "
	"\n\t    one of the guessed colors is correct, but it is in the \n\t\twrong position.\n"
	"\t + Each black color displayed in the tiny holes means\n\t    that one of the guessed colors "
	"is correct, and it is\n\t    in the right position.\n\t + The order in which blacks and whites "
	" are positioned\n\t     do not determine positions of guessed colors.");
	//the size of the letters of the rules
	rules.setCharacterSize(16);
	//the type of lettering for the rules
	rules.Bold;
	//the postion of the rules
	rules.setPosition(485, 10);
	
	//time object if needed
	

	int m;
	int d = 50;

	
	//color objects for the pegs, costum made
	Paint tempColor[8];
	Paint Result[4];
	Color temp, resultColor[4];
	sf::Color red, blue, green, yellow, magenta, sky_blue, gray, purple, silver, lime, bl, wh;
	red = Color(255, 0, 0);
	blue = Color(0, 0, 255);
	green = Color(0, 128, 0);
	yellow = Color(255, 255, 0);
	magenta = Color(255, 0, 255);
	sky_blue = Color(0, 191, 255);
	gray = Color(128, 128, 128);
	purple = Color(128, 0, 128);
	silver = Color(192, 192, 192);
	lime = Color(0, 250, 154);
	bl = Color(0, 0, 0);
	wh = Color(255, 255, 255);

	
	//rules.setColor(Color(255, 0, 0));
	rules.setFillColor(Color(0, 0, 0));
	//setting the title for the window when opened
	windows.setTitle("Mastermind");

	//each color is assigned to a number in an array
	Color color[8] = { red, blue,green, yellow, magenta, sky_blue, purple, lime };

	//along with the rules we have examples of pegs the player will use
	//this to help with the idea
	for (int g = 0; g < 8; g++)
	{
		tempColor[g].str = col[g];
		tempColor[g].co = color[g];
	}


	int t = 0, s = 490;
	for (t; t < 8; s += 45, t++)
	{

		Peg[t] = new bigCircle(s, 280, d, color[t]);
		
		//Peg[t]->setRadius(20);
		//windows.draw(letter);
		windows.draw(*(Peg[t]));

	}

	//randomized function for colors
	m = rand() % 7;
	
	//i stands for the postion of the player pegs on the board
	//a stands for the colume index of the player pegs
	int i = 5, a = 0;


	//for loop for the colum index
	for (a; a <4; i += 55, a++)
	{
		//for loop for the row index
		//b stands for the row index of the player pegs
		//j stands for the row postion of the player pegs
		for (int j = 5, b = 0; b < 10; j += 65, b++)
		{
			//m stands for the random color
			m = rand() % 7;
			//Player peg is a double array, a is for the column: 4 columns
			//b is for rows: 10 rows, 10 chances for the player to win the game
			//also to compare to his last chances to guessing the right answer
			//this will be assigned to a new object that is a big circle.
			//A circle shape object that takes in the i and j vertext for postion
			//d is for the vetices the circle will have and lime is just a stand in color that will change
			//in the finished function
			(PlayerPeg[a][b]) = new bigCircle(i, j,d, silver);
			
		}
	}
	/**************************************************************************************/

	//these are for the guessing pegs
	//these pegs will take in the guess from  the player
	//compare their guess to the master code and tell
	//the player how close they are to the answer
	//they are off by 305 pixels from the player pegs
	//to help associate each row
	//x represents the postion of the peg column
	int x = 280, column = 0;

	//going through each column for which there are 4
	for (column; column <4; x += 35, column++)
	{
		//going through each row which are 8, along with the 8 chances for the player
		for (int y = 15, row = 0; row < 10; y += 65, row++)
		{
			//m represents the random color
			m = rand() % 7;
			//Player peg is a double array, a is for the column: 4 columns
			//b is for rows: 10 rows, 10 chances for the player to win the game
			//also to compare to his last chances to guessing the right answer
			//this will be assigned to a new object that is a big circle.
			//A circle shape object that takes in the i and j vertext for postion
			//d is for the vetices the circle will have and lime is just a stand in color that will change
			//in the finished function
			(GuessPeg[column][row]) = new smallCircle(x, y,d, silver);

		}

	}
	int rowIndex = 0, columnIndex = 0, colorIndex = 0;

	game.masterCode(masterCod);
	//now with all our object's memory alocated, the board is ready to be printed
	while (windows.isOpen())
	{
		int round = 5;
		//open up the window
		sf::Event event;
		while (windows.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				windows.close();
		}

		//clear the window's background to a grey color
		windows.clear(sf::Color(gray));



		//i stands for the postion of the player pegs on the board
		//a stands for the colume index of the player pegs
		int i = 5, a = 0;

		//for loop for the colum index
		for (a; a < 4; i += 55, a++)
		{
			//for loop for the row index
			//b stands for the row index of the player pegs
			//j stands for the row postion of the player pegs
			for (int j = 5, b = 0; b < 10; j += 65, b++)
			{
				//Sleep(1000);
				//draws the circle onto the window using a double
				//array for each row and column
				windows.draw(*(PlayerPeg[a][b]));


			}
		}

		//guessing pegs location
		int x = 280, column = 0;

		for (column; column < 4; x += 35, column++)
		{
			for (int y = 15, row = 0; row < 10; y += 65, row++)
			{
				windows.draw(*(GuessPeg[column][row]));
			}

		}
		int t = 0, s = 490, l = 495;
		for (t; t < 8; l += 48, s += 55, t++)
		{
			letter.setString(letters[t]);
			letter.Bold;
			letter.setCharacterSize(15);
			letter.setPosition(l, 250);
			letter.setFillColor(Color(0, 0, 0));
			windows.draw(letter);
			windows.draw(*(Peg[t]));
		}
		windows.draw(rules);
		windows.display();
		int move = 0;
			round = 0;

		// here we play game
		
			if (blacks != 4 && rowIndex != 10)
			{

				int x_cord = 5, y_cord = 5;

				game.guessCode(guesscod);    //Asks user for guess

				for (int p = 0; p < 4; p++)   //Makes copies of the master and guess code 
				{
					copymaster[p] = masterCod[p];
					Copyguesscod[p] = guesscod[p];
				}

				game.playTurn(copymaster, Copyguesscod, &blacks, &whites);



				// enter guess  into the window
				int h = 5;
				l = 0;

				//goes through the array of the guess
				for (int w = 0; w < 4; h += 55, w++)   // W is the column of the 2D array(x coord)
				{
					//goes through the array of colors to assign
					for (int v = 0; v < 8; v++)   // V is the amount if colors.     
					{
						//if the loop detects the 
						if (guesscod[w][0] == col[v][0])
						{
							temp = tempColor[v].co;
							resultColor[l] = temp;
							l++;

						}

					}



				}

				column = 0;
				int row = 0;
				h = 0;

				colorIndex = 0;
				for (column; column < 4; column++)
				{
					(PlayerPeg[column][rowIndex])->setFillColor(resultColor[colorIndex]);
					colorIndex++;
				}


				string results[4] = { "","","","", };
				// enter results into graphics
				for (int r = 0; r < blacks; r++)
				{
					results[r] = "black";
				}
				int r = blacks;
				for (int e = 0; e < whites; r++)
				{
					if (results[r] != "black")
					{
						results[r] = "white";
						e++;
					}
				}

				//what is the length of black and white pegs
				int len = blacks + whites;
				//set it to zero
				column = 0;

				//goes through the guess peg array to print out
				for (int index = 0; index < len; index++)
				{

					//set the color to black indicating you got the right color in the right spot
					if (results[index] == "black")
					{
						//sets the color to black
						(GuessPeg[column][rowIndex])->setFillColor(bl);
						//go to the next column
						column++;
					}

					//if one of the pegs is white indicating you got the right color in the wrong spot
					else if (results[index] == "white")
					{
						//sets the color to white
						(GuessPeg[column][rowIndex])->setFillColor(wh);
						//go to the next column
						column++;
					}
				}

				//this is for each round of the game
				rowIndex++;

				//creates the board
				windows.create(sf::VideoMode(900, 700), "Mastermind");
				//displays the board in a different window
				windows.display();
				//clears the command screen
				system("cls");

				//if you guess all of the pegs right
				if (blacks == 4)
				{
					cout << "congrats you won! the master code was " << masterCod[0] << masterCod[1] << masterCod[2] << masterCod[3] << endl;
				}

				//if you use up all your chances
				if (rowIndex == 10)
				{
					cout << "You ran out of chances! the master code was " << masterCod[0] << masterCod[1] << masterCod[2] << masterCod[3] << endl;
				}

			}

			//would you like to try again choice pops up on the command console
			else
			{
				//default string to collect answer
				string choice = "";
				//ask the player to play again
				cout << "Do you want to play again? y/n: ";
				//collect their choice
				cin >> choice[0];

				//if the answer is yes it restarts the game
				if (choice[0] == 'y')
				{
					windows.close();
					main();
				}

				//otherwise it will exit out of the game
				else
				{
					break;
				}
				
			}
		

	}

	return 0;
}