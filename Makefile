NAME = containers
SEED = 42

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
MMD = -MMD

RM = rm -rf

SRC = ft_main.cpp std_main.cpp

OBJ = ${SRC:.cpp=.o}

.PHONY = all clean fclean re

all: ${NAME}

${NAME}: std_container ft_container
	touch ${NAME}

std_container: std_main.o
	${CXX} ${CXXFLAGS} -o std_container std_main.o

ft_container: ft_main.o
	${CXX} ${CXXFLAGS} -o ft_container ft_main.o

ft_main.o: main.cpp
	${CXX} ${CXXFLAGS} ${MMD} -c -DFT -o $@ main.cpp

std_main.o: main.cpp
	${CXX} ${CXXFLAGS} ${MMD} -c -DSTD -o $@ main.cpp

test: ${NAME}
	./ft_container ${SEED} > out_ft.out
	./std_container ${SEED} > out_std.out

clean:
	${RM} ${OBJ}
	${RM} ${SRC:.cpp=.d}

fclean: clean
	${RM} ${NAME}

re: fclean all

-include ${SRC:.cpp=.d}