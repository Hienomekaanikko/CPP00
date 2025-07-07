CC = c++
FLAGS = -Wall -Werror -Wextra
SRC = Account.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Account
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ) $(NAME)

re: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re
