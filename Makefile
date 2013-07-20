CXX = g++
CXXFLAGS = -Wall -MMD
OBJECTS = main.o grid.o textdisplay.o tile.o thing.o wall.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}