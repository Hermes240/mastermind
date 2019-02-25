
/*******************************************************************************************************************************
* Programmers: Hermes Obiang, Anthony Smith, Dennis Kibe and Joshua Lung													   *
* Class: CPTS 122																											   *
* Programming Assignment: PA 9 (Mastermind)																					   *
* Date: 4/25/2018																											   *
* Description: Mastermind is a code guessing game where the computer chooses four random colors and the user gets a certain	   *
* amount of rounds to guess the four colors. The smaller circles to the right of the board display when the user			   *
* has guessed right. A white circle means the user guessed one or more of the random colors the computer guessed,              *
* but in wrong place. A black circle means the user guessed one or more of the right colors in the right place.                *
********************************************************************************************************************************/
#include"Header.h"


class mastermind: public RenderWindow
{
public:

	
	//void playGame();
	void playTurn(string masterCod[], string guessCode[], int *blacks, int * whites);
	void masterCode(string masterCod[] = {}); // making master code
	void guessCode(string guessCod[] = {}); // gets user input

	//this is the function itself, it will take in the player's pegs they just inserted, the guess pegs it will change
	//the current game loop the player is on, the master code they are trying to guess, the index of which peg
	//and the guess index for which guess peg we are on
	//int GuessPegFunction(string Player[4], string Guess[4], string MasterCode[4], int Index);


private:


};

