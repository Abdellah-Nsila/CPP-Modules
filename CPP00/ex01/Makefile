NAME = phonebook
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -f
INC_DIR = ./includes
SRC_DIR = ./srcs
INCLUDES = -I$(INC_DIR)

SRCS =	$(SRC_DIR)/main.cpp $(SRC_DIR)/utils.cpp $(SRC_DIR)/Contact.cpp $(SRC_DIR)/PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp	$(INC_DIR)/includes.hpp $(INC_DIR)/main.hpp $(INC_DIR)/utils.hpp $(INC_DIR)/Contact.hpp \
			$(INC_DIR)/PhoneBook.hpp  
	$(CPP) $(CPPFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
