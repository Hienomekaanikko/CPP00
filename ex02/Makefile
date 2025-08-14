CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = tests.cpp Account.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f
NAME = account

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
