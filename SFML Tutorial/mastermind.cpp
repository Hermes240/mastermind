

/******************************************************************************************************************************
* Programmers: Hermes Obiang (LAB 12), Anthony Smith (Lab 2), Dennis Kibe (LAB 12) and Joshua Lung (LAB 5)					  *								 
* Class: CPTS 122																											  *
* Programming Assignment: PA 9 (Mastermind)																					  *
* Date: 4/25/2018																											  *
* Description: Mastermind is a code guessing game where the computer chooses four random colors and the user gets a certain	  *
amount of rounds to guess the four colors. The smaller circles to the right of the board display when the user				  *
has guessed right. A white circle means the user guessed one or more of the random colors the computer guessed,				  *
but in wrong place. A black circle means the user guessed one or more of the right colors in the right place.				  *
*******************************************************************************************************************************/

#include "mastermind.h"

/* * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * *
* This function is where the game logic is executed, this function takes in both arrays that contains the user's guess as well *
* as the computer's random guesses' as wel. The algorithm compares the names of the colors in the arrays and addsa counter of  *
* either black or white. Black is the number of colors the user got right and in the right place and white is the number of	   *
* colors the user got right but in the wrong place.																			   *
*																															   *
* * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * *  * * *  *  */

void mastermind::playTurn(string masterCod[], string guessCod[], int * blacks, int * whites)  //Takes both the colors set by computer as well as the user guess and compares the two
{

	int bl = 0, wh = 0;

	for (int i = 0; i < 4; i++)
	{
		if (guessCod[i] == masterCod[i])
		{
			guessCod[i] = "black";
			masterCod[i] = "black";

			//change the color of the litlleholes 
		}
	}

	for (int m = 0; m < 4; m++)
	{
		if (guessCod[m] != "black")
		{
			for (int n = 0; n < 4; n++)
			{
				if (guessCod[m] == masterCod[n])
				{
					guessCod[m] = "white";
					masterCod[n] = "white";
				}
			}
		}
	}

	for (int o = 0; o < 4; o++)
	{
		if (guessCod[o] == "black")
		{
			bl++;
		}
		else if(guessCod[o] == "white")
		{
			wh++;
		}
	}

	*blacks = bl;
	*whites = wh;

}
/* * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * *
 * This function is the mastercode for the computer to choose four random colors. This function accepts an array of strings  *
 * which is populated with the names of the colors and random colors the computer chooses                                    *
 * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * *  * * *  */

void mastermind::masterCode(string masterCod[])    
{
	srand(time(NULL));

	int random_choice;
	char colors[8] = { 'r','b', 'g', 'y', 'm', 's', 'p', 'l'  };
	

	for (int i = 0; i < 4; i++)
	{
		random_choice = rand() % 8;

		masterCod[i] = colors[random_choice];
	}
	
	//for debugging purposes to test the correct answer
	/*cout << "The mastercode is: ";
	for (int j = 0; j < 4; j++)
	{
		cout << masterCod[j];
	}
	cout << endl;*/
}

/***********************************************************************************************************************************************************
*This function takes input of the users random color guess and stores them in array that is the used to compare to the computer's guess array from above.  *
*This function also checks the user's input to make sure it is a valid input according to the colors labeled in the game screen.						   *
************************************************************************************************************************************************************/

void mastermind::guessCode( string guessCod[])  //returns array of colors as strings that the user guessed 
{
	string guess = "";
	int pass = 0, fail = 0;

	// list of colors
	char colors[8] = { 'r','b', 'g', 'y', 'm', 's', 'p', 'l' };

	//ask user for a guess
	cout << "Enter your guess format xxxx: ";
	cin >> guess;

	while (guess.length() != 4 || pass == 0)
	{
		if (guess.length() == 4)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (guess[i] == colors[j])
					{
						pass++;
					}
				}
			}
		}
		

		if (pass != 4)
		{
			cout << "Please enter a valid guess: ";
			cin >> guess;
			pass = 0;
		}
	}
	
	for (int d = 0; d < 4; d++)
	{
		guessCod[d] = guess[d];
	}
	
	
}

