NAME = containers

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
MMD = -MMD

RM = rm -rf

SRC = main.cpp

OBJ = ${SRC:.cpp=.o}

TESTS_VECTOR = \
	test_vector.o \
	vector_constructor.o \

.PHONY = all clean fclean re

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJ}

%.o: %.cpp
	${CXX} ${CXXFLAGS} -I. -c $<

clean:
	${RM} ${OBJ}
	${RM} ${SRC:.cpp=.d}
	${RM} tests/test_vector.o

fclean: clean
	${RM} ${NAME}

re: fclean all

#relinks
test_vector: ${addprefix tests/, ${TESTS_VECTOR}}
	${CXX} ${CXXFLAGS} -I. -o tests/$@ ${TESTS_VECTOR}

-include ${SRC:.cpp=.d}