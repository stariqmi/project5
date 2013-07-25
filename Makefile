CXX = g++
CXXFLAGS = -Wall -MMD

OBJECTS =  main.o textdisplay.o coordinates.o charFactory.o itemFactory.o combatMediator.o grid.o room.o tile.o thing.o nonlivingthing.o wall.o stairway.o ground.o door.o passage.o livingthing.o character.o elf.o dwarf.o human.o orc.o werewolf.o vampire.o phoenix.o troll.o merchant.o goblin.o dragon.o item.o potion.o boosthealth.o poisonhealth.o boostattack.o boostdefence.o woundattack.o wounddefence.o treasure.o dragonhorde.o smallhorde.o normalgold.o merchanthorde.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}
	rm -rf *.o *.d