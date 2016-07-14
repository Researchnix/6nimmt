#include <iostream>
#include <map>
#include "Field.h"
#include "Player.h"

using namespace std;


//----------------------- CONSTRUCTOR -----------------------  

 
Field::Field()
{
	//initialize the 2D vector of cards
	for (int i = 0; i < 5; i++) {
		vector<int> col;
		_cards.push_back(col);
	}
}


//----------------------- PRIVATE FUNCTIONS -----------------------  
 

void Field::makePlayerPay(Player* p, int c, int pickedNumber)
{
	cout << "The player who tried to play the card " << c << " has to take a row" << endl << "he had ";
	p->printBulls();
  	cout << " bulls" << endl;
	if (pickedNumber == 8) // 8 is an impossible dummy value indicating that 
	// the player has to take a row not due to the card fitting to an 
	// overfilled row, but due to the card not fitting to any row at all
	{
		pickedNumber = p->pickRow(_cards);
		cout << "picked number is " << pickedNumber << endl;
	}
	//delete the row the player picked, make him add the
	//bulls and add a new row
	vector<int> pickedRow = _cards.at(pickedNumber);
	_cards.erase(_cards.begin() + pickedNumber);
	p->addBulls(pickedRow.size()); // assuming every card has one bull value
	vector<int> newColumn;
	newColumn.push_back(c);
	_cards.push_back(newColumn);
	// never forget to sort the field whenever it has been changed
	sortField();
	// print the changes
	cout << "Now he has ";
	p->printBulls();
	cout << " bulls" << endl << "The new field is" << endl << endl;
	printCards();

}
	

class Compare {
	public:
		bool operator() (vector<int> &a, vector<int> &b){
			return (a.back() > b.back());
		}
}compare;

void Field::sortField()
{
	sort(_cards.begin(), _cards.end(), compare);
}


 //----------------------- PUBLIC FUNCTIONS -----------------------  


void Field::initialize(vector<int> newCards)
{
	for (int i = 0; i < 5; i++) {
		_cards.at(i).push_back(newCards.at(i));	
	}
	sortField();
	cout << "Field initialized!" << endl;
}


void Field::addCard(int row, int card)
{
	_cards.at(row).push_back(card);
}


void Field::printCards() {
	for (vector< vector<int> >::const_iterator i =_cards.begin(); i !=_cards.end(); ++i) {
		vector<int> row = *i;
		for (vector<int>::const_iterator j =row.begin(); j !=row.end(); ++j) {
			cout << *j << " ";
		}
		cout << endl;
	}
		cout << endl << endl;
}



vector< vector<int> > Field::getField()
{
	return _cards;
}



void Field::addCards(map<int, Player*> round)
{
	//Extract the keys
	vector<int> newCards;
	for (map<int,Player*>::const_iterator it = round.begin(); it != round.end(); ++it) 
	{
		newCards.push_back(it->first);
	}

	cout << "addCards has been called\n\nThe current field is\n\n";
	sortField();
	//cout << "all good" << endl;
	
	// sort the newCards to add them in the right
	// order to the field
	sort(newCards.begin(), newCards.end());

	// add them from smallest to biggest
	for (int i = 0; i < newCards.size(); i++) {
		bool addedOrTakenCareOf = false;
		printCards();
		int current = newCards.at(i);
		cout << endl << "trying to fit " << current;
		// try to fit starting from row with biggest
		// number at the end
		for (int j = 0; j < 5; ++j) {
			vector<int> row = _cards.at(j);
			cout << endl << "to " << row.back() << endl;
			if (row.back() < current) {
				cout << "fit!" << endl << endl;

				// Don't forget to check if the row that fits
				// might actually have already 5 cards ...
				// proceed accordingly

				if (_cards.at(j).size() < 5)
				{
					addCard(j,current);
					// never forget to sort the field whenever it has been changed
					sortField();
				} else {
					cout << "6nimmt !!" << endl << "------------------------------------------------------------------------------------------------------------------" << endl;
					makePlayerPay(round[current], current, j); // here the player has to take a specific row!!!
				}
				addedOrTakenCareOf = true;
				break;
			} else {
				cout << "too big, keep looking" << endl;
			}
		}
		// if the card could be added to the field do this
		if (addedOrTakenCareOf) {
			cout << "the number has been added, the new field is\n\n";
			printCards();
		// if not, make the player choose a row and handle adding bulls
		// and replacing the row
		} else {
			cout << "This number " << current << " is too small for any row, take a row!!\n\n";
			makePlayerPay( round[current], current); // here the player can choose the row he wants to take
		}
	}
}
