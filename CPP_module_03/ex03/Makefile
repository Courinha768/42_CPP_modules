NAME			= DiamondTrap

SRCS			= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -I. -std=c++98 -Wshadow

REMOVE			= rm

.SILENT:		$(OBJS)

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
				@echo "\e[1mFinished compiling $(NAME)\033[0m"

./%.o:			./%.cpp
				@echo "\e[1mCompiling [$@]...\033[0m"
				@$(CXX) $(CXXFLAGS) -o $@ -c $<
				@printf "\033[A\033[K"
				@echo "\e[1mFinished [$(NAME)]\033[0m"
				@printf "\033[A\033[K"

clean:
				@rm -rf $(OBJS)
				@echo "\e[1mObject files deleted\033[0m"

fclean:			clean
				@rm -rf $(NAME)
				@echo "\e[1mExecutable files deleted\033[0m"

re:				fclean $(NAME)

c:				$(NAME) clean

r:				$(NAME) clean
				@./$(NAME)

.PHONY:			all clean fclean re c