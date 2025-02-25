NAME	= a.out
FLAGS	= -Werror -Wall -Wextra -std=c++98
HEADERS	= Bureaucrat.hpp AForm.hpp ShruberryCreationForm.hpp \
		  RobotomyRequestForm.hpp PresidentialPardonForm.hpp

SRCS	= main.cpp Bureaucrat.cpp ShruberryCreationForm.cpp \
		  RobotomyRequestForm.cpp AForm.cpp PresidentialPardonForm.cpp

OBJS	= $(SRCS:.cpp=.o)

all	: $(NAME)

%.o	: %.cpp $(HEADERS)
	$(CXX) -c $< -o $@ $(FLAGS)

$(NAME)	: $(OBJS)
	$(CXX) $^ -o $@ $(FLAGS)

clean	:
	@rm -rf $(OBJS)

fclean	: clean
	@rm -rf $(NAME)

re	: fclean all

.PHONY	: clean