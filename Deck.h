#ifndef DECK_H
#define DECK_H

#include <vector>

using namespace std; 


class Deck{

	private:
		vector<int> _content;
	protected:
	public:
		void fill(int max);
		void shuffle();
		vector<int> draw(int n); 
};

#endif // DECK_H
