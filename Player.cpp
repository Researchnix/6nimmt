#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

//----------------------- CONSTRUCTOR -----------------------  


Player::Player(string name)
{
	_name = name;
	_bulls = 0;
}

Player::Player()
{
	_bulls = 0;
}


//----------------------- PRIVATE FUNCTIONS -----------------------  


//----------------------- PUBLIC FUNCTIONS -----------------------  


void Player::addToHand(vector<int> n)
{
	for (vector<int>::const_iterator i = n.begin(); i != n.end(); ++i)
	{
		_hand.push_back(*i);
	}
}


void Player::addBulls(int b)
{
	_bulls += b;
}


int Player::playCard(vector< vector<int> > cards)
{
	int r = _hand.front();
	_hand.erase(_hand.begin());
	return r;
}


int Player::pickRow(vector< vector<int> > cards)
{
	//this is just a dummy answer
	return 0;
}


void Player::printBulls()
{
	cout << _bulls << endl;
}


string Player::getName()
{
	return _name;
}
