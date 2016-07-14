#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include <vector>
#include <map>

#include "Player.h"
#include "RandomPlayer.h"
#include "Field.h"
#include "Deck.h"
#include "LogWriter.h"

using namespace std;

class GameMaster{

	private:
		vector<Player> _players; 	//
		Field _field; 			//object that handles cards on the table
		int _roundCount; 		//counting the rounds played
		Deck _deck; 			//the deck of cards
		LogWriter _logo;
	public:
		GameMaster();
		void initializeGame();
		void playRound();
		void playGame();
	protected:
};

#endif // GAMEMASTER_H
