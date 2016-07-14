CC=g++

output: main.o GameMaster.o Player.o Field.o Deck.o RandomPlayer.o LogWriter.o
	$(CC) main.o GameMaster.o Player.o Field.o Deck.o RandomPlayer.o LogWriter.o -o output
	./output

main.o: main.cpp
	$(CC) -c main.cpp

GameMaster.o: GameMaster.cpp GameMaster.h
	$(CC) -c GameMaster.cpp

Player.o: Player.cpp Player.h
	$(CC) -c Player.cpp

Field.o: Field.cpp Field.h
	$(CC) -c Field.cpp

Deck.o: Deck.cpp Deck.h
	$(CC) -c Deck.cpp

RandomPlayer.o: RandomPlayer.cpp RandomPlayer.h
	$(CC) -c RandomPlayer.cpp

LogWriter.o: LogWriter.cpp LogWriter.h
	$(CC) -c LogWriter.cpp

clean:
	rm -rf *.o
