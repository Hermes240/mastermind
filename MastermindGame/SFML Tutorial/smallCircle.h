
/*******************************************************************************************
* Programmers: Hermes Obiang, Anthony Smith, Dennis Kibe and Joshua Lung
* Class: CPTS 122
* Programming Assignment: PA 9 (Mastermind)
* Date: 4/25/2018
* Description: Mastermind is a code guessing game where the computer chooses four random colors and the user gets a certain
amount of rounds to guess the four colors. The smaller circles to the right of the board display when the user
has guessed right. A white circle means the user guessed one or more of the random colors the computer guessed,
but in wrong place. A black circle means the user guessed one or more of the right colors in the right place.
*******************************************************************************************/

#pragma once
#include"Circle.h"

//This class creates the small circles, this class inherits publicly from the circle class */
class smallCircle: public Circle
{
public:
	smallCircle();

	smallCircle(int x, int y, int d, Color color) : Circle(x, y,d, color)
	{
		this->size = 10;
		this->setRadius(size);
	}

	void printData(int data)
	{
		cout << data;
	}
//Size represents radius of circle
private:

	float size;

};