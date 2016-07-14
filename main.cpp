#include <iostream>
#include <algorithm>
#include <vector>

#include "GameMaster.h"
#include "Player.h"
#include "Field.h"
#include "Deck.h"

#include <fstream>


using namespace std;


int main(int argc, const char *argv[])
{
	GameMaster m;
	m.initializeGame();
	m.playGame();

	ofstream myfile;
  	myfile.open ("example.txt");
    	myfile << "Writing this to a file.\n";
      	myfile.close();

	return 0;
}
