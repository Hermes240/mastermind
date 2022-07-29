#pragma once
#include "Header.h"

//this is a function that will color in the guess pegs for the board after each turn
//first it will have a while loop for the guess index, this index is the col of the guess peg
while (guessIndex < 4)
{
	//this is the function itself, it will take in the player's pegs they just inserted, the guess pegs it will change
	//the current game loop the player is on, the master code they are trying to guess, the index of which peg
	//and the guess index for which guess peg we are on
	int GuessPegFunction(bigCircle Player[4][10], smallCircle Guess[4][10], int gameLoop, bigCircle MasterCode[4], int PlayerMasterIndex, int GuessIndex)
	{
		//declaring an int for after you check if it is in the right spot,
		//this is for the loop to check the other places
		int ifinotherloop = 0;
		//this is if the color is in the right spot
		if (Player[PlayerMasterIndex][gameLoop] == MasterCode[PlayerMasterIndex])
		{
			//colors it in solid representing that it is in the right spot
			Guess[GuessIndex][gameLoop].setsolidcolor();
			//add to the guess index for the next gues peg
			GuessIndex++;
			//this is to return the results
			return GuessIndex;
		}
		//this is to shorten the the length because
		//we already checked the previous pegs
		ifinotherloop = PlayerMasterIndex;
		//the while loop to go throught the other pegs
		while (ifinotherloop < 4)
		{
			//this is if the master code has the same color but in the wrong spot
			if (Player[PlayerMasterIndex][gameLoop] == MasterCode[ifinotherloop])
			{
				//colors it in lightly representing that it is the right color but in the wrong spot
				Guess[GuessIndex][gameLoop].setlightcolor();
				//add to the guess index for the next guess peg
				GuessIndex++;
				//return the value of the guess index
				return GuessIndex;
			}
		}

	}
}


CreateMaterCode()
{
	//declare the four colors
	char color[4] = {};
	//an index to run through
	int index = 0, RandomColor = 0;
	//a loop to go through the index
	while (index < 4)
	{
		//this is to make sure of no dublicates
		//no bbrr or gggb, making sure the code is
		//brgy
		bool noCopies = true;
		while (noCopies == ture)
		{
			//picks out a random color
			RandomeColor = Rand() & 8 + 1;
			//if a color is the same as the others
			if (color[index] == color[0] ||
				color[index] == color[1] ||
				color[index] == color[2] ||
				color[index] == color[3])
			{
				//tells the player it is rerolling another color
				cout << "rerolling another color" << endl;
			}
			else
			{
				//tells them a color is picked out
				cout << "Color is picked out for col " << index << endl;
				//set the color of the master peg
				MasterPeg[index].setcolor();

				// truns the bool into false to step out of loop
				noCopies = false;

			}
		}

	}

}



//gameloop for 10 rounds
while (gameloop < 10)
{

}