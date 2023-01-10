NAME = containers
VECTOR = tests/test_vector

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
MMD = -MMD

RM = rm -rf

SRC = main.cpp

OBJ = ${SRC:.cpp=.o}

TEST_VECTOR = tests/test_vector
TESTS_VECTOR_OBJ = \
	tests/test_vector.o \
	tests/vector_constructor.o \
	tests/vector_access.o \
	tests/vector_iterators.o \
	tests/utils.o \
	tests/vector_capacity.o \
	tests/vector_modifiers.o \
	tests/vector_non_member.o \

.PHONY = all clean fclean re

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJ}

%.o: %.cpp
	${CXX} ${CXXFLAGS} ${MMD} -I. -c -o $@ $<

clean:
	${RM} ${OBJ}
	${RM} ${SRC:.cpp=.d}
	${RM} ${TESTS_VECTOR_OBJ:.o=.d}
	${RM} ${TESTS_VECTOR_OBJ}

fclean: clean
	${RM} ${NAME}
	${RM} ${VECTOR}

re: fclean all

${VECTOR}: ${TESTS_VECTOR_OBJ}
	${CXX} ${CXXFLAGS} -I. -o $@ ${TESTS_VECTOR_OBJ}

-include ${SRC:.cpp=.d} ${TESTS_VECTOR_OBJ:.o=.d}