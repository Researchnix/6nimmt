#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <map>
#include "Player.h"

using namespace std;

class Field // Cards on the Table
{
	private:
		vector< vector<int> > _cards;
		vector<int> _frontValues;
		void makePlayerPay(Player* p, int c, int pickedNumber = 8);
		void sortField();
	public:
		Field();
		void initialize(vector<int>);
		void addCard(int,int);
		void printCards();
		vector< vector<int> > getField();
		void addCards(map<int, Player*> round);
	protected:
};
#endif // FIELD_H
