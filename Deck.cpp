#include <iostream>
#include <vector>
#include <random>

#include "Deck.h"




using namespace std;


//----------------------- PUBLIC FUNCTIONS -----------------------  

void Deck::fill(int max)
{
	for (int i = 1; i <= max; i++)
	{
		_content.push_back(i);
	}
}


void Deck::shuffle()
{
	int p;
	int size = _content.size();
	random_device rd; // obtain a random
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution <> distr(0, size - 1); // define the range
	for (int i = 0; i < 10*size; i++)
	{
		p = distr(eng);
		_content.push_back(_content.at(p));
		_content.erase(_content.begin() + p);
	}
}


vector<int> Deck::draw(int n)
{
	vector<int> result;
	for(int i = 1; i <= n; i++)
	{
		result.push_back(_content.front());
		_content.erase(_content.begin());
	}	
	return result;
}
