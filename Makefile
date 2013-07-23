CXX = g++
CXXFLAGS = -Wall -MMD
OBJECTS =  main.o textdisplay.o coordinates.o grid.o room.o tile.o thing.o nonlivingthing.o wall.o stairway.o ground.o door.o passage.o livingthing.o character.o elf.o dwarf.o human.o orc.o werewolf.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}