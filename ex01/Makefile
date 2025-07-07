CC = c++
FLAGS = -Wall -Werror -Wextra
SRC = PhoneBook.cpp Contacts.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f
NAME = PhoneBook

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
