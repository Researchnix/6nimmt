#ifndef PLAYER_H
#define PLAYER_H
#include <vector>

using namespace std;

class Player
{
	private:
	protected:
		string _name;
		int _bulls;
		vector<int> _hand;
	public:
		Player(string name);
		Player();
		void addToHand(vector<int>);
		void addBulls(int b);
		int playCard(vector< vector<int> >);
		int pickRow(vector< vector<int> >);
		void printBulls();
		string getName();
};
#endif // PLAYER_H
