NAME = containers

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
MMD = -MMD

RM = rm -rf

SRC = main.cpp

OBJ = ${SRC:.cpp=.o}

.PHONY = all clean fclean re

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJ}

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $<

clean:
	${RM} ${OBJ}
	${RM} ${SRC:.cpp=.d}
	${RM} tests/test_vector.o

fclean: clean
	${RM} ${NAME}

re: fclean all

#relinks
test_vector:
	${CXX} ${CXXFLAGS} -I. -o tests/test_vector.o -c tests/test_vector.cpp
	${CXX} ${CXXFLAGS} -I. -o tests/$@ tests/test_vector.o

-include ${SRC:.cpp=.d}