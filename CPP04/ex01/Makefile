NAME = animal
CPP = c++
CPPFLAGS = #-Wall -Wextra -Werror -std=c++98
RM = rm -f
INC_DIR = ./includes
SRC_DIR = ./src
INCLUDES = -I$(INC_DIR)

SRCS =	$(SRC_DIR)/main.cpp $(SRC_DIR)/Animal.cpp $(SRC_DIR)/Dog.cpp $(SRC_DIR)/Cat.cpp \
		$(SRC_DIR)/WrongAnimal.cpp $(SRC_DIR)/WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp	$(INC_DIR)/Animal.hpp $(INC_DIR)/Dog.hpp $(INC_DIR)/Cat.hpp \
			$(INC_DIR)/WrongAnimal.hpp $(INC_DIR)/WrongCat.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
