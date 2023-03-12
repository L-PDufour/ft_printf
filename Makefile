NAME = libftprintf.a

RM = rm -f

CFLAGS =  -Wall -Wextra -Werror 

.PHONY: all clean fclean re bonus

SRC = ft_printf.c\
	utils.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) 


re: fclean all


