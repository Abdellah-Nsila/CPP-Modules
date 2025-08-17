NAME = a.out
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -f
INCLUDES = -I./

SRCS =	main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp	
	$(CPP) $(CPPFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
