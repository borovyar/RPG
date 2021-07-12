CC = g++
OBJ = src/items/items.o src/items/potionD.o src/items/potionH.o src/items/potionL.o src/items/sword.o src/traps/trap.o src/traps/bomb.o src/traps/snare.o src/traps/throm.o src/inventory.o src/chest.o src/enemies/enemies.o src/enemies/boar.o src/enemies/boss.o src/enemies/pank.o src/enemies/dragon.o src/enemies/soldier.o src/combat.o src/player.o src/game.o src/main.o

dep:
	g++ -MM src/*.cpp > dependencies.mk

include dependencies.mk

src/%.o : src/%.cpp src/%.hpp
	$(CC) -c -o  $@ $<

compile: $(OBJ)
	$(CC) -o borovyar $^
	
run: 
	./borovyar

doc:

clean:
	rm -f $(OBJ)
	rm -rf borovyar