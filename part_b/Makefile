COMP_FLAG=-std=c++11 -Wall -Werror -pedantic-errors -DNDEBUG

game_test.out: game_test.cpp Game.o TileItem.o Character.o Soldier.o Auxiliaries.o Game.h
	g++ -o $@ game_test.cpp Game.o TileItem.o Character.o Soldier.o Auxiliaries.o

Game.o: Game.cpp Game.h TileItem.h Board.h Exceptions.h Soldier.h Character.h
	g++ -c -o $@ $(COMP_FLAG) Game.cpp

Soldier.o: Character.h Soldier.h Soldier.cpp
	g++ -c -o $@ $(COMP_FLAG) $*.cpp
Medic.o: Character.h Medic.h Medic.cpp
	g++ -c -o $@ $(COMP_FLAG) $*.cpp
Sniper.o: Character.h Sniper.h Sniper.cpp
	g++ -c -o $@ $(COMP_FLAG) $*.cpp

TileItem.o: TileItem.h TileItem.cpp
	g++ -c -o $@ $(COMP_FLAG) TileItem.cpp
Character.o: Character.h Character.cpp TileItem.h
	g++ -c -o $@ $(COMP_FLAG) Character.cpp
Auxiliaries.o: Auxiliaries.h Auxiliaries.cpp
	g++ -c -o $@ $(COMP_FLAG) Auxiliaries.cpp


clean:
	rm -rf *.o *.out
