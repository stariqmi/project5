CXX = g++
CXXFLAGS = -Wall -MMD
OBJECTS =  main.o textdisplay.o coordinates.o grid.o room.o tile.o thing.o nonlivingthing.o livingthing.o character.o wall.o ground.o door.o passage.o orc.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}