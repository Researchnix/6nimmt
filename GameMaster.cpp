#include <iostream>
#include <vector>
#include <map>


#include "GameMaster.h"
#include "RandomPlayer.h"
#include "Player.h"
#include "Field.h"
#include "Deck.h"
#include "Logwriter.h"


using namespace std;


//----------------------- CONSTRUCTOR -----------------------  


GameMaster::GameMaster()
{
	cout << "Let's start a new game" << endl;
}


//----------------------- PRIVATE FUNCTIONS -----------------------  




//----------------------- PUBLIC FUNCTIONS -----------------------  


void GameMaster::initializeGame()
{
	// set the round count to zero
	_roundCount = 0;
	// fill deck of cards with cards
	_deck.fill(115);
	// shuffle the deck
	_deck.shuffle();
	
	Player p1("Lennart");
	RandomPlayer p2("Oonagh");
	_players.push_back(p1);
	_players.push_back(p2);

	// distribute 10 cards from the deck to each player in _players
	for (int p = 0; p < _players.size(); p++) {
		_players.at(p).addToHand(_deck.draw(10));
	}
	
	// initialize the field with 5 random cards from the deck
	_field.initialize(_deck.draw(5));
}






void GameMaster::playRound()
{
	cout << "=================================================== BEGINNING OF ROUND " << _roundCount << " ===================================================" << endl << endl;
	cout << "Initial setup, ie number of Bulls of each player: " << endl;
	for (int p = 0; p < _players.size(); p++) {
		_players.at(p).printBulls();
	}

	map<int, Player*> round;
	for (int p = 0; p < _players.size(); p++) {
		round[_players.at(p).playCard(_field.getField())] = &_players.at(p);
	}
	_field.addCards(round);

	cout << "Final setup, ie number of Bulls of each player: " << endl;
	for (int p = 0; p < _players.size(); p++) {
		_players.at(p).printBulls();
	}
	cout << "=================================================== END OF ROUND " << _roundCount << " ===================================================" << endl << endl;
}


void GameMaster::playGame()
{
	for (int i = 0; i < 10; i++) {
		playRound();
	}
}
