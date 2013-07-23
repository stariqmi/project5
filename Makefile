CXX = g++
CXXFLAGS = -Wall -MMD
<<<<<<< HEAD
OBJECTS =  main.o textdisplay.o coordinates.o grid.o room.o tile.o thing.o nonlivingthing.o wall.o stairway.o ground.o door.o passage.o livingthing.o character.o elf.o dwarf.o human.o orc.o werewolf.o mediator.o
=======
OBJECTS =  main.o textdisplay.o coordinates.o grid.o room.o tile.o thing.o nonlivingthing.o wall.o stairway.o ground.o door.o passage.o livingthing.o character.o elf.o dwarf.o human.o orc.o werewolf.o item.o potion.o boosthealth.o poisonhealth.o boostattack.o boostdefence.o woundattack.o wounddefence.o
>>>>>>> 5acef6b9e9fa2c3a8d036a81c9cc608332914da1
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}