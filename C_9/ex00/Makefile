NAME= btc

CXX=c++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98 -g -fsanitize=address

SRC= main.cpp BitcoinExchange.cpp
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re