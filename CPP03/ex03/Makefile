NAME = trap
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
RM = rm -f
INCLUDES = -I./

SRCS =	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp	ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
