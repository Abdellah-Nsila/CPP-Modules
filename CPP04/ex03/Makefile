NAME = animal
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
INC_DIR = ./includes
SRC_DIR = ./src
INCLUDES = -I$(INC_DIR)

SRCS =	$(SRC_DIR)/main.cpp $(SRC_DIR)/AMateria.hpp $(SRC_DIR)/ICharacter.hpp $(SRC_DIR)/Ice.hpp \
		$(SRC_DIR)/Cure.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp	$(INC_DIR)/AMateria.hpp $(INC_DIR)/ICharacter.hpp $(INC_DIR)/Ice.hpp \
			$(INC_DIR)/Cure.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
