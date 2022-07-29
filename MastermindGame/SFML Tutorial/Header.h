
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
#include<SFML\Graphics.hpp>
#include<iostream>
#include<string>
#include<cstdlib>
#include<Windows.h>
#include<SFML\System.hpp>
#include<SFML\Window.hpp>



//#include"bigCircle.h"
//#include"smallCircle.h"



using sf::CircleShape;
using sf::Color;


using std::string;
using std::cout;
using std::cin;
using sf::Color;
using sf::Text;
using std::endl;
using sf::Font;
using sf::RenderWindow;
using sf::VideoMode;


/*This struct holds the colors we use to fill in holes of the board as well as the names of the colors as a string
we use this to compare the user's color guesses with the computers' random guess*/
typedef struct paint
{
	string str;
	Color co;
}Paint;


//
//typedef struct resul
//{
//	string str[4];
//	Color co[2];
//}Result;
