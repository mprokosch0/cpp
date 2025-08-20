NAME = Materias

CXX = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS = srcs/main.cpp srcs/AMateria.cpp srcs/MateriaSource.cpp \
	   srcs/IceMateria.cpp srcs/CureMateria.cpp srcs/Character.cpp

OBJS_DIR = objs

OBJS =	$(SRCS:%.cpp=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o:%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
