CXX = clang++
EXEC = edit_distance
OBJECTS = EditDistance.o

${EXEC} : ${OBJECTS} driver.cpp
	${CXX} ${OBJECTS} driver.cpp -o ${EXEC}

EditDistance.o : EditDistance.cpp EditDistance.hpp
	${CXX} -c EditDistance.cpp

clean:
	rm -fr ${OBJECTS}
	rm -fr ${EXEC}
